#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlDriver>
#include <QSqlError>

class DB_Manager
{
public:
    DB_Manager();
    void set_up_connection();
    void create_table(QString table_name, int row, int column);
    void insert_line(int);
    void insert_item(int row,QString item);
    void read_line(int);

private:
    QSqlDatabase m_db;
};

#endif // DB_MANAGER_H
