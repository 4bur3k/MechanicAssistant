#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class registration;
}

class registration : public QDialog
{
    Q_OBJECT

public:
    explicit registration(QWidget *parent = nullptr);
    ~registration();

private slots:
    void on_pushButton_3_clicked();

    void on_createAccountButton_clicked();

private:
    Ui::registration *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // REGISTRATION_H
