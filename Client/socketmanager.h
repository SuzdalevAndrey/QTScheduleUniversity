#ifndef SOCKETMANAGER_H
#define SOCKETMANAGER_H

#include "qobject.h"
#include "qtcpsocket.h"
#include "../Data/basedata.h"
#include "../Data/scheduleforweek.h"
#include "../Data/userinfo.h"
#include "../Data/authrequest.h"
#include "../Data/authanswer.h"
#include "../Data/userlist.h"
#include "schedulemanager.h"

class SocketManager: public QObject
{
    Q_OBJECT;

public:
    static SocketManager& instance();

signals:
    void userAuthenticated(const UserInfo& user);
    void scheduleForWeekReceived(const ScheduleForWeek& message);
    void disconectionReceived();
    void userAuthenticationFailed();
    void userRegistration();
    void userRegistrationFailed();
    void userListReceived(const UserList& users);
    void registrationAnswer(bool answer);
    void deleteUserAnswer(bool answer);

public slots:
    void slotReadyRead();
    void connectSocket();
    void sendScheduleRequest();
    void sendUserListRequest();
    void registerUser(const quint64 studentId, const QString& name);
    void autorizationUser(const quint64 studentId);
    void logout();
    void deleteUser(const quint64 numberStudentId);
    void saveScheduleDay(ScheduleForDay &scheduleForDay);
    void updateScheduleDay(ScheduleForDay &scheduleForDay);

private:
    SocketManager();
    ~SocketManager();
    SocketManager(const SocketManager&) = delete;
    SocketManager& operator=(const SocketManager&) = delete;

    void readAuthAnswer(QDataStream& data);
    void readRegisterAnswer(QDataStream& data);
    void readScheduleForWeek(QDataStream& data);
    void readUsers(QDataStream& data);
    void readDeleteUserAnswer(QDataStream& data);

    void sendToServer(const BaseData& dataToSend);

    QTcpSocket *socket;
    UserInfo indificatorUser;
};

#endif // SOCKETMANAGER_H
