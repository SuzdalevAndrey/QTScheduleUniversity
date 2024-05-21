#ifndef SHEDULEMANAGER_H
#define SHEDULEMANAGER_H
#include "../Data/scheduleforweek.h"

class ScheduleManager
{
public:
    static ScheduleManager& instance();

    ScheduleForDay getScheduleForDayByNameDayWeek(const QString& nameDayWeek);

    void setScheduleForWeek(const ScheduleForWeek& scheduleForWeek);

    ScheduleForWeek getSchedule()const;
private:
    ScheduleManager();
    ~ScheduleManager();
    ScheduleManager(const ScheduleManager&) = delete;
    ScheduleManager& operator=(const ScheduleManager&) = delete;
    ScheduleForWeek scheduleForWeek;
};

#endif // SHEDULEMANAGER_H
