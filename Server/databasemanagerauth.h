#ifndef DATABASEMANAGERAUTH_H
#define DATABASEMANAGERAUTH_H
#include <QtSql>
#include "../Data/userinfo.h"


class DataBaseManagerAuth
{
public:
    DataBaseManagerAuth();

    ~DataBaseManagerAuth();

    UserInfo getUserByStudentId(const quint64& studentId);

    bool registerUser(const int& studentId, const QString& userName, const int &groupId);

    bool userExists(const quint64& studentId);

    bool authenticateUser(const quint64& studentId);
private:
    // QSqlDatabase db;
};

#endif // DATABASEMANAGERAUTH_H
