#include "userlist.h"

UserList::UserList() {}

UserList::UserList(const QList<UserInfo> &users):users(users)
{}

QDataStream& UserList::toStream(QDataStream &stream) const
{
    stream<<groupId;
    for (const auto &user : users) {
        stream << user;
    }
    return stream;
}

QDataStream& UserList::fromStream(QDataStream &stream)
{
    stream>>groupId;
    while(!stream.atEnd()){
        UserInfo user;
        stream>>user;
        users.push_back(user);
    }
    return stream;
}

DataType UserList::type() const
{
    return dataType;
}

void UserList::push_back(const UserInfo &user)
{
    users.push_back(user);
}

void UserList::remove(const UserInfo &user)
{
    for(int i = 0;i<users.size();++i){
        if(users[i] == user){
            users.remove(i);
            break;
        }
    }
}

void UserList::clear()
{
    users.clear();
}

UserInfo &UserList::operator[](int index)
{
    if(index>=0 && index<users.size())
        return users[index];
    throw std::out_of_range("Index no valid");
}

void UserList::setUsersResponse()
{
    dataType = DataType::USERSLISTRESPONSE;
}

void UserList::setUsersRequest()
{
    dataType = DataType::USERSLISTREQUEST;
}

void UserList::setGroupId(int groupId)
{
    this->groupId = groupId;
}

int UserList::getGroupId() const
{
    return this->groupId;
}

const QVector<UserInfo>& UserList::getUsers() const
{
    return users;
}
