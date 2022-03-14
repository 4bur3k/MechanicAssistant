#ifndef NEWCAR_H
#define NEWCAR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class newCar;
}

class newCar : public QDialog
{
    Q_OBJECT

public:
    explicit newCar(QWidget *parent = nullptr);
    ~newCar();

private slots:
    void on_pushButton_clicked();

    void on_SaveButton_clicked();

private:
    Ui::newCar *ui;
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // NEWCAR_H
