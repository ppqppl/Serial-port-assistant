#include "linkmysql.h"
#include "ui_linkmysql.h"

//添加一个数据库
QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");    //括号内要写出数据库的类型

LinkMySQL::LinkMySQL(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LinkMySQL)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    this->setWindowTitle("MySQL测试");
    this->setWindowIcon(QIcon(":/Img/logo.png"));
}

LinkMySQL::~LinkMySQL()
{
    delete ui;
}

void LinkMySQL::configmysql(){
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
}

QString LinkMySQL::getTime(){
    QString timestr;
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    timestr = dateTime .toString("yyyy-MM-dd/hh:mm:ss");//格式化时间
    return timestr;
}

void LinkMySQL::on_BackBtn_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();
}

void LinkMySQL::on_TestBtn_clicked()
{
    qDebug()<<QSqlDatabase::drivers();
}

void LinkMySQL::on_LinkBtn_clicked()
{
    configmysql();
    //打开数据库（已经安装过mysql驱动了）
    if(db.open()==false){
        ui->MyText->append("数据库连接失败！");
        qDebug()<<db.lastError();
    }
    else{
        ui->MyText->append("数据库连接成功！");
        ui->MyText->append(getTime());
    }
}

void LinkMySQL::on_FindAllBtn_clicked()
{
    QSqlQuery query;
    query.exec("select * from aht20");
    while(query.next()){
        qDebug()<<query.value(0).toInt()
                  //               <<query.value("name").toString().toUtf8().data()
               <<query.value(1).toDouble()
              <<query.value(2).toString().toUtf8().data();
        QString temp,humi,time;
        temp = "温度："+QString::number(query.value(0).toDouble(),10,2);
        humi = "湿度："+QString::number(query.value(1).toDouble(),10,2);
        time = "日期："+query.value(2).toString();
        ui->MyText->append(temp+"  "+humi+"  "+time);
    }
}

void LinkMySQL::on_InsertBtn_clicked()
{
    QSqlQuery query;
    query.prepare("insert into aht20 (temp,humi,time) values (:temp,:humi,:time)");  //:id之类的名字时自定义的 自己方便就好
    //添加绑定数据
    QVariantList idList;    //创建一个id列表
    idList << 25.0;
    query.bindValue(":temp",idList); //完成:id的绑定
    QVariantList nameList;
    nameList << 31.7;
    query.bindValue(":humi",nameList);   //完成:name的绑定
    QVariantList ageList;
    ageList << getTime();
    query.bindValue(":time",ageList);    //完成:age的绑定
    //执行批处理
    bool ok = query.execBatch();
    if(ok){
        ui->MyText->append("插入数据成功！"+getTime());
    }
    else{
        ui->MyText->append("插入数据失败！"+getTime());
    }
}
