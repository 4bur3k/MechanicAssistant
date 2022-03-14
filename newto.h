#ifndef NEWTO_H
#define NEWTO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class newto;
}

class newto : public QDialog
{
    Q_OBJECT

public:
    explicit newto(QWidget *parent = nullptr);
    ~newto();
    void setGrz(QString grz);


private slots:
    void on_pushButton_2_clicked();

    void on_saveButton_clicked();

    void updateMileAge(QString mileage, QString grz);


private:
    Ui::newto *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // NEWTO_H
