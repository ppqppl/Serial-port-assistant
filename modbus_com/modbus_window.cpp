#include "modbus_window.h"
#include "ui_modbus_window.h"

QString tempstr,humistr,timestr;
double temp,humi;

Modbus_Window::Modbus_Window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Modbus_Window)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    this->setWindowTitle("modbus助手");
    this->setWindowIcon(QIcon(":/Img/logo.png"));

    modbusDevice = new QModbusRtuSerialMaster(this);
    pollTimer = new QTimer;

    InitialSetting();

    InitChart();

    QLoggingCategory::setFilterRules(QStringLiteral("qt.modbus* = true"));
}

Modbus_Window::~Modbus_Window()
{
    delete ui;
}

//获取系统时间
void Modbus_Window::getTime(){
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    timestr = dateTime .toString("yyyy-MM-dd/hh:mm:ss");//格式化时间
}

//插入到数据库
void Modbus_Window::insert2sql(){
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");    //括号内要写出数据库的类型
    //设置数据库IP
    db.setHostName("127.0.0.1"); //设置数据库的主机ip
    //设置数据库端口
    db.setPort(3307);
    //设置数据库的用户名
    db.setUserName("root");
    //设置数据库的密码
    db.setPassword("123456");    //这个就是安装MySQL时设置的密码
    //设置数据库的名字
    db.setDatabaseName("stm32");
    db.open();
    QSqlQuery query;
    query.prepare("insert into aht20 (temp,humi,time) values (:temp,:humi,:time)");  //:id之类的名字时自定义的 自己方便就好
    //添加绑定数据
    QVariantList idList;    //创建一个id列表
    idList << temp;
    query.bindValue(":temp",idList); //完成:id的绑定
    QVariantList nameList;
    nameList << humi;
    query.bindValue(":humi",nameList);   //完成:name的绑定
    QVariantList ageList;
    ageList << timestr;
    query.bindValue(":time",ageList);    //完成:age的绑定
    //执行批处理
    int k = query.execBatch();
    if(k == 0){
        qDebug()<<"失败";
    }
    else{
        qDebug()<<"数据库存储成功！";
    }
    db.close();
}

//初始化配置
void Modbus_Window::InitialSetting()
{
    //填充串口号组合框
    SearchSerialPorts();

    //填充报文格式
    ui->comboBoxFormat->addItem("Modbus-RTU");
    ui->comboBoxFormat->addItem("Modbus-ASCII");

    //设置界面操作的初始状态
    ui->spinBoxInterval->setValue(1000);
    ui->checkBoxAuto->setChecked(true);
}

//搜索串口
void Modbus_Window::SearchSerialPorts()
{
    ui->comboBoxPort->clear();

    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        ui->comboBoxPort->addItem(info.portName());
    }
}

//写数据请求
void Modbus_Window::WriteRequest(QList<quint16> values)
{
    if (!modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type;

    switch(ui->comboBoxDataType->currentIndex())
    {
    case 0:type=QModbusDataUnit::Coils;break;
    case 1:type=QModbusDataUnit::DiscreteInputs;break;
    case 2:type=QModbusDataUnit::InputRegisters;break;
    case 3:type=QModbusDataUnit::HoldingRegisters;break;
    default:type=QModbusDataUnit::Invalid;
    }

    int startAddress = ui->spinBoxStartWrite->value();
    Q_ASSERT(startAddress >= 0 && startAddress < 10);

    QModbusDataUnit writeUnit = QModbusDataUnit(type,startAddress, values.size());
    for(int i=0; i<values.size(); i++)
    {
        writeUnit.setValue(i, values.at(i));
    }

    //serverEdit 发生给slave的ID
    if (auto *reply = modbusDevice->sendWriteRequest(writeUnit,ui->spinBoxStation->value()))
    {
        if (!reply->isFinished())
        {
            connect(reply, &QModbusReply::finished, this, [this, reply]() {
                if (reply->error() == QModbusDevice::ProtocolError) {
                    qDebug() << QString("Write response error: %1 (Mobus exception: 0x%2)")
                                .arg(reply->errorString()).arg(reply->rawResult().exceptionCode(), -1, 16);
                } else if (reply->error() != QModbusDevice::NoError) {
                    qDebug() << QString("Write response error: %1 (code: 0x%2)").
                                arg(reply->errorString()).arg(reply->error(), -1, 16);
                }
                reply->deleteLater();
            });
        }
        else
        {
            reply->deleteLater();
        }
    }
    else
    {
        qDebug() << QString(("Write error: ") + modbusDevice->errorString());
    }
}

//读数据请求
void Modbus_Window::ReadRequest()
{
    if (!modbusDevice)
    {
        QMessageBox::information(NULL,  "Title",  "尚未连接从站设备");
        return;
    }

    QModbusDataUnit::RegisterType type;

    switch(ui->comboBoxDataType->currentIndex())
    {
    case 0:type=QModbusDataUnit::Coils;break;
    case 1:type=QModbusDataUnit::DiscreteInputs;break;
    case 2:type=QModbusDataUnit::InputRegisters;break;
    case 3:type=QModbusDataUnit::HoldingRegisters;break;
    default:type=QModbusDataUnit::Invalid;
    }

    int startAddress = ui->spinBoxStartRead->value();
    Q_ASSERT(startAddress >= 0 && startAddress < 10);

    // do not go beyond 10 entries
    quint16 numberOfEntries = qMin(quint16(ui->spinBoxNumberRead->value()), quint16(10 - startAddress));
    QModbusDataUnit readUnit=QModbusDataUnit(type, startAddress, numberOfEntries);

    statusBar()->clearMessage();

    if (auto *reply = modbusDevice->sendReadRequest(readUnit, ui->spinBoxStation->value()))
    {
        if (!reply->isFinished())
            connect(reply, &QModbusReply::finished, this, &Modbus_Window::ReadSerialData);
        else
            delete reply; // broadcast replies return immediately
    }
    else
    {
        statusBar()->showMessage(tr("Read error: ") + modbusDevice->errorString(), 5000);
    }

}

//从串口接收数据
void Modbus_Window::ReadSerialData()
{
    auto reply = qobject_cast<QModbusReply *>(sender());
    if (!reply)
        return;

    if (reply->error() == QModbusDevice::NoError)
    {
        const QModbusDataUnit unit = reply->result();

        for (int i = 0, total = int(unit.valueCount()); i < total; ++i)
        {
            QString entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                .arg(QString::number(unit.value(i)));
            if(ui->HEXCheckBox->isChecked()){
                entry = tr("Address: %1, Value: %2").arg(unit.startAddress() + i)
                    .arg(QString::number(unit.value(i),
                                         unit.registerType() <= QModbusDataUnit::Coils ? 10 : 16));
            }
            ui->textBrowser->append(entry);
            switch(i){
            case 0:{
                tempstr = QString::number(unit.value(i));
                getTime();
                break;
            }
            case 1:{
                tempstr = tempstr + "." + QString::number(unit.value(i));
                temp = tempstr.toDouble();
                qDebug()<<"时间： "<<timestr;
                qDebug()<<"温度： "<<temp;
                break;
            }
            case 2:{
                humistr = QString::number(unit.value(i));
                break;
            }
            case 3:{
                humistr = humistr + "." + QString::number(unit.value(i));
                humi = humistr.toDouble();
                qDebug()<<"湿度： "<<humi;
                ui->textBrowser->append("时间： "+timestr);
                ui->textBrowser->append("温度： "+tempstr);
                ui->textBrowser->append("湿度： "+humistr);
                if(ui->MySQLcheckBox->isChecked()){
                    insert2sql();
                }
                break;
            }
            }

//            ui->textBrowser->append();

            if((unit.startAddress() + i)<8)
            {
                values[(unit.startAddress() + i)]=unit.value(i);
            }
        }
    }
    else if (reply->error() == QModbusDevice::ProtocolError)
    {
        statusBar()->showMessage(tr("Read response error: %1 (Mobus exception: 0x%2)").
                                 arg(reply->errorString()).
                                 arg(reply->rawResult().exceptionCode(), -1, 16), 5000);
    }
    else
    {
        statusBar()->showMessage(tr("Read response error: %1 (code: 0x%2)").
                                 arg(reply->errorString()).
                                 arg(reply->error(), -1, 16), 5000);
    }

    reply->deleteLater();
}

//图形显示的初始化
void Modbus_Window::InitChart()
{

    mChart = new QChart;

    for(int i=0;i<8;i++)
    {
        lineSeries[i] = new QLineSeries(this);
        mChart->addSeries(lineSeries[i]);
        values[i]=0;
    }

    mChart->setTitle("实时变化曲线");//设置图标标题
    mChart->legend()->hide();
    axisX = new QValueAxis;
    axisY = new QValueAxis;
    chartTimer = new QTimer;
    connect(chartTimer,&QTimer::timeout, this, &Modbus_Window::ChartDisplay);
    chartTimer->start(1000);
}

//曲线显示
void Modbus_Window::ChartDisplay()
{
    QColor acolor[8]={Qt::red,Qt::blue,Qt::green,Qt::cyan,Qt::yellow,Qt::magenta,Qt::black,Qt::darkRed};
    QStringList name={"抛物线","正弦值","正弦值","固定值","固定值","固定值","固定值","固定值"};
    QVector<QPointF> list[8];
    QVector<QPointF> newlist[8];

    for(int j=0;j<8;j++)
    {
        list[j] = lineSeries[j]->pointsVector();//获取现在图中列表

        if (list[j].size() < 200)
        {
            //保持原来
            newlist[j] = list[j];
        }
        else
        {
            //错位移动
            for(int i =1 ; i< list[j].size();i++)
            {
                newlist[j].append(QPointF(i-1,list[j].at(i).y()));
            }
        }

        newlist[j].append(QPointF(newlist[j].size(),values[j]));//最后补上新的数据

        lineSeries[j]->replace(newlist[j]);//替换更新

        lineSeries[j]->setName(name[j]);//设置曲线名称
        lineSeries[j]->setPen(acolor[j]);//设置曲线颜色
        lineSeries[j]->setUseOpenGL(true);//openGl 加速

        //mChart->setTitle("Pressure Data");//设置图标标题
        mChart->removeSeries(lineSeries[j]);
        mChart->addSeries(lineSeries[j]);
        mChart->createDefaultAxes();//设置坐标轴
    }

    ui->graphicsView->setChart(mChart);
}

//退出程序
void Modbus_Window::on_actionExit_triggered()
{
    this->close();
}

//串口连接
void Modbus_Window::on_actionConnect_triggered()
{
    if (!modbusDevice)
        return;

    modbusDevice->setConnectionParameter(QModbusDevice::SerialPortNameParameter,ui->comboBoxPort->currentText());
    modbusDevice->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,ui->comboBoxBaud->currentText().toInt());

    switch(ui->comboBoxParity->currentIndex())                   //设置奇偶校验
    {
    case 0: modbusDevice->setConnectionParameter(QModbusDevice::SerialParityParameter,QSerialPort::NoParity);break;
    default: break;
    }

    switch(ui->comboBoxData->currentIndex())                   //设置数据位数
    {
    case 1:modbusDevice->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,QSerialPort::Data8);break;
    default: break;
    }

    switch(ui->comboBoxStop->currentIndex())                     //设置停止位
    {
    case 1: modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::OneStop);break;
    case 2: modbusDevice->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,QSerialPort::TwoStop);break;
    default: break;
    }

    modbusDevice->setTimeout(1000);
    modbusDevice->setNumberOfRetries(3);

    if (modbusDevice->connectDevice())
    {
        //开启自动读取
        if(ui->checkBoxAuto->isChecked())
        {
            connect(pollTimer,&QTimer::timeout, this, &Modbus_Window::ReadRequest);
            pollTimer->setInterval(ui->spinBoxInterval->value());
            pollTimer->start();
        }

        //连接槽函数
        //QObject::connect(serialPort, &QSerialPort::readyRead, this, &MainWindow::ReadSerialData);

        // 设置控件可否使用
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionRefresh->setEnabled(false);
    }
    else    //打开失败提示
    {

        QMessageBox::information(this,tr("错误"),tr("连接从站失败！"),QMessageBox::Ok);
    }
}

//断开连接
void Modbus_Window::on_actionDisconnect_triggered()
{
    modbusDevice->disconnectDevice();
    pollTimer->stop();

    // 设置控件可否使用
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionRefresh->setEnabled(true);

}

//刷新串口
void Modbus_Window::on_actionRefresh_triggered()
{
    //填充串口号组合框
    SearchSerialPorts();
}

//参数配置
void Modbus_Window::on_actionConfig_triggered()
{

}

//报文保存
void Modbus_Window::on_actionSave_triggered()
{
    if(ui->textBrowser->toPlainText().isEmpty()){
        QMessageBox::information(this, "提示消息", tr("貌似还没有数据! 您需要在发送编辑框中输入要发送的数据"), QMessageBox::Ok);
        return;
    }

    QString filename = QFileDialog::getSaveFileName(this, tr("保存为"), tr("未命名.txt"),tr("Text files (*.txt)"));
    QFile file(filename);
    //如果用户取消了保存则直接退出函数
    if(file.fileName().isEmpty()){
        return;
    }

    //如果打开失败则给出提示并退出函数
    if(!file.open(QFile::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, tr("保存文件"), tr("打开文件 %1 失败, 无法保存\n%2").arg(filename).arg(file.errorString()), QMessageBox::Ok);
        return;
    }
    //写数据到文件
    QTextStream out(&file);
    out<<ui->textBrowser->toPlainText();
    file.close();
}

//手动读取
void Modbus_Window::on_pushButtonRead_clicked()
{
    ReadRequest();
}

//手动写入
void Modbus_Window::on_pushButtonWrite_clicked()
{
    QList<quint16> values;

    QStringList str1=ui->lineEditWriteValue->text().split(",");
    //qDebug()<<str1.size();
    //qDebug()<<ui->spinBoxNumberWrite->value();

    for(int i=0;i<ui->spinBoxNumberWrite->value();i++)
    {
        values.append(str1[i].toUShort());
    }

    //qDebug()<<values.size();
    WriteRequest(values);
}

//手动发送
void Modbus_Window::on_pushButtonSend_clicked()
{

}

//手自动变换
void Modbus_Window::on_checkBoxAuto_clicked(bool checked)
{
    if(checked)     //自动循环发送
    {
        if (modbusDevice->state() != QModbusDevice::ConnectedState)
        {
            pollTimer->setInterval(ui->spinBoxInterval->text().toInt());
            pollTimer->start();

            ui->statusbar->showMessage(tr("启用循环发送"));
        }
        else
        {
            if (QMessageBox::Ok ==
                    QMessageBox::question(this, tr("提示"),
                                          QString(tr("串口 %1 并没有打开, 是否要打开串口 %2 ?"))
                                          .arg(ui->comboBoxPort->currentText(), ui->comboBoxPort->currentText()),
                                          QMessageBox::Ok, QMessageBox::Cancel))
            {
                on_actionConnect_triggered();
            }
            ui->checkBoxAuto->setChecked(false);
        }
    }
    else            //取消循环发送
    {
        pollTimer->stop();

        ui->statusbar->showMessage(tr("取消循环发送"));
    }
}


void Modbus_Window::on_BackBtn_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();
}
