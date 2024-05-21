#ifndef SCHEDULEINFO_H
#define SCHEDULEINFO_H

#include "basedata.h"
#include "qstring.h"
#include "qvector.h"

struct Subject {
    int id;
    QString name;
    QString timeStart;
    QString timeEnd;
    int audienceNumber;
};

class ScheduleForDay : public BaseData
{
public:
    ScheduleForDay();

    void addSubject(const Subject& subject);
    void remove(const int& index);

    virtual QDataStream &toStream(QDataStream &stream) const override;
    virtual QDataStream &fromStream(QDataStream &stream) override;
    virtual DataType type() const override;

    void setTypeAdd();
    void setTypeDelete();
    void setTypeUpdate();
    void setNameDayWeek(const QString& nameDayWeek);
    void setGroupId(const int& groupId);
    void setId(const int& id);

    QString getNameDayWeek() const;
    int getId() const;
    int getGroupId() const;
    QVector<Subject> getSubjects() const;
private:
    QVector<Subject> subjects;
    QString nameDayWeek;
    int id;
    int groupId;
    DataType dataType = DataType::SCHEDULEFORDAY;
};

#endif // SCHEDULEINFO_H
