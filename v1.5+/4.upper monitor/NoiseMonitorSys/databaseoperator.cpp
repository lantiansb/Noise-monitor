
#include "databaseoperator.h"

DatabaseOperator::DatabaseOperator(QObject *parent)
    : QObject{parent}
{
    this->db.setDatabaseName("NoiseDatabase.sqlite");
    if(!this->db.open())
    {
        QMessageBox::critical(NULL,
                              "数据库错误!",
                              "无法连接到本地数据库！",
                              QMessageBox::Ok);
    }
}

/** ***************************************************
 * @param
 *      const Qstring sql
 * @brief
 *      将sql语句写入初始化时建立好的数据库
 * ************************************************* **/
void DatabaseOperator::db_WriteSQL(const QString sql)
{
    this->query.prepare(sql);
    if(!this->query.exec())
    {
        QMessageBox::critical(NULL,
                              "数据库错误!",
                              "无法执行此命令(或查询为空)!",
                              QMessageBox::Ok);
    }
}

/** ***************************************************
 * @param
 *      const Qstring sql
 * @brief
 *      使用SQL语句进行查询,返回一个存储着数据的QSqlQuery
 * ************************************************* **/
QSqlQuery DatabaseOperator::db_SearchSQL(const QString sql)
{
    this->db_WriteSQL(sql);
    return this->query;
}
