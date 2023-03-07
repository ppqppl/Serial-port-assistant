#ifndef TCP_WINDOW_H
#define TCP_WINDOW_H

#include <QMainWindow>
#include <main.h>

namespace Ui {
class TCP_Window;
}

class TCP_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit TCP_Window(QWidget *parent = nullptr);
    ~TCP_Window();

    int getIndexOfSigns(char ch);
    int hexToDec(char *source);
    uint16_t CRC_16(uint8_t *temp);
    unsigned char * fromhex(char *str);
    void getdata();
    void dealClose();
    void getTime();
    void insert2sql();

signals:
    void startThread(int n);
    void destroyThread();

private slots:
    void on_BackBtn_clicked();

    void on_GetBtn_clicked();

private:
    Ui::TCP_Window *ui;

protected:
};

#endif // TCP_WINDOW_H
