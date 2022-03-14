#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>

class database
{
public:
    database();
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
};

#endif // DATABASE_H
