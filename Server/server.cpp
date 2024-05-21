#include "server.h"
#include "clientmanager.h"

Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323)){
        qDebug()<<"Start";
    }
    else{
        qDebug()<<"Server fail";
    }
}

Server::~Server()
{
    delete socket;
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead,this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &Server::onClientDisconnection);
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    ClientManager::instance().setLastSocket(socket);
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if(in.status() == QDataStream::Ok){
        qDebug()<<"read...";
        processAction(in);
    }
    else{
        qDebug()<<"QDataStream error";
    }
}

void Server::processAction(QDataStream &data)
{
    qint8 action;
    data>>action;
    qDebug()<<"processAction "<< action;
    if(action == DataType::SCHEDULEFORWEEKREQUEST){
        // ClientManager::instance().addClient(UserInfo(), socket);
        ScheduleForWeek schedule;
        data>>schedule;
        schedule = dataBaseSchedule.getScheduleForWeekByIdGroup(schedule.getIdGroup());
        schedule.setResponse();
        ClientManager::instance().writeLastClient(schedule);
    }
    else if(action == DataType::AUTHREQUEST){
        AuthRequest request;
        data>>request;
        AuthAnswer authAnswer;
        authAnswer.setLoginResponse();
        if(dataBaseAuth.authenticateUser(request.getStudentIdNumber())){
            authAnswer.setAnswer(true);
            UserInfo user = dataBaseAuth.getUserByStudentId(request.getStudentIdNumber());
            qDebug()<<user.getName()<<user.getNameGroup();
            authAnswer.setUser(user);
        }
        else
            authAnswer.setAnswer(false);
        ClientManager::instance().writeLastClient(authAnswer);
    }
    else if(action == DataType::USERSLISTREQUEST){
        UserList users;
        data>>users;
        users = dataBaseClient.getUsersByGroupId(users.getGroupId());
        users.setUsersResponse();
        ClientManager::instance().writeLastClient(users);
    }
    else if(action == DataType::REGISTERREQUEST){
        AuthRequest request;
        data>>request;
        bool isRegister= dataBaseAuth.registerUser(request.getStudentIdNumber(), request.getName(),request.getGroupId());
        AuthAnswer answer;
        answer.setAnswer(isRegister);
        answer.setRegisterResponse();
        ClientManager::instance().writeLastClient(answer);
    }
    else if(action == DataType::DELETEUSER){
        UserInfo deleteUser;
        data>>deleteUser;
        bool isDelete = dataBaseClient.deleteUser(deleteUser.getId());
        deleteUser.setDataTypeDeleteUser();
        if(isDelete)
            deleteUser.setUserId(1);
        else
            deleteUser.setUserId(-1);
        ClientManager::instance().writeLastClient(deleteUser);
    }
    else if(action == DataType::SCHEDULEFORDAYEUPDATE){
        ScheduleForDay scheduleForDay;
        data>>scheduleForDay;
        int groupId = scheduleForDay.getGroupId();
        dataBaseSchedule.updateScheduleDay(scheduleForDay);
        ScheduleForWeek schedule;
        schedule = dataBaseSchedule.getScheduleForWeekByIdGroup(groupId);
        schedule.setResponse();
        ClientManager::instance().writeClientsByGroupId(groupId, schedule);
    }
}

void Server::onClientDisconnection()
{
    auto disconnectedSocket = static_cast<QTcpSocket*>(sender());
}
