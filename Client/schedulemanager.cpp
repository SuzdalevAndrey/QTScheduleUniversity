#include "schedulemanager.h"

ScheduleManager &ScheduleManager::instance()
{
    static ScheduleManager sheduleManager;
    return sheduleManager;
}

ScheduleForDay ScheduleManager::getScheduleForDayByNameDayWeek(const QString &nameDayWeek)
{
    for(int i = 0; i<scheduleForWeek.getScheduleForWeek().size(); ++i){
        if(scheduleForWeek.getScheduleForWeek()[i].getNameDayWeek() == nameDayWeek)
            return scheduleForWeek.getScheduleForWeek()[i];
    }
    return ScheduleForDay();
}

void ScheduleManager::setScheduleForWeek(const ScheduleForWeek &scheduleForWeek)
{
    this->scheduleForWeek = scheduleForWeek;
}

ScheduleForWeek ScheduleManager::getSchedule() const
{
    return scheduleForWeek;
}

ScheduleManager::ScheduleManager()
{}

ScheduleManager::~ScheduleManager()
{}


