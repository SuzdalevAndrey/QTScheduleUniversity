#include "socketmanager.h"

SocketManager::SocketManager(){connectSocket();}

SocketManager &SocketManager::instance()
{
    static SocketManager socketManager;
    return socketManager;
}

void SocketManager::slotReadyRead()
{
    QDataStream data = QDataStream(socket);
    data.setVersion(QDataStream::Qt_6_2);
    if(data.status() == QDataStream::Ok){
        qDebug()<<"read...";
        qint8 type;
        data>>type;
        if(type == DataType::AUTHRESPONSE)
            readAuthAnswer(data);
        else if(type == DataType::SCHEDULEFORWEEKRESPONSE)
            readScheduleForWeek(data);
        else if(type == DataType::USERSLISTRESPONSE)
            readUsers(data);
        else if(type == DataType::REGISTERRESPONSE)
            readRegisterAnswer(data);
        else if(type == DataType::DELETEUSER)
            readDeleteUserAnswer(data);
    }
    else{
        qDebug()<<"QDataStream error";
    }
}

void SocketManager::connectSocket()
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &SocketManager::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    socket->connectToHost("127.0.0.1", 2323);
}

void SocketManager::sendScheduleRequest()
{
    ScheduleForWeek scheduleRequest;
    scheduleRequest.setRequest();
    scheduleRequest.setIdGroup(indificatorUser.getIdGroup());
    sendToServer(scheduleRequest);
}

void SocketManager::sendUserListRequest()
{
    UserList users;
    users.setUsersRequest();
    users.setGroupId(indificatorUser.getIdGroup());
    sendToServer(users);
}

void SocketManager::registerUser(const quint64 studentId, const QString &name)
{
    AuthRequest request(studentId, indificatorUser.getIdGroup(), name);
    request.setTypeRegisterRequest();
    sendToServer(request);
}

void SocketManager::autorizationUser(const quint64 studentId)
{
    AuthRequest request;
    request.setTypeAuthRequest();
    request.setStudentIdNumber(studentId);
    sendToServer(request);
}

void SocketManager::logout()
{
    emit socket->disconnected();
}

void SocketManager::deleteUser(const quint64 numberStudentId)
{
    UserInfo deleteUser;
    deleteUser.setDataTypeDeleteUser();
    deleteUser.setUserId(numberStudentId);
    sendToServer(deleteUser);
}

void SocketManager::saveScheduleDay(ScheduleForDay& scheduleForDay)
{
    scheduleForDay.setGroupId(indificatorUser.getIdGroup());
    scheduleForDay.setTypeAdd();
    sendToServer(scheduleForDay);
}

void SocketManager::updateScheduleDay(ScheduleForDay &scheduleForDay)
{
    scheduleForDay.setGroupId(indificatorUser.getIdGroup());
    scheduleForDay.setTypeUpdate();
    sendToServer(scheduleForDay);
}

void SocketManager::readAuthAnswer(QDataStream &data)
{
    AuthAnswer answer;
    data>>answer;
    if(answer.isAnswer()){
        // ClientsManager::instance().setCurrentUser(answer.getUser());
        // emit userAuthenticated(ClientsManager::instance().getCurrentUser().getName());
        indificatorUser = answer.getUser();
        // qDebug()<<"indificatorUser:"<<indificatorUser.getName()<<indificatorUser.getId()<<indificatorUser.getIdGroup()<<indificatorUser.getNameGroup();
        emit userAuthenticated(answer.getUser());
        sendScheduleRequest();
    }
    else
        emit userAuthenticationFailed();
}

void SocketManager::readRegisterAnswer(QDataStream &data)
{
    AuthAnswer answer;
    data>>answer;
    emit registrationAnswer(answer.isAnswer());
}

void SocketManager::readScheduleForWeek(QDataStream &data)
{
    ScheduleForWeek schedule;
    data>>schedule;
    ScheduleManager::instance().setScheduleForWeek(schedule);
    // qDebug()<<"Schedule:";
    // for(int i = 0; i < schedule.getScheduleForWeek().size(); ++i){
    //     qDebug()<<schedule.getScheduleForWeek()[i].getNameDayWeek();
    //     for(int j = 0; j < schedule.getScheduleForWeek()[i].getSubjects().size();++j){
    //         Subject subjectDay = schedule.getScheduleForWeek()[i].getSubjects()[j];
    //         qDebug()<<subjectDay.name+" "+subjectDay.timeStart+" "+subjectDay.timeEnd+" "+QString::number(subjectDay.audienceNumber);
    //     }
    // }
    emit scheduleForWeekReceived(schedule);
}

void SocketManager::readUsers(QDataStream &data)
{
    UserList users;
    data>>users;
    emit userListReceived(users);
}

void SocketManager::readDeleteUserAnswer(QDataStream &data)
{
    UserInfo user;
    data>>user;
    bool isDelete = false;
    if(user.getId() == 1)
        isDelete = true;
    else if(user.getId() == -1)
        isDelete = false;
    emit deleteUserAnswer(isDelete);
}

void SocketManager::sendToServer(const BaseData &dataToSend)
{
    QByteArray data;
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out<<dataToSend.type()<<dataToSend;
    socket->write(data);
}

SocketManager::~SocketManager()
{
    delete socket;
}
