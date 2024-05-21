#ifndef AUTHREQUEST_H
#define AUTHREQUEST_H

#include "basedata.h"
#include "qtypes.h"
#include "qstring.h"

class AuthRequest : public BaseData
{
public:
    AuthRequest(quint64 studentIdNumber = -1, quint64 groupId = -1, QString name = "");

    virtual QDataStream& toStream(QDataStream& stream) const override;
    virtual QDataStream& fromStream(QDataStream& stream) override;
    virtual DataType type()const override {return dataType;}

    void setUserName(const QString& name){this->name = name;}
    void setGroupId(const quint64& groupId){this->groupId = groupId;}
    void setStudentIdNumber(const quint64& studentIdNumber){this->studentIdNumber = studentIdNumber;}
    void setTypeAuthRequest() { dataType = DataType::AUTHREQUEST; }
    void setTypeRegisterRequest() { dataType = DataType::REGISTERREQUEST; }

    QString getName()const{return name;}
    quint64 getGroupId()const{return groupId;}
    quint64 getStudentIdNumber()const{return studentIdNumber;}

private:
    quint64 studentIdNumber;
    quint64 groupId;
    QString name;
    DataType dataType;
};

#endif // AUTHREQUEST_H
