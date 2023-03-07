#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTime>
#include <QtCharts>
//#include <QModbusDataUnit>
#include <QModbusClient>

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    void InitialSetting();

    void InitChart();

    void SearchSerialPorts();

    //QModbusDataUnit readRequest() const;
    void ReadRequest();

    void WriteRequest(QList<quint16> values);

private:
    Ui::MainWindow *ui;

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
#endif // MAINWINDOW_H
