#include "scheduleforday.h"

ScheduleForDay::ScheduleForDay() {}

void ScheduleForDay::addSubject(const Subject &subject)
{
    subjects.push_back(subject);
}

void ScheduleForDay::remove(const int &index)
{
    if(index>=0 && index<subjects.size())
        subjects.remove(index);
}

QDataStream &ScheduleForDay::toStream(QDataStream &stream) const
{
    int size = subjects.size();
    stream<<id<<groupId<<nameDayWeek<<size;
    for(const Subject& subject : subjects){
        stream<<subject.id<<subject.name<<subject.audienceNumber<<subject.timeStart<<subject.timeEnd;
    }
    return stream;
}

QDataStream &ScheduleForDay::fromStream(QDataStream &stream)
{
    int size = 0;
    stream>>id>>groupId>>nameDayWeek>>size;
    while(size){
        Subject subject;
        stream>>subject.id>>subject.name>>subject.audienceNumber>>subject.timeStart>>subject.timeEnd;
        subjects.push_back(subject);
        --size;
    }
    return stream;
}

DataType ScheduleForDay::type() const
{
    return dataType;
}

void ScheduleForDay::setTypeAdd()
{
    dataType = DataType::SCHEDULEFORDAYADD;
}

void ScheduleForDay::setTypeDelete()
{
    dataType = DataType::SCHEDULEFORDAYDELETE;
}

void ScheduleForDay::setTypeUpdate()
{
    dataType = DataType::SCHEDULEFORDAYEUPDATE;
}

void ScheduleForDay::setNameDayWeek(const QString &nameDayWeek)
{
    this->nameDayWeek = nameDayWeek;
}

void ScheduleForDay::setGroupId(const int &groupId)
{
    this->groupId = groupId;
}

void ScheduleForDay::setId(const int &id)
{
    this->id = id;
}

QString ScheduleForDay::getNameDayWeek() const
{
    return nameDayWeek;
}

int ScheduleForDay::getId() const
{
    return id;
}

int ScheduleForDay::getGroupId() const
{
    return groupId;
}

QVector<Subject> ScheduleForDay::getSubjects() const
{
    return subjects;
}
