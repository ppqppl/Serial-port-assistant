#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <main.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // 重写事件
    void keyPressEvent(QKeyEvent *event);
//    void keyReleaseEvent(QKeyEvent *event);



private slots:
    void on_ExitBtn_clicked();

    void on_JumpComBtn_clicked();

    void on_JumpModbusBtn_clicked();

    void on_MySQLBtn_clicked();

    void on_JumpTCPBtn_clicked();

    void on_JumpUDPBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
