#ifndef USERINFO_H
#define USERINFO_H

#include "basedata.h"
#include "qstring.h"

class UserInfo : public BaseData
{
public:
    UserInfo(const qint64& id = -1,const qint64& idGroup = -1, const QString& name = "", const QString& nameGroup = "");

    virtual QDataStream& toStream(QDataStream& stream) const override;
    virtual QDataStream& fromStream(QDataStream& stream) override;

    virtual DataType type()const override;

    void setUserName(const QString& name);
    void setUserId(const qint64& id);
    void setGroupId(const quint64& groupId);
    void setDataTypeNewUser();
    void setDataTypeDeleteUser();
    void setNameGroup(const QString& nameGroup);

    QString getName() const;
    qint64 getId() const;
    quint64 getIdGroup() const;
    bool getIsAdmin() const;
    QString getNameGroup()const;

    void makeAdmin();

    bool operator<(const UserInfo& right) const;
    bool operator==(const UserInfo& right) const;
private:
    QString name;
    qint64 id;
    quint64 idGroup;
    QString nameGroup;
    DataType dataType;
    bool isAdmin = false;
};

#endif // USERINFO_H
