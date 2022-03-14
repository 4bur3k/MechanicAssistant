#ifndef CARS_H
#define CARS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QString>
#include <QTableView>
#include <Qt>

namespace Ui {
class cars;
}

class cars : public QDialog
{
    Q_OBJECT

public:
    explicit cars(QWidget *parent = nullptr);
    ~cars();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_repairsListButton_clicked();


    void on_carsTable_clicked(const QModelIndex &index);

private:
    Ui::cars *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QSqlTableModel *model2;
    QSqlQueryModel *querymodel;


};

#endif // CARS_H
