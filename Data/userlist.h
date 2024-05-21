#ifndef USERLIST_H
#define USERLIST_H

#include "basedata.h"
#include "userinfo.h"
#include "qvector.h"

class UserList : public BaseData
{
public:
    UserList();
    UserList(const QList<UserInfo> &users);

    virtual QDataStream &toStream(QDataStream &stream) const override;
    virtual QDataStream &fromStream(QDataStream &stream) override;
    virtual DataType type() const override;

    void push_back(const UserInfo& user);
    void remove(const UserInfo& user);
    void clear();
    UserInfo& operator[](int index);

    void setUsersResponse();
    void setUsersRequest();
    void setGroupId(int groupId);

    int getGroupId() const;

    const QVector<UserInfo>& getUsers()const;
private:
    int groupId;
    QVector<UserInfo> users;
    DataType dataType;
};

#endif // USERLIST_H
