
#ifndef DATABASEOPERATOR_H
#define DATABASEOPERATOR_H
#pragma execution_character_set("utf-8")

#include <QObject>
#include <QMessageBox>
#include <QString>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseOperator : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseOperator(QObject *parent = nullptr);

public:
    void db_WriteSQL(const QString sql);
    QSqlQuery db_SearchSQL(const QString sql);

private:
    /** ***************************************************
    * db:数据库本体,用于进行链接和初始化等操作
    * query:sql语句执行的中间桥,用于执行sql语句
    ** ************************************************* **/
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;

signals:

};

#endif // DATABASEOPERATOR_H
