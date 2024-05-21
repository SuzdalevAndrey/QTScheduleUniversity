#ifndef SCHEDULEFORWEEK_H
#define SCHEDULEFORWEEK_H

#include "basedata.h"
#include "scheduleforday.h"

class ScheduleForWeek : public BaseData
{
public:
    ScheduleForWeek();

    virtual QDataStream &toStream(QDataStream &stream) const override;
    virtual QDataStream &fromStream(QDataStream &stream) override;
    virtual DataType type() const override;

    void addScheduleForDay(const ScheduleForDay& scheduleForDay);

    // void makeEven();
    // void makeOdd();

    void setResponse();
    void setRequest();
    void setIdGroup(quint64 idGroup);

    quint64 getIdGroup() const;
    QVector<ScheduleForDay> getScheduleForWeek() const;

    // int getParity() const;
private:
    QVector<ScheduleForDay> scheduleForWeek;
    // int parityWeek;
    quint64 idGroup;
    DataType dataType;
};

#endif // SCHEDULEFORWEEK_H
