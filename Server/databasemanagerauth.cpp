#include "databasemanagerauth.h"

DataBaseManagerAuth::DataBaseManagerAuth()
{
    // db = QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("database.db");
    // if (!db.open()) {
    //     qDebug() << "Failed to connect to database!";
    // }
}

DataBaseManagerAuth::~DataBaseManagerAuth()
{
    // db.close();
}

UserInfo DataBaseManagerAuth::getUserByStudentId(const quint64 &studentId)
{
    QSqlQuery queryGetNameGroup;
    queryGetNameGroup.prepare("SELECT users.studentId, users.userName, users.groupId, users.isAdmin, groups.name "
                              "FROM users "
                              "JOIN groups ON users.groupId = groups.id "
                              "WHERE users.studentId = :studentId");
    queryGetNameGroup.bindValue(":studentId", studentId);

    if (!queryGetNameGroup.exec()) {
        qDebug() << "Query execution failed:" << queryGetNameGroup.lastError().text();
        return UserInfo();
    }

    if (queryGetNameGroup.next()) {
        UserInfo user = UserInfo(queryGetNameGroup.value(0).toInt(),
                                 queryGetNameGroup.value(2).toInt(),
                                 queryGetNameGroup.value(1).toString(),
                                 queryGetNameGroup.value(4).toString());
        if(queryGetNameGroup.value(3).toInt())
            user.makeAdmin();
        return user;
    } else {
        qDebug() << "No user found with studentId:" << studentId;
        return UserInfo();
    }
}

bool DataBaseManagerAuth::registerUser(const int &studentId, const QString &userName, const int &groupId)
{
    QSqlQuery query;

    query.prepare("INSERT INTO users (studentId, userName, groupId, isAdmin) VALUES (:studentId, :userName, :groupId, :isAdmin)");
    query.bindValue(":studentId", (int)studentId);
    query.bindValue(":userName", userName);
    query.bindValue(":groupId", (int)groupId);
    query.bindValue(":isAdmin", 0);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DataBaseManagerAuth::userExists(const quint64 &studentId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE studentId = :studentId");
    query.bindValue(":studentId", studentId);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();

    return count > 0;
}

bool DataBaseManagerAuth::authenticateUser(const quint64 &studentId)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM users WHERE studentId = :studentId");
    query.bindValue(":studentId", studentId);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();

    return count > 0;
}

