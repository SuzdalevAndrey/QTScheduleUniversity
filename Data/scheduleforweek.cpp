#include "scheduleforweek.h"

ScheduleForWeek::ScheduleForWeek() {}

QDataStream &ScheduleForWeek::toStream(QDataStream &stream) const
{
    int size = scheduleForWeek.size();
    stream<<idGroup<<size;
    for(const ScheduleForDay& schedule : scheduleForWeek)
        stream<<schedule;
    return stream;
}

QDataStream &ScheduleForWeek::fromStream(QDataStream &stream)
{
    int size = 0;
    stream>>idGroup>>size;
    while(size){
        ScheduleForDay schedule;
        stream>>schedule;
        scheduleForWeek.push_back(schedule);
        --size;
    }
    return stream;
}

DataType ScheduleForWeek::type() const
{
    return dataType;
}

void ScheduleForWeek::addScheduleForDay(const ScheduleForDay &scheduleForDay)
{
    this->scheduleForWeek.push_back(scheduleForDay);
}

// void ScheduleForWeek::makeEven()
// {
//     parityWeek = 2;
// }

// void ScheduleForWeek::makeOdd()
// {
//     parityWeek = 1;
// }

void ScheduleForWeek::setResponse()
{
    dataType = DataType::SCHEDULEFORWEEKRESPONSE;
}

void ScheduleForWeek::setRequest()
{
    dataType = DataType::SCHEDULEFORWEEKREQUEST;
}

void ScheduleForWeek::setIdGroup(quint64 idGroup)
{
    this->idGroup = idGroup;
}

quint64 ScheduleForWeek::getIdGroup() const
{
    return idGroup;
}

QVector<ScheduleForDay> ScheduleForWeek::getScheduleForWeek() const
{
    return scheduleForWeek;
}

// int ScheduleForWeek::getParity() const
// {
//     return parityWeek;
// }
