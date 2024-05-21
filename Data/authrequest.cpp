#include "authrequest.h"


AuthRequest::AuthRequest(quint64 studentIdNumber, quint64 groupId, QString name):studentIdNumber(studentIdNumber),groupId(groupId),name(name)
{}

QDataStream &AuthRequest::toStream(QDataStream &stream) const
{
    stream<<studentIdNumber<<groupId<<name;
    return stream;
}

QDataStream &AuthRequest::fromStream(QDataStream &stream)
{
    stream>>studentIdNumber>>groupId>>name;
    return stream;
}
