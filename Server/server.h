#ifndef SERVER_H
#define SERVER_H

#include "databasemanagerauth.h"
#include "databasemanagerschedule.h"
#include "qtcpserver.h"
#include "qtcpsocket.h"
#include "../Data/basedata.h"
#include "../Data/authrequest.h"
#include "../Data/userlist.h"
#include "databasemanagerclient.h"

class Server: public QTcpServer
{
    Q_OBJECT
public:
    Server();
    ~Server();
private:
    void processAction(QDataStream& data);

public slots:
    void incomingConnection(qintptr socketDescriptor);
    void slotReadyRead();
    void onClientDisconnection();

private:
    QTcpSocket* socket;
    DataBaseManagerSchedule dataBaseSchedule;
    DataBaseManagerAuth dataBaseAuth;
    DataBaseManagerClient dataBaseClient;
};

#endif // SERVER_H
