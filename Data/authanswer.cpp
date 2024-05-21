#include "authanswer.h"

AuthAnswer::AuthAnswer() {}

QDataStream &AuthAnswer::toStream(QDataStream &stream) const
{
    stream<<answer<<user;
    return stream;
}

QDataStream &AuthAnswer::fromStream(QDataStream &stream)
{
    stream>>answer>>user;
    return stream;
}

DataType AuthAnswer::type() const
{
    return dataType;
}

bool AuthAnswer::isAnswer() const
{
    return answer;
}

UserInfo AuthAnswer::getUser() const
{
    return user;
}

void AuthAnswer::setAnswer(bool answer)
{
    this->answer = answer;
}

void AuthAnswer::setUser(const UserInfo& user)
{
    this->user = user;
}

void AuthAnswer::setLoginResponse()
{
    this->dataType = DataType::AUTHRESPONSE;
}

void AuthAnswer::setRegisterResponse()
{
    this->dataType = DataType::REGISTERRESPONSE;
}
