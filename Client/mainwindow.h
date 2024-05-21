#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include "editschedulewindow.h"
#include "../Data/scheduleforweek.h"
#include "../Data/userinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void handleReceivedSchedule(const ScheduleForWeek& schedule);
    void handleReceivedUserAuthenticated(const UserInfo& user);

private slots:

    void on_OpenLoginWindowPushButton_clicked();

    void on_AddStudentsPushButton_clicked();

    void on_EditSchedulePushButton_clicked();

private:
    bool isLogin = false;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
