#include "databasemanagerclient.h"
#include "databasemanagerauth.h"

DataBaseManagerClient::DataBaseManagerClient() {}

UserList DataBaseManagerClient::getUsersByGroupId(const quint64 &groupId)
{
    UserList userList;

    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE users.groupId = :groupId");
    query.bindValue(":groupId", groupId);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return userList;
    }

    DataBaseManagerAuth dataBase;

    while (query.next()) {
        quint64 studentId = query.value(0).toUInt();
        UserInfo user = dataBase.getUserByStudentId(studentId);
        userList.push_back(user);
    }

    return userList;
}

bool DataBaseManagerClient::deleteUser(const quint64 &numberStudentId)
{
    QSqlQuery query;
    query.prepare("DELETE FROM users WHERE studentId = :studentId");
    query.bindValue(":studentId", numberStudentId);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return false;
    }

    int rowsAffected = query.numRowsAffected();
    if (rowsAffected == 0) {
        qDebug() << "No user found with studentId:" << numberStudentId;
        return false;
    }

    qDebug() << "User with studentId" << numberStudentId << "deleted successfully";
    return true;
}
