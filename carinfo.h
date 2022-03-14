#ifndef CARINFO_H
#define CARINFO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QString>
#include <QTableView>
#include <Qt>

namespace Ui {
class carInfo;
}

class carInfo : public QDialog
{
    Q_OBJECT

public:
    explicit carInfo(QWidget *parent = nullptr);
    ~carInfo();
    void setGrz(QString grz, QString vin, QString mileage);
    void updateTable();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::carInfo *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QSqlQueryModel *querymodel;
};

#endif // CARINFO_H
