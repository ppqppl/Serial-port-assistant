#ifndef COM_WINDOW_H
#define COM_WINDOW_H

#include <QMainWindow>
#include <main.h>

namespace Ui {
class COM_Window;
}

class COM_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit COM_Window(QWidget *parent = nullptr);
    ~COM_Window();

    void SearchCOM();   // 自动获取并添加串口号
    void setcombox(bool judge); // 初始下拉框
    QString getTime();  // 获取系统时间
    QString StringToHex(QString str);  // 字符串 转 16进制

    QSerialPort * serial;

private slots:

    // 自定义槽函数

    void serialPortReadyRead();


    // 系统槽函数

    void on_BackBtn_clicked();

    void on_RenewCOMBtn_clicked();

    void on_OpenCOMBtn_clicked();

    void on_ClearBtn_clicked();

private:
    Ui::COM_Window *ui;
};

#endif // COM_WINDOW_H
