#include "tcp_window.h"
#include "ui_tcp_window.h"

SOCKET tcpclient_socket = INVALID_SOCKET;
MyThread *mythread;
QThread *qthread;
float mic,strain_temp;
QString tcptimestr,micstr,tcptempstr;
int ID;

TCP_Window::TCP_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TCP_Window)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    this->setWindowTitle("TCP助手");
    this->setWindowIcon(QIcon(":/Img/logo.png"));
    mythread = new MyThread;
    qthread = new QThread(this);
    mythread->moveToThread(qthread);
    connect(mythread,&MyThread::mySignal,this,&TCP_Window::getdata);
    connect(this, &TCP_Window::startThread, mythread, &MyThread::myconnect);
    connect(this, &TCP_Window::destroyed, this, &TCP_Window::dealClose);
}

TCP_Window::~TCP_Window()
{
    delete ui;
}

//获取系统时间
void TCP_Window::getTime(){
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    tcptimestr = dateTime .toString("yyyy-MM-dd/hh:mm:ss");//格式化时间
}

//插入到数据库
void TCP_Window::insert2sql(){
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
    if(db.open()==false){
        qDebug()<<"连接失败";
    }
//    db.open();
    QSqlQuery query;
    query.prepare("insert into tcp(num,strain,temp,time) values (:ID,:strain,:temp,:time)");
    //添加绑定数据
    QVariantList IDList;
    IDList << ID;
    query.bindValue(":ID",IDList);
    QVariantList strainList;
    strainList << micstr;
    query.bindValue(":strain",strainList);
    QVariantList tempList;
    tempList << tcptempstr;
    query.bindValue(":temp",tempList);
    QVariantList timeList;
    timeList << tcptimestr;
    query.bindValue(":time",timeList);
//    query.prepare("insert into tcp(ID,strain,temp,time) values (?,?,?,?)");
//    //添加绑定数据
//    QVariantList IDList;
//    IDList << ID;
//    query.addBindValue(IDList);
//    QVariantList strainList;
//    strainList << micstr;
//    query.addBindValue(strainList);
//    QVariantList tempList;
//    tempList << tcptempstr;
//    query.addBindValue(tempList);
//    QVariantList timeList;
//    timeList << tcptimestr;
//    query.addBindValue(timeList);
    //执行批处理
    int k = query.execBatch();
    if(k == 0){
        qDebug()<<"失败"<<query.lastError();
    }
    db.close();
}

//设置一个进程用于获取数据
void TCP_Window::getdata(){
    int BUFFER_SIZE = 4196;
    char recv_data[BUFFER_SIZE+1];


    char *data = new char[8];	// 要进行输入的指令数据
    for(int i=0;i<5;i++){
        //		char *data;
        //            printf("具体指令给格式为0+传感器编号（1，2，3，4，5）+0300010002，请输入采集传感器的编号（0表示退出采集）：\n");
        //            scanf("%s",data);
        switch(i){
        case 0:{
            data = "010300010002";
            break;
        }
        case 1:{
            data = "020300010002";
            break;
        }
        case 2:{
            data = "030300010002";
            break;
        }
        case 3:{
            data = "040300010002";
            break;
        }
        case 4:{
            data = "050300010002";
            break;
        }

        }

        uint16_t crc;	// CRC 校验数据
        unsigned char * cmd;	// 要进行输入的控制台shuju
        char crc1[8];
        cmd = fromhex(data);	// 获取数据
        crc = CRC_16(cmd);		// 进行 CRC 校验
        uint8_t a = 0xFF;
        for(int i=0;i<6;i++){
            //TODO
            crc1[i] = cmd[i];
        }
        crc1[6] = a & crc;	// 设置最后两位为 CRC 校验位
        crc1[7] = (crc >> 8) & a;
        if (send(tcpclient_socket, crc1, 8, 0) < 0) {
            ui->MyText->append("发送指令失败！");
            //        break;
            return;
        }

        int ret = recv(tcpclient_socket, recv_data, BUFFER_SIZE, 0);
        if (ret < 0) {
            ui->MyText->append("接收数据失败！");
            //        break;
            return;
        }
        recv_data[ret]=0; // 正确结束收到的字符串
        char yb[4],wd[4];
        for(int i=0;i<4;i++){
            //TODO
            yb[i] = recv_data[4+i];
            wd[i] = recv_data[8+i];

        }
        ID = i+1;
        mic = hexToDec(yb)/100.0;		// 由于我们获取到的数据是十六进制，这里需要进行进制转换
        strain_temp = hexToDec(wd)/100.0;
        micstr = QString::number(mic,10,6);
        tcptempstr = QString::number(strain_temp,10,6);
        //            printf("应变：%f\r\n",mic);
        //            printf("温度：%f\r\n",strain_temp);
        ui->MyText->append("数据ID： "+QString::number(i));
        ui->MyText->append("应变传感器： "+micstr);
        ui->MyText->append("温度传感器： "+tcptempstr);
        if(ui->SqlcheckBox->isChecked()){
            getTime();
            insert2sql();
        }
    }

}

void TCP_Window::dealClose(){
    on_GetBtn_clicked();
    delete mythread;
}

/* 返回ch字符在sign数组中的序号 */
int TCP_Window::getIndexOfSigns(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F')
    {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return -1;
}
/* 十六进制数转换为十进制数 */
int TCP_Window::hexToDec(char *source)
{
    int sum = 0;
    char low,high;
    for(int i=0,j=7;i<4;i++){
        //TODO
        high = (source[i] & 0xf0)>>4;
        low = source[i] & 0x0f;
        sum += high*pow(16,j--)+low*pow(16,j--);
    }
    return sum;
}


unsigned char * TCP_Window::fromhex(char *str)
{
    static unsigned char buf[512];
    size_t len = strlen(str) / 2;
    if (len > 512) len = 512;
    for (size_t i = 0; i < len; i++) {
        unsigned char c = 0;
        if (str[i * 2] >= '0' && str[i*2] <= '9')
            c += (str[i * 2] - '0') << 4;
        if ((str[i * 2] & ~0x20) >= 'A' && (str[i*2] & ~0x20) <= 'F')
            c += (10 + (str[i * 2] & ~0x20) - 'A') << 4;
        if (str[i * 2 + 1] >= '0' && str[i * 2 + 1] <= '9')
            c += (str[i * 2 + 1] - '0');
        if ((str[i * 2 + 1] & ~0x20) >= 'A' && (str[i * 2 + 1] & ~0x20) <= 'F')
            c += (10 + (str[i * 2 + 1] & ~0x20) - 'A');
        buf[i] = c;
    }
    return buf;
}

uint16_t TCP_Window::CRC_16(uint8_t *temp)
{
    uint8_t i,j;
    uint16_t CRC_1 = 0xFFFF;          //声明CRC寄存区，也就是步骤1
    for(i = 0;i < 6;i++)       //这里的for循环说的是步骤6中的重复步骤 2 到步骤 5
    {
        CRC_1 ^= temp[i]; //这里就是步骤2，进行异或运算
        for(j = 0;j < 8;j++)         //用来将异或后的低八位全部移出的for循环
        {
            if(CRC_1 & 0x01)         //判断低八位的最后一位是否为1，为1时执行下列语句，也就是步骤3说的移位判断与步骤5说的右移8次
            {
                /*一定要先移位，再异或*/
                CRC_1 >>=1;          //移位后再异或，就是步骤4
                CRC_1 ^= 0xA001;     //0xA001为0x8005的逆序
            }
            else                    //若不为1，则直接移位。
            {
                CRC_1 >>=1;
            }
        }
    }

    return(CRC_1);
}

void TCP_Window::on_BackBtn_clicked()
{
    if(ui->GetBtn->text() == "停止获取"){
        QMessageBox::information(this,"提示","退出前需要手动关闭数据获取");
    }
    else{
        MainWindow *main = new MainWindow();
        main->show();
        this->close();
    }
}

void TCP_Window::on_GetBtn_clicked()
{
    QString portstr = ui->PortText->text();
    QString IPstr = ui->IPText->text();
    QString sleeptime = ui->SleepspinBox->text();
    char* IP;
    QByteArray ba = IPstr.toLatin1(); // must
    IP=ba.data();
    int Port = portstr.toInt();
    int stime = sleeptime.toInt();
    if(ui->GetBtn->text() == "获取数据"){
        WORD winsock_version = MAKEWORD(2,2);
        //WSADATA结构包含有关Windows Sockets实现的信息。
        WSADATA wsa_data;
        //Winsock进行初始化
        //调用 WSAStartup 函数以启动使用 WS2 _32.dll
        //WSAStartup的 MAKEWORD (2，2) 参数发出对系统上 Winsock 版本2.2 的请求，并将传递的版本设置为调用方可以使用的最新版本的 Windows 套接字支持
        int iResult = WSAStartup(MAKEWORD(2, 2), &wsa_data);
        if (iResult != 0) {
            ui->MyText->append("WSAStartup 初始化失败！");
            WSACleanup();
            return;
        }

        // socket 函数创建绑定到特定
        //为服务器创建一个SOCKET来监听客户端连接
        //socket函数创建绑定到特定传输服务提供者的套接字。
        //参数1：地址族规范
        //参数2：新套接字的类型规范
        //参数3：使用的协议
        tcpclient_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (tcpclient_socket == INVALID_SOCKET) {
            ui->MyText->append("套接字错误！");
            WSACleanup();
            return;
        }

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(Port);
        server_addr.sin_addr.S_un.S_addr = ::inet_addr(IP);
        //尝试连接到一个地址，直到一个成功
        if (::connect(tcpclient_socket, (LPSOCKADDR)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
            ui->MyText->append("连接失败！");
            closesocket(tcpclient_socket);//关闭一个已存在的套接字。
            tcpclient_socket = INVALID_SOCKET;
            return;
        }
        qDebug()<<"1111";
        ui->GetBtn->setText("停止获取");
        qthread->start();
        mythread->setFlag(false);
        emit startThread(stime);
    }
    else{
        ui->GetBtn->setText("获取数据");
        qDebug()<<"stopthread";
        mythread->setFlag(true);
        qthread->quit();
        qthread->wait();
        closesocket(tcpclient_socket);
        WSACleanup();
    }
}
