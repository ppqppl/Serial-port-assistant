#ifndef UDP_WINDOW_H
#define UDP_WINDOW_H

#include <QMainWindow>
#include <main.h>

namespace Ui {
class UDP_Window;
}

class UDP_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit UDP_Window(QWidget *parent = nullptr);
    ~UDP_Window();

    int getIndexOfSigns(char ch);
    int hexToDec(char *source);
    uint16_t CRC_16(uint8_t *temp);
    unsigned char * fromhex(char *str);
    void getdata();
    void dealClose();
    void getTime();
    void insert2sql(int i);

signals:
    void startThread(int n);
    void destroyThread();

private slots:
    void on_BackBtn_clicked();

    void on_GetBtn_clicked();

private:
    Ui::UDP_Window *ui;
};

#endif // UDP_WINDOW_H
