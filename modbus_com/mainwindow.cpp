#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("STM32助手");
    this->setWindowIcon(QIcon(":/Img/logo.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ExitBtn_clicked()
{
    qDebug()<<"退出";
    this->close();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Escape){
        this->close();
    }
}

void MainWindow::on_JumpComBtn_clicked()
{
    COM_Window *com = new COM_Window();
    com->show();
    this->close();
}

void MainWindow::on_JumpModbusBtn_clicked()
{
    Modbus_Window *mod = new Modbus_Window();
    mod->show();
    this->close();
}

void MainWindow::on_MySQLBtn_clicked()
{
    LinkMySQL *mysql = new LinkMySQL();
    mysql->show();
    this->close();
}

void MainWindow::on_JumpTCPBtn_clicked()
{
    TCP_Window *tcp = new TCP_Window();
    tcp->show();
    this->close();
}

void MainWindow::on_JumpUDPBtn_clicked()
{
    UDP_Window *udp = new UDP_Window();
    udp->show();
    this->close();
}
