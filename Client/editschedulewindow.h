#ifndef EDITSCHEDULEWINDOW_H
#define EDITSCHEDULEWINDOW_H

#include <QDialog>
#include "qmessagebox.h"
#include "../Data/scheduleforday.h"
#include "socketmanager.h"
#include "schedulemanager.h"

namespace Ui {
class EditScheduleWindow;
}

class EditScheduleWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditScheduleWindow(QWidget *parent = nullptr);
    ~EditScheduleWindow();

private slots:
    void on_AddSubjectPushButton_clicked();

    void on_SaveSchedulePushButton_clicked();

    void on_DayWeekComboBox_currentTextChanged(const QString &arg1);

    void on_DeleteSubjectPushButton_clicked();

private:
    void updateData();

    Ui::EditScheduleWindow *ui;
    ScheduleForDay scheduleForDay;
};

#endif // EDITSCHEDULEWINDOW_H
