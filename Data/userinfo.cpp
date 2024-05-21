#include "userinfo.h"

UserInfo::UserInfo(const qint64 &id, const qint64 &idGroup, const QString &name, const QString &nameGroup):name(name), id(id), idGroup(idGroup), nameGroup(nameGroup)
{}

QDataStream &UserInfo::toStream(QDataStream &stream) const
{
    stream<<id<<idGroup<<name<<nameGroup<<isAdmin;
    return stream;
}

QDataStream &UserInfo::fromStream(QDataStream &stream)
{
    stream>>id>>idGroup>>name>>nameGroup>>isAdmin;
    return stream;
}

DataType UserInfo::type() const
{
    return dataType;
}

void UserInfo::setUserName(const QString &name)
{
    this->name = name;
}

void UserInfo::setUserId(const qint64 &id)
{
    this->id = id;
}

void UserInfo::setGroupId(const quint64 &groupId)
{
    this->idGroup = groupId;
}

void UserInfo::setDataTypeNewUser()
{
    dataType = DataType::NEWUSER;
}

void UserInfo::setDataTypeDeleteUser()
{
    dataType = DataType::DELETEUSER;
}

void UserInfo::setNameGroup(const QString &nameGroup)
{
    this->nameGroup = nameGroup;
}

QString UserInfo::getName() const
{
    return name;
}

qint64 UserInfo::getId() const
{
    return id;
}

quint64 UserInfo::getIdGroup() const
{
    return idGroup;
}

bool UserInfo::getIsAdmin() const
{
    return isAdmin;
}

QString UserInfo::getNameGroup() const
{
    return nameGroup;
}

void UserInfo::makeAdmin()
{
    isAdmin = true;
}

bool UserInfo::operator<(const UserInfo &right) const
{
    return id<right.getId();
}

bool UserInfo::operator==(const UserInfo &right) const
{
    return id == right.getId();
}
