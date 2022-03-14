#include "admincars.h"
#include "ui_admincars.h"
#include "carinfo.h"
#include "newcar.h"

//Меню администратора
adminCars::adminCars(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminCars)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    query = new QSqlQuery(db);

    model = new QSqlTableModel(this, db);
    model->setTable("Cars");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    //Блокируем кнопки, пока пользователь не выберет какое то авто.
    ui->moreButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

adminCars::~adminCars()
{
    delete ui;
}

//Выход
void adminCars::on_pushButton_3_clicked()
{
    hide();
}

//Открывает окно с инфомрмацией овыбранном автомобиле
void adminCars::on_moreButton_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    QString grz = (ui->tableView->model()->data(ui->tableView->model()->index(currentIndex.row(),0), 0)).toString();
    QString vin = (ui->tableView->model()->data(ui->tableView->model()->index(currentIndex.row(),1), 0)).toString();
    QString mileage = (ui->tableView->model()->data(ui->tableView->model()->index(currentIndex.row(),2), 0)).toString();

   // hide();
    carInfo inf;

    inf.setGrz(grz, vin, mileage);
    inf.updateTable();

    ui->moreButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);

    inf.setModal(true);
    inf.exec();
}

//Открывет окно регистрации автомобиля
void adminCars::on_pushButton_clicked()
{

    hide();
    newCar car;
    car.setModal(true);
    car.exec();
}

//Разблокируем кнопки
void adminCars::on_tableView_clicked(const QModelIndex &index)
{
    ui->moreButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

//Удаляет выбранное авто и его ТО
void adminCars::on_pushButton_2_clicked()
{
    QModelIndex currentIndex = ui->tableView->currentIndex();
    QString grz = (ui->tableView->model()->data(ui->tableView->model()->index(currentIndex.row(),0), 0)).toString();
    qDebug() << grz;

    query->exec("DELETE FROM Cars WHERE ГРЗ = '"+grz+"';");
    query->exec("DELETE FROM Maint WHERE ГРЗ = '"+grz+"';");

    qDebug() << "Car has been deleted";

    //Обновляем таблицу

    model->setTable("Cars");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->moreButton->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

