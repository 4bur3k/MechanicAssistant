#include "carinfo.h"
#include "ui_carinfo.h"
#include "admincars.h"

//Информация по каждому авто
carInfo::carInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::carInfo)
{
    ui->setupUi(this);
    setFixedSize(800, 400);

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    querymodel = new QSqlQueryModel;

}

carInfo::~carInfo()
{
    delete ui;
}

//Открывает панель администратора
void carInfo::on_pushButton_3_clicked()
{
    hide();
    adminCars adm;
    adm.setModal(true);
    adm.exec();
}

//Метод, устонавливающий Гос номер выбранного в другом окне авто
void carInfo::setGrz(QString grz, QString vin, QString mileage){

    ui->grzLine->setText(grz);
    ui->vinLine->setText(vin);
    ui->miles->setText(mileage);
}


void  carInfo::updateTable(){
    QString grz = ui->grzLine->text();

    querymodel->setQuery("SELECT Работы, Стоимость, Комментарий, Дата, Пробег FROM Maint WHERE ГРЗ = '" + grz + "';");
    querymodel->setHeaderData(0, Qt::Horizontal, tr("Работы"));
    querymodel->setHeaderData(1, Qt::Horizontal, tr("Стоимость"));
    querymodel->setHeaderData(2, Qt::Horizontal, tr("Комментарий"));
    querymodel->setHeaderData(3, Qt::Horizontal, tr("Дата"));
    querymodel->setHeaderData(4, Qt::Horizontal, tr("Пробег"));

    ui->tableView->setModel(querymodel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

}

