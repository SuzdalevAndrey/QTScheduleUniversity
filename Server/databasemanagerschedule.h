#ifndef DATABASEMANAGERSCHEDULE_H
#define DATABASEMANAGERSCHEDULE_H
#include "../Data/scheduleforweek.h"
#include <QtSql>

class DataBaseManagerSchedule
{
public:
    DataBaseManagerSchedule();

    ~DataBaseManagerSchedule();

    void insertSchedule(const QString& nameGroup, const ScheduleForWeek& schedule);

    void insertScheduleDay(const quint64& groupId, const ScheduleForDay& scheduleforDay);

    void updateScheduleDay(const ScheduleForDay& scheduleForDay);

    ScheduleForWeek getScheduleForWeekByIdGroup(const quint64 idGroup) const;
private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGERSCHEDULE_H
