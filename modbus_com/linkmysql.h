#ifndef LINKMYSQL_H
#define LINKMYSQL_H

#include <QMainWindow>
#include <main.h>

namespace Ui {
class LinkMySQL;
}

class LinkMySQL : public QMainWindow
{
    Q_OBJECT

public:
    explicit LinkMySQL(QWidget *parent = nullptr);
    ~LinkMySQL();


    void configmysql();
    QString getTime();

private slots:
    void on_BackBtn_clicked();

    void on_TestBtn_clicked();

    void on_LinkBtn_clicked();

    void on_FindAllBtn_clicked();

    void on_InsertBtn_clicked();

private:
    Ui::LinkMySQL *ui;
};

#endif // LINKMYSQL_H
