#ifndef BASEDATA_H
#define BASEDATA_H

#include "qtypes.h"
#include "qdatastream.h"

enum DataType : qint8
{
    AUTHREQUEST,
    AUTHRESPONSE,
    REGISTERREQUEST,
    REGISTERRESPONSE,
    NEWUSER,
    DELETEUSER,
    USERINFO,
    SCHEDULEFORDAYDELETE,
    SCHEDULEFORDAYADD,
    SCHEDULEFORDAYEUPDATE,
    SCHEDULEFORDAY,
    SCHEDULEFORWEEKREQUEST,
    SCHEDULEFORWEEKRESPONSE,
    USERSLISTRESPONSE,
    USERSLISTREQUEST
};

class BaseData
{
public:
    explicit BaseData() = default;

    friend QDataStream &operator >> (QDataStream &stream, BaseData &data);
    friend QDataStream &operator << (QDataStream &stream, const BaseData &data);

    virtual QDataStream& toStream(QDataStream &stream) const = 0;
    virtual QDataStream& fromStream(QDataStream &stream) = 0;
    virtual DataType type() const  = 0;

    virtual ~BaseData() = default;
};

QDataStream &operator >> (QDataStream &stream, BaseData &data);
QDataStream &operator << (QDataStream &stream, const BaseData &data);

#endif // BASEDATA_H
