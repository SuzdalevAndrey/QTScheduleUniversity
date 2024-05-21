#include <QCoreApplication>
#include "databasemanagerschedule.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    // DataBaseManagerSchedule dataBase;
    // ScheduleForDay schedule;
    // schedule.setNameDayWeek("Вторник");
    // dataBase.insertScheduleDay(10, schedule);
    // schedule.setNameDayWeek("Среда");
    // dataBase.insertScheduleDay(10, schedule);
    // schedule.setNameDayWeek("Четверг");
    // dataBase.insertScheduleDay(10, schedule);
    // schedule.setNameDayWeek("Пятница");
    // dataBase.insertScheduleDay(10, schedule);
    // schedule.setNameDayWeek("Суббота");
    // dataBase.insertScheduleDay(10, schedule);
    // schedule.setNameDayWeek("Воскресенье");
    // dataBase.insertScheduleDay(10, schedule);
    // DataBaseManagerAuth dataBaseA;
    // dataBaseA.registerUser(2001, "Святослав", 10);
    // dataBaseA.registerUser(1002, "Валентин", 11);
    // dataBaseA.registerUser(1003, "Алексей", 11);
    // dataBaseA.registerUser(1005, "Владимир", 11);

    // ScheduleForWeek schedule;

    // ScheduleForDay scheduleForDay;

    // scheduleForDay.addSubject(Subject{0,"Математика", "11:00", "13:00", 6401});
    // scheduleForDay.addSubject(Subject{1,"Физика", "11:00", "13:00", 6401});
    // scheduleForDay.addSubject(Subject{2,"Физра", "11:00", "13:00", 5301});

    // scheduleForDay.setNameDayWeek("Понедельник");

    // schedule.setIdGroup(11);

    // schedule.addScheduleForDay(scheduleForDay);
    // ScheduleForDay scheduleForDay2;

    // scheduleForDay2.addSubject(Subject{0,"Математика", "11:00", "13:00", 6401});
    // scheduleForDay2.addSubject(Subject{1,"Физика", "11:00", "13:00", 6401});
    // scheduleForDay2.addSubject(Subject{2,"Физра", "11:00", "13:00", 5301});

    // scheduleForDay2.setNameDayWeek("Вторник");
    // schedule.addScheduleForDay(scheduleForDay2);

    // dataBase.insertSchedule("22-ИСТ-3", schedule);

    // ScheduleForWeek schedule = dataBase.getScheduleForWeekByIdGroup(11);

    // for(int i = 0; i < schedule.getScheduleForWeek().size(); ++i){
    //     qDebug()<<schedule.getScheduleForWeek()[i].getNameDayWeek();
    //     for(int j = 0; j < schedule.getScheduleForWeek()[i].getSubjects().size();++j){
    //         Subject subjectDay = schedule.getScheduleForWeek()[i].getSubjects()[j];
    //         qDebug()<<subjectDay.id<<" "<<subjectDay.name<<" "<<subjectDay.timeStart<<" "<<subjectDay.timeEnd<<" "<<subjectDay.audienceNumber;
    //     }
    // }

    return a.exec();
}
