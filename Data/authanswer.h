#ifndef AUTHANSWER_H
#define AUTHANSWER_H

#include "basedata.h"
#include "userinfo.h"

class AuthAnswer : public BaseData
{
public:
    AuthAnswer();

    virtual QDataStream& toStream(QDataStream &stream) const override;
    virtual QDataStream& fromStream(QDataStream &stream) override;
    virtual DataType type() const override;

    bool isAnswer()const;
    UserInfo getUser()const;

    void setAnswer(bool answer);
    void setUser(const UserInfo& user);

    void setLoginResponse();
    void setRegisterResponse();

private:
    bool answer;
    UserInfo user;
    DataType dataType;
};

#endif // AUTHANSWER_H
