#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include "qtcpsocket.h"
#include "../Data/userinfo.h"
#include "../Data/basedata.h"
#include "../Data/authanswer.h"

class ClientManager
{
private:
    ClientManager();

    ~ClientManager();

    ClientManager(const ClientManager&) = delete;

    ClientManager& operator=(const ClientManager&) = delete;
public:
    void addClient(const UserInfo &user, QTcpSocket* socket);

    void removeClient(const UserInfo& user);

    void writeOneClient(const UserInfo& user, const BaseData& dataFrom);

    void writeLastClient(const BaseData& dataFrom);

    void writeClientsByGroupId(const quint64 &groupId, const BaseData& dataFrom);

    static ClientManager& instance();
private:
    friend class Server;

    void setLastSocket(QTcpSocket* socket);

    void write(QTcpSocket* socket, const BaseData& dataFrom);

    void onClientDisconnection(QTcpSocket* disconnectionSocket);

    QMap<UserInfo, QTcpSocket*> clients;

    QTcpSocket* lastSocket;

    // DataBaseManagerClients dataBaseManagerClients;
};

#endif // CLIENTMANAGER_H
