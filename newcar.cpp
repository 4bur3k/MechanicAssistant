#include <QString>
#include <QtSql>

#include "newcar.h"
#include "ui_newcar.h"
#include "admincars.h"

//Окно регистрации новго авто
newCar::newCar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newCar)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    query = new QSqlQuery(db);
}

newCar::~newCar()
{
    delete ui;
}

//Открывает меню администратора
void newCar::on_pushButton_clicked()
{
    hide();
    adminCars inf;
    inf.setModal(true);
    inf.exec();
}


//Записывает в БД данные о новом авто
void newCar::on_SaveButton_clicked()
{
    QString GrzLine = ui->grzLine->text();
    QString VinLine = ui->vinLine->text();
    QString MileLine = ui->mileLine->text();

//Если авто существует - выходим
    if(!(query->exec("INSERT INTO Cars (ГРЗ, Вин, Пробег) VALUES ('" + GrzLine.toUpper() + "', '"+ VinLine + "', '" + MileLine + "');"))){
           qDebug() << "Car is existing!";

        } else { qDebug() << "Car has been added"; }

        hide();
        adminCars inf;
        inf.setModal(true);
        inf.exec();
}

