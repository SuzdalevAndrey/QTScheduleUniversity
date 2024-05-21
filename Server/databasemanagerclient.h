#ifndef DATABASEMANAGERCLIENT_H
#define DATABASEMANAGERCLIENT_H

#include "../Data/userlist.h"
#include "qtypes.h"
#include <QtSql>

class DataBaseManagerClient
{
public:
    DataBaseManagerClient();

    UserList getUsersByGroupId(const quint64& groupId);

    bool deleteUser(const quint64& numberStudentId);
};

#endif // DATABASEMANAGERCLIENT_H
