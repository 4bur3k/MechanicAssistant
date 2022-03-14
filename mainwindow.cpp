#include <QString>

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cars.h"
#include "registration.h"
#include "admincars.h"

//Главное меню
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./DB.db");
    if(db.open()){
        qDebug("DB open");
    } else {qDebug("DB not open");}

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Users (ФИО TEXT NOT NULL, Логин	TEXT NOT NULL, Пароль	TEXT NOT NULL, isAdmin TEXT NOT NULL, PRIMARY KEY(Логин));");
    query->exec("CREATE TABLE Cars (ГРЗ	TEXT NOT NULL, Вин	TEXT NOT NULL, Пробег	TEXT, PRIMARY KEY(ГРЗ));");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_enterButton_clicked()
{
    QString login = ui->loginLine->text();
    QString password = ui->passwordLine->text();

    query = new QSqlQuery(db);
    query->exec("SELECT * FROM Users");
    bool flag = false;
    do{    //Поочередно проходится по Логинам + Паролям и проверяет совпадения
            if(query->value(1).toString() == login && query->value(2).toString() == password && login != ""){
                if(query->value(3).toString() == "0"){  // Проверяет Пользователь или Админинстратор
                cars carForm;
                carForm.setModal(true);
                carForm.exec();
                } else {
                    adminCars adm;
                    adm.setModal(true);
                    adm.exec();
                }
                flag = true; //Если найдено совпадение - выходим из do while
            }

    } while (query->next() && flag ==false);

    if(flag == false){
       ui->notValidLog->setText("Неверный логин или пароль!");
       qDebug() << "Not correct login or passowrd";
    } else { ui->notValidLog->setText(""); }
}

//Открываем окно регитсрации
void MainWindow::on_newUserButton_clicked()
{
    registration registration;
    registration.setModal(true);
    registration.exec();

}





