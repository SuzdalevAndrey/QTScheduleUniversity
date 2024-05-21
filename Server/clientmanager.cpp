#include "clientmanager.h"

ClientManager::ClientManager()
{}

ClientManager::~ClientManager()
{}

void ClientManager::addClient(const UserInfo &user, QTcpSocket *socket)
{
    clients.insert(user,socket);
}

void ClientManager::removeClient(const UserInfo &user)
{
    clients.remove(user);
}

void ClientManager::writeOneClient(const UserInfo &user, const BaseData &dataFrom)
{
    if (clients.contains(user)) {
        write(clients[user], dataFrom);
    }
}

ClientManager &ClientManager::instance()
{
    static ClientManager clientManager;
    return clientManager;
}

void ClientManager::writeLastClient(const BaseData &dataFrom)
{
    if(lastSocket){
        if(dataFrom.type() == DataType::AUTHRESPONSE){
            const AuthAnswer *answer = dynamic_cast<const AuthAnswer*>(&dataFrom);
            if(answer && answer->isAnswer())
                clients.insert(answer->getUser(), lastSocket);
        }
        write(lastSocket, dataFrom);
    }
}

void ClientManager::writeClientsByGroupId(const quint64& groupId, const BaseData &dataFrom)
{
    for(const auto& client : clients.keys()){
        if(client.getIdGroup() == groupId)
            writeOneClient(client, dataFrom);
    }
}

void ClientManager::setLastSocket(QTcpSocket *socket)
{
    lastSocket = socket;
}

void ClientManager::write(QTcpSocket *socket, const BaseData &dataFrom)
{
    QByteArray data;
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out<<dataFrom.type()<<dataFrom;
    socket->write(data);
}

void ClientManager::onClientDisconnection(QTcpSocket *disconnectionSocket)
{
    UserInfo client = clients.key(disconnectionSocket);
    removeClient(client);
}
