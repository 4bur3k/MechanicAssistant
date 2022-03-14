#ifndef ADMINCARS_H
#define ADMINCARS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QString>

namespace Ui {
class adminCars;
}

class adminCars : public QDialog
{
    Q_OBJECT

public:
    explicit adminCars(QWidget *parent = nullptr);
    ~adminCars();

private slots:
    void on_pushButton_3_clicked();

    void on_moreButton_clicked();

    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::adminCars *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // ADMINCARS_H
