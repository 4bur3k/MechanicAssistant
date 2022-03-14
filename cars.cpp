#include "cars.h"
#include "ui_cars.h"
#include "newto.h"

#include <Qt>

//Меню пользователя
cars::cars(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cars)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    ui->carsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->carsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    query = new QSqlQuery(db);

    query->exec("CREATE TABLE Maint (ГРЗ TEXT NOT NULL, Работы    TEXT NOT NULL, Стоимость	TEXT NOT NULL, Комментарий TEXT NOT NULL, Дата	TEXT NOT NULL, Пробег	TEXT);");

    model = new QSqlTableModel(this, db);
    model->setTable("Cars");
    model->select();

    ui->carsTable->setModel(model);
    ui->carsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    model2 = new QSqlTableModel(this, db);
    model2->setTable("Maint");
    model2->select();

    ui->oldRepairsTable->setModel(model2);
    ui->oldRepairsTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    querymodel = new QSqlQueryModel;

    //Блокируем кнопки
    ui->pushButton->setEnabled(false);
    ui->repairsListButton->setEnabled(false);
}

cars::~cars()
{
    delete ui;
}

//Выход
void cars::on_pushButton_3_clicked()
{
    hide();
}

//Окно создания новго ТО
void cars::on_pushButton_clicked()
{    
    QModelIndex currentIndex = ui->carsTable->currentIndex();
    QString grz = (ui->carsTable->model()->data(ui->carsTable->model()->index(currentIndex.row(),0), 0)).toString();

    hide();

    newto to;
    to.setGrz(grz); //Записывает Гос номер выбранного авто в новом окне
    to.setModal(true);
    to.exec();

}

//Открывает список всех ТО выьранного автомобиля
void cars::on_repairsListButton_clicked()
{
    QModelIndex currentIndex = ui->carsTable->currentIndex();
    QString grz = (ui->carsTable->model()->data(ui->carsTable->model()->index(currentIndex.row(),0), 0)).toString();

    querymodel->setQuery("SELECT * FROM Maint WHERE ГРЗ = '" + grz + "';");
    querymodel->setHeaderData(0, Qt::Horizontal, tr("Гос номер"));
    querymodel->setHeaderData(1, Qt::Horizontal, tr("Работы"));
    querymodel->setHeaderData(2, Qt::Horizontal, tr("Стоимость"));
    querymodel->setHeaderData(3, Qt::Horizontal, tr("Комментарий"));
    querymodel->setHeaderData(4, Qt::Horizontal, tr("Дата"));
    querymodel->setHeaderData(5, Qt::Horizontal, tr("Пробег"));

    ui->oldRepairsTable->setModel(querymodel);
}




//Разблокируем кнопки
void cars::on_carsTable_clicked(const QModelIndex &index)
{
    ui->pushButton->setEnabled(true);
    ui->repairsListButton->setEnabled(true);
}

