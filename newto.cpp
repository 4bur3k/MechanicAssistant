#include "newto.h"
#include "ui_newto.h"
#include "cars.h"

#include <QString>
#include<QDate>

//Окно регистрации нового ТС
newto::newto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newto)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    query = new QSqlQuery(db);
}

newto::~newto()
{
    delete ui;
}

//Открывает меню пользователя
void newto::on_pushButton_2_clicked()
{
    hide();
    cars cars;
    cars.setModal(true);
    cars.exec();
}

//Записывет данные ТО
void newto::on_saveButton_clicked()
{
    QString grz = ui->GrzLine->text().toUpper();
    QString workLine = ui->workLine->text();
    QString priceLine = ui->priceLine->text();
    QString commentLine = ui->commentLine->toPlainText();
    QString mileLine = ui->kmLine->text();
    QDate date = ui->dateEdit->date();

    query = new QSqlQuery;

    if(!(query->exec("INSERT INTO Maint (ГРЗ, Работы, Стоимость, Комментарий, Дата, Пробег) VALUES ('" + grz + "', '" + workLine + "', '" + priceLine + "', '" + commentLine + "', '" +
               date.toString("dd.MM.yyyy") + "', '" + mileLine + "');"))){
        qDebug() << "New TO added";
    } else {
        updateMileAge(mileLine, grz);
        hide();
        cars cars;
        cars.setModal(true);
        cars.exec();
    }
}

//Обновляет данные о пробеге в таблице
void newto::updateMileAge(QString mileage, QString grz){
    QSqlQuery *query = new QSqlQuery(db);

    query->exec("UPDATE Cars SET Пробег = '" + mileage + "' WHERE ГРЗ = '" + grz + "';");
}

//Устанвливаем Гос номер выбранного в предыдущем окне авто
void newto::setGrz(QString grz){
    ui->GrzLine->setText(grz);
}




