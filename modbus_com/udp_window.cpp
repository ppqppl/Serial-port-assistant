#include "udp_window.h"
#include "ui_udp_window.h"

SOCKET udpclient_socket =  socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in server_addr;
MyThread *myUDPthread;
QThread *qUDPthread;
float UDPhum,UDPtemp,water_level;
QString UDPtimestr,UDPhumstr,UDPtempstr,udpwater_levelstr;
int UDPID;

UDP_Window::UDP_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UDP_Window)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    this->setWindowTitle("UDP助手");
    this->setWindowIcon(QIcon(":/Img/logo.png"));
    myUDPthread = new MyThread;
    qUDPthread = new QThread(this);
    myUDPthread->moveToThread(qUDPthread);
    connect(myUDPthread,&MyThread::mySignal,this,&UDP_Window::getdata);
    connect(this, &UDP_Window::startThread, myUDPthread, &MyThread::myconnect);
    connect(this, &UDP_Window::destroyed, this, &UDP_Window::dealClose);
}

UDP_Window::~UDP_Window()
{
    delete ui;
}

//获取系统时间
void UDP_Window::getTime(){
    QDateTime dateTime= QDateTime::currentDateTime();//获取系统当前的时间
    UDPtimestr = dateTime .toString("yyyy-MM-dd/hh:mm:ss");//格式化时间
}

//插入到数据库
void UDP_Window::insert2sql(int i){
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
    getTime();
    if(i == 0){
        query.prepare("insert into udp_temp_humi (temp,humi,time) values (:temp,:humi,:time)");
        //        添加绑定数据
        QVariantList tempList;
        tempList << UDPtempstr;
        query.bindValue(":temp",tempList);
        QVariantList humiList;
        humiList << UDPhumstr;
        query.bindValue(":humi",humiList);
        QVariantList timeList;
        timeList << UDPtimestr;
        query.bindValue(":time",timeList);
    }
    else{
        query.prepare("insert into udp (num,deflect,time) values (:num,:deflect,:time)");
        //        添加绑定数据
        QVariantList idList;
        idList << UDPID;
        query.bindValue(":num",idList);
        QVariantList levList;
        levList << udpwater_levelstr;
        query.bindValue(":deflect",levList);
        QVariantList timeList;
        timeList << UDPtimestr;
        query.bindValue(":time",timeList);
    }


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

void UDP_Window::dealClose(){
    on_GetBtn_clicked();
    delete myUDPthread;
}

void UDP_Window::getdata(){
    qDebug()<<"udp";
    int BUFFER_SIZE = 4196;
    char recv_data[BUFFER_SIZE+1];

    //		uint8_t data[length_8];
    char *data = new char[8];
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
            data = "020300010001";
            break;
        }
        case 2:{
            data = "030300010001";
            break;
        }
        case 3:{
            data = "040300010001";
            break;
        }
        case 4:{
            data = "050300010001";
            break;
        }
        }
        uint16_t crc;
        unsigned char * cmd;
        char crc1[8];
        cmd = fromhex(data);
        crc = CRC_16(cmd);
        uint8_t a = 0xFF;
        for(int i=0;i<6;i++){
            //TODO
            crc1[i] = cmd[i];
        }
        crc1[6] = a & crc;
        crc1[7] = (crc >> 8) & a;
        if (sendto(udpclient_socket, crc1, 8, 0,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0) {
            ui->MyText->append("发送指令失败！");
            return;
        }
        int ret = recvfrom(udpclient_socket, recv_data, BUFFER_SIZE, 0,NULL,NULL);
        if (ret < 0) {
            ui->MyText->append("接收数据失败！");
            return;
        }
        recv_data[ret]=0; // correctly ends received string
        char var = cmd[5];
        if(var == 2){
            //TODO
            char yb[4],wd[4];
            for(int i=0;i<4;i++){
                //TODO
                yb[i] = recv_data[4+i];
                wd[i] = recv_data[8+i];
            }
            UDPtemp = hexToDec(yb)/100.0;
            UDPhum = hexToDec(wd);
            UDPtempstr = QString::number(UDPtemp,10,6);
            UDPhumstr = QString::number(UDPhum,10,6);
            ui->MyText->append("数据ID： "+QString::number(i));
            ui->MyText->append("温度传感器： "+UDPtempstr);
            ui->MyText->append("湿度传感器： "+UDPhumstr);
            if(ui->SqlcheckBox->isChecked()){
                insert2sql(i);
            }
        }else if(var == 1){
            //TODO
            char nd[4];
            for(int i=0;i<4;i++){
                //TODO
                nd[i] = recv_data[4+i];
            }
            water_level = hexToDec(nd)*10.0;
            udpwater_levelstr = QString::number(water_level,10,6);
            UDPID = i;
            ui->MyText->append("数据ID： "+QString::number(UDPID));
            ui->MyText->append("静力水准仪： "+udpwater_levelstr);
            if(ui->SqlcheckBox->isChecked()){
                insert2sql(i);
            }
        }
    }
}

/* 返回ch字符在sign数组中的序号 */
int UDP_Window::getIndexOfSigns(char ch)
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
int UDP_Window::hexToDec(char *source)
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


unsigned char * UDP_Window::fromhex(char *str)
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

uint16_t UDP_Window::CRC_16(uint8_t *temp)
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

    //	CRC_1 = (((CRC_1 & 0xFF)<<8) + (CRC_1>>8));
    //	printf("%04x\r\n",CRC_1);     //用于打印检测CRC校验码
    return(CRC_1);
}

void UDP_Window::on_BackBtn_clicked()
{
    MainWindow *main = new MainWindow();
    main->show();
    this->close();
}

void UDP_Window::on_GetBtn_clicked()
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
        WSADATA wsa_data;
        if (WSAStartup(winsock_version, &wsa_data) != 0) {
            ui->MyText->append("WSAStartup 初始化失败！");
            return;
        }

        udpclient_socket =  socket(AF_INET, SOCK_DGRAM, 0);

        if (udpclient_socket == INVALID_SOCKET) {
            ui->MyText->append("创建连接失败！");
            return;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(Port);
        server_addr.sin_addr.S_un.S_addr = inet_addr(IP);
        ui->GetBtn->setText("停止获取");
        qUDPthread->start();
        myUDPthread->setFlag(false);
        emit startThread(stime);
    }

    else{
        ui->GetBtn->setText("获取数据");
        qDebug()<<"stopthread";
        myUDPthread->setFlag(true);
        qUDPthread->quit();
        qUDPthread->wait();
        closesocket(udpclient_socket);
        WSACleanup();
    }
}
