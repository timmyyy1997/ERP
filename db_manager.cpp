#include "db_manager.h"
#include <QDebug>

DB_Manager::DB_Manager()
{

}

void DB_Manager::read_line(int row){
    qDebug() << "reading the Data in row: " << row;


}

void DB_Manager::insert_line(int row){

    QSqlQuery query;
    if(query.exec("INSERT INTO testtable (id,name,sn)"
                  "VALUES (100,101,102)"))
    {
       qDebug() << "query inserted";
    }
    else
    {
        qDebug() << "error:  " << query.lastError();

    }

}


void DB_Manager::set_up_connection(){
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/gradstudent1/Documents/Qt_projects/ERP_project/test2.db");
    m_db.open();
    if(!m_db.open()){
        qDebug() << "Error: cannot connect to testD.db file.";
    }
    else
        qDebug() << "Connection set up!";
}

void DB_Manager::create_table(QString table_name, int row, int column){

}
