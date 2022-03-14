#include "database.h"

database::database()
{

     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("./DB.db");
            if(db.open()){
                 qDebug("open");
            } else {qDebug("not open");}

    query = new QSqlQuery(db);

}
