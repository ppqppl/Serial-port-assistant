//#ifndef MODBUS_WINDOW_H
//#define MODBUS_WINDOW_H

//#include <QMainWindow>

//namespace Ui {
//class Modbus_Window;
//}

//class Modbus_Window : public QMainWindow
//{
//    Q_OBJECT

//public:
//    explicit Modbus_Window(QWidget *parent = nullptr);
//    ~Modbus_Window();

//private:
//    Ui::Modbus_Window *ui;
//};

//#endif // MODBUS_WINDOW_H


#ifndef MODBUS_WINDOW_H
#define MODBUS_WINDOW_H

#include <QMainWindow>
#include <main.h>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class Modbus_Window; }
QT_END_NAMESPACE

class Modbus_Window : public QMainWindow
{
    Q_OBJECT

public:
    Modbus_Window(QWidget *parent = nullptr);
    ~Modbus_Window();

    void getTime();
    void insert2sql();

private slots:
    void on_actionExit_triggered();

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

    void on_actionRefresh_triggered();

    void on_actionConfig_triggered();

    void on_actionSave_triggered();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_pushButtonSend_clicked();

    void on_checkBoxAuto_clicked(bool checked);

    void ReadSerialData();

    void ChartDisplay();

    void on_BackBtn_clicked();

private:
    void InitialSetting();

    void InitChart();

    void SearchSerialPorts();

    //QModbusDataUnit readRequest() const;
    void ReadRequest();

    void WriteRequest(QList<quint16> values);

private:
    Ui::Modbus_Window *ui;

    //QSerialPort *serialPort;
    QModbusReply *lastRequest = nullptr;
    QModbusClient *modbusDevice = nullptr;
    QTimer *pollTimer;
    QChart *mChart;
    QValueAxis *axisY;
    QValueAxis *axisX;
    QLineSeries *lineSeries[8];
    QTimer *chartTimer;

    uint16_t values[8];
};
#endif // MODBUS_WINDOW_H
