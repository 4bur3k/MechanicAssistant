#include <QString>
#include <QtSql>

#include "registration.h"
#include "ui_registration.h"
#include "mainwindow.h"

registration::registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    query = new QSqlQuery(db);

}

registration::~registration()
{
    delete ui;
}
//Выход
void registration::on_pushButton_3_clicked()
{
    hide();

}

//Создаем аккаунт
void registration::on_createAccountButton_clicked()
{
    QString passwordLine = ui->PasswordLine->text();
    QString loginLine = ui->LoginLine->text();
    QString FIO = ui->FioLine->text();
    QString isAdmin = "0";  //1 админ, 0 пользователь

    if(ui->keyLine->text() == "123"){  //Админ если знает ключ
        isAdmin = "1";
    }


   if(!(query->exec("INSERT INTO Users (ФИО, Логин, Пароль, isAdmin) VALUES ('" + FIO + "', '" + loginLine + "', '" + passwordLine + "', " +
              isAdmin + ");"))){            //Проверка, что уже существует
       qDebug() << "Account is existing!";
       ui->notValidLog->setText("Аккаунт уже сущетсвет!");
   } else {
       qDebug () << "Account has been created";
       hide();
   }


}

