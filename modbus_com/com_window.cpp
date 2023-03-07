#include "com_window.h"
#include "ui_com_window.h"


COM_Window::COM_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::COM_Window)
{
    ui->setupUi(this);
    this->setWindowTitle("串口助手");
    this->setWindowIcon(QIcon(":/Img/logo.png"));
    serial = new QSerialPort(this);
    this->SearchCOM();
}

COM_Window::~COM_Window()
{
    delete ui;
}

void COM_Window::SearchCOM(){
    ui->COMcomboBox->clear();
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()){
        ui->COMcomboBox->addItem(info.portName());
    }
    qDebug()<<"串口搜索成功！";
}

void COM_Window::setcombox(bool judge){
    ui->COMcomboBox->setEnabled(judge);
    ui->BitcomboBox->setEnabled(judge);
    ui->DatacomboBox->setEnabled(judge);
    ui->StopcomboBox->setEnabled(judge);
    ui->CRCcomboBox->setEnabled(judge);
}

void COM_Window::serialPortReadyRead(){
    QByteArray buf;
    buf = serial->readAll();
    QTextCodec::ConverterState state;
    QTextCodec *codeutf8 = QTextCodec::codecForName("UTF-8");
    QString bufstr = codeutf8->toUnicode(buf.constData(),buf.size(),&state);
    bufstr =  codeutf8->toUnicode(buf);
    if(bufstr!=""&&!ui->StopShowcheckBox->isChecked()){
        if(ui->LogShowcheckBox->isChecked()){
            QString timestr = getTime();
            bufstr = timestr + bufstr + "\r\n";
        }
        if (state.invalidChars)
        {
            bufstr = QTextCodec::codecForName( "GBK" )->toUnicode(buf);
        }
        else
        {
            bufstr =  codeutf8->toUnicode(buf);
        }
        if(ui->HEXradioButton->isChecked()){
            bufstr = StringToHex(bufstr)+"\r\n";
            if(bufstr == ""){
                bufstr = "字符串转16进制失败\r\n";
            }
        }
        if(ui->LogShowcheckBox->isChecked()){
            bufstr = getTime()+bufstr+"\r\n";
        }
        ui->ReceiveText->insertPlainText(bufstr);
    }
}

QString COM_Window::getTime(){
    QString timestr;
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    timestr = dateTime .toString("yyyy-MM-dd/hh:mm:ss");//格式化时间
    return timestr;
}

QString COM_Window::StringToHex(QString str)
{
    QByteArray array = str.toUtf8();
    QString string1=array.toHex();
    QString string2;
    for(int i=0;i<string1.size();i++)
    {
        for(int j=0;j<2;j++)
        {
            if(i<string1.size())
                string2.append(string1.at(i+j));
        }
        if(i++<string1.size()-2)
            string2.append(" ");
    }
    return string2;
}

void COM_Window::on_RenewCOMBtn_clicked()
{
    this->SearchCOM();
}

void COM_Window::on_OpenCOMBtn_clicked()
{
    if(ui->COMcomboBox->currentIndex() == -1)
    {
        QMessageBox::information(this,"提示","当前没有可用串口，请刷新后再次尝试");
        return;
    }
    else{
        if(ui->OpenCOMBtn->text() == "打开串口"){
            serial->clear();
            qDebug()<<"测试数据";
            serial->close();
            serial->setPortName(ui->COMcomboBox->currentText());    // 设置串口号
            serial->setBaudRate(ui->BitcomboBox->currentText().toInt(),QSerialPort::AllDirections); // 设置波特率
            serial->setDataBits((QSerialPort::DataBits)ui->DatacomboBox->currentText().toInt());    // 设置数据位
            serial->setStopBits((QSerialPort::StopBits)ui->StopcomboBox->currentText().toUInt());   // 设置停止位
            switch(ui->CRCcomboBox->currentIndex()){    // 设置校验位
            case 0:{
                serial->setParity(QSerialPort::NoParity);
                break;
            }
            case 1:{
                serial->setParity(QSerialPort::OddParity);
                break;
            }
            case 2:{
                serial->setParity(QSerialPort::EvenParity);
                break;
            }
            }
            if(serial->open(QIODevice::ReadWrite)){
                qDebug()<<"打开串口成功！";
                ui->OpenCOMBtn->setText("关闭串口");
                connect(serial,SIGNAL(readyRead()),this,SLOT(serialPortReadyRead()));   //将串口读信号与槽函数进行关联
                //readyRead()信号，即串口发送过来数据时，程序就会收到一个可以读数据的信号

                setcombox(false);
            }
            else{
                QMessageBox::information(this,"提示","串口打开失败！");
                return;
            }
        }
        else {
            serial->close();
            disconnect(serial,SIGNAL(readyRead()),this,SLOT(serialPortReadyRead()));   //将串口读信号与槽函数解除关联
            ui->OpenCOMBtn->setText("打开串口");
            setcombox(true);
        }
    }
}

void COM_Window::on_ClearBtn_clicked()
{
    ui->ReceiveText->clear();
}

void COM_Window::on_BackBtn_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();
}
