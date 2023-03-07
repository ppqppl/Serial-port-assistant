#include "mythread.h"

MyThread::MyThread(QObject *parent) : QObject(parent){
    isStop = false;
}

void MyThread::myconnect(int n)
{
    qDebug()<<n;
    while( !isStop )
    {

        QThread::sleep(n);
        emit mySignal();

        qDebug() << "子线程号：" << QThread::currentThread();

        if(isStop)
        {
            break;
        }
    }
}
//这个函数非常有作用可以实现多个按钮对线程的控制开启和停止
void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
