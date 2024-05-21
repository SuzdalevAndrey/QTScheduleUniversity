#include "databasemanagerschedule.h"
#include "qdebug.h"

DataBaseManagerSchedule::DataBaseManagerSchedule()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if (!db.open()) {
        qDebug() << "Failed to connect to database!";
    }
}

DataBaseManagerSchedule::~DataBaseManagerSchedule()
{
    db.close();
}

void DataBaseManagerSchedule::insertSchedule(const QString& nameGroup, const ScheduleForWeek &schedule)
{
    QSqlQuery query;

    query.prepare("INSERT INTO groups (id, name) VALUES (:id, :name)");
    query.bindValue(":id", schedule.getIdGroup());
    query.bindValue(":name", nameGroup);

    if (!query.exec()) {
        qDebug() << "Query execution failed:" << query.lastError().text();
        return;
    }

    query.prepare("INSERT INTO schedule (nameDayWeek, groupId) VALUES (:nameDayWeek, :groupId)");

    for (const auto& scheduleDay : schedule.getScheduleForWeek()) {
        query.bindValue(":nameDayWeek", scheduleDay.getNameDayWeek());
        query.bindValue(":groupId", schedule.getIdGroup());
        if (!query.exec()) {
            qDebug() << "Failed to add scheduleDay to schedule:" << query.lastError().text();
            return;
        }

        int idSchedule = query.lastInsertId().toInt();

        for(const auto& subject : scheduleDay.getSubjects()){
            QSqlQuery insertQuerySubject;
            insertQuerySubject.prepare("INSERT INTO subjects (name, timeStart, timeEnd, audienceNumber, idSchedule) VALUES (:name, :timeStart, :timeEnd, :audienceNumber, :idSchedule)");
            insertQuerySubject.bindValue(":name", subject.name);
            insertQuerySubject.bindValue(":timeStart", subject.timeStart);
            insertQuerySubject.bindValue(":timeEnd", subject.timeEnd);
            insertQuerySubject.bindValue(":audienceNumber", subject.audienceNumber);
            insertQuerySubject.bindValue(":idSchedule", idSchedule);
            if (!insertQuerySubject.exec()) {
                qDebug() << "Failed to add subject to subjects:" << insertQuerySubject.lastError().text();
                return;
            }
        }
    }
}

void DataBaseManagerSchedule::insertScheduleDay(const quint64 &groupId, const ScheduleForDay &scheduleforDay)
{
    QSqlQuery query;

    query.prepare("INSERT INTO schedule (nameDayWeek, groupId) VALUES (:nameDayWeek, :groupId)");

    query.bindValue(":nameDayWeek", scheduleforDay.getNameDayWeek());
    query.bindValue(":groupId", groupId);
    if (!query.exec()) {
        qDebug() << "Failed to add scheduleDay to schedule:" << query.lastError().text();
        return;
    }

    int idSchedule = query.lastInsertId().toInt();

    for(const auto& subject : scheduleforDay.getSubjects()){
        QSqlQuery insertQuerySubject;
        insertQuerySubject.prepare("INSERT INTO subjects (name, timeStart, timeEnd, audienceNumber, idSchedule) VALUES (:name, :timeStart, :timeEnd, :audienceNumber, :idSchedule)");
        insertQuerySubject.bindValue(":name", subject.name);
        insertQuerySubject.bindValue(":timeStart", subject.timeStart);
        insertQuerySubject.bindValue(":timeEnd", subject.timeEnd);
        insertQuerySubject.bindValue(":audienceNumber", subject.audienceNumber);
        insertQuerySubject.bindValue(":idSchedule", idSchedule);
        if (!insertQuerySubject.exec()) {
            qDebug() << "Failed to add subject to subjects:" << insertQuerySubject.lastError().text();
            return;
        }
    }
}

void DataBaseManagerSchedule::updateScheduleDay(const ScheduleForDay &scheduleForDay)
{
    QSqlQuery deleteQuery;
    deleteQuery.prepare("DELETE FROM subjects WHERE idSchedule = :idSchedule");
    deleteQuery.bindValue(":idSchedule", scheduleForDay.getId());

    if (!deleteQuery.exec()) {
        qDebug() << "Failed to delete subjects for schedule day:" << deleteQuery.lastError().text();
        return;
    }

    const QVector<Subject> subjects = scheduleForDay.getSubjects();
    for (const Subject &subject : subjects) {
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO subjects (name, timeStart, timeEnd, audienceNumber, idSchedule) "
                            "VALUES (:name, :timeStart, :timeEnd, :audienceNumber, :idSchedule)");
        insertQuery.bindValue(":name", subject.name);
        insertQuery.bindValue(":timeStart", subject.timeStart);
        insertQuery.bindValue(":timeEnd", subject.timeEnd);
        insertQuery.bindValue(":audienceNumber", subject.audienceNumber);
        insertQuery.bindValue(":idSchedule", scheduleForDay.getId());

        if (!insertQuery.exec()) {
            qDebug() << "Failed to insert subject:" << insertQuery.lastError().text();
            return;
        }
    }
}

ScheduleForWeek DataBaseManagerSchedule::getScheduleForWeekByIdGroup(const quint64 idGroup) const {
    ScheduleForWeek scheduleForWeek;

    QSqlQuery query;
    query.prepare("SELECT DISTINCT s.id, s.nameDayWeek FROM schedule s WHERE s.groupId = :idGroup");
    query.bindValue(":idGroup", idGroup);

    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return scheduleForWeek;
    }

    while (query.next()) {
        QString nameDayWeek = query.value(1).toString();
        quint64 id = query.value(0).toULongLong();

        ScheduleForDay scheduleForDay;
        scheduleForDay.setNameDayWeek(nameDayWeek);
        scheduleForDay.setId(id);

        QSqlQuery querySubjects;
        querySubjects.prepare("SELECT sb.id, sb.name, sb.timeStart, sb.timeEnd, sb.audienceNumber "
                              "FROM schedule s "
                              "JOIN subjects sb ON s.id = sb.idSchedule "
                              "WHERE s.groupId = :idGroup AND s.nameDayWeek = :nameDayWeek");
        querySubjects.bindValue(":idGroup", idGroup);
        querySubjects.bindValue(":nameDayWeek", nameDayWeek);

        if (!querySubjects.exec()) {
            qDebug() << "Ошибка выполнения запроса:" << querySubjects.lastError().text();
            continue;
        }

        while (querySubjects.next()) {
            quint64 id = querySubjects.value(0).toInt();
            QString subjectName = querySubjects.value(1).toString();
            QString timeStart = querySubjects.value(2).toString();
            QString timeEnd = querySubjects.value(3).toString();
            int numberAudit = querySubjects.value(4).toInt();

            Subject subject{static_cast<int>(id), subjectName, timeStart, timeEnd, numberAudit};
            scheduleForDay.addSubject(subject);
        }

        scheduleForWeek.addScheduleForDay(scheduleForDay);
    }

    return scheduleForWeek;
}
