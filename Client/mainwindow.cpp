#include "mainwindow.h"
#include "addstudentwindow.h"
#include "socketmanager.h"
#include "ui_mainwindow.h"

#include "../Data/scheduleforweek.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&SocketManager::instance(), &SocketManager::scheduleForWeekReceived, this, &MainWindow::handleReceivedSchedule);
    ui->AddStudentsPushButton->setVisible(false);
    ui->EditSchedulePushButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleReceivedSchedule(const ScheduleForWeek &schedule)
{
    ui->textBrowser->clear();
    for(int i = 0; i < schedule.getScheduleForWeek().size(); ++i){
        ui->textBrowser->append(schedule.getScheduleForWeek()[i].getNameDayWeek() + ":");
        qDebug()<<schedule.getScheduleForWeek()[i].getId();
        int count = 1;
        for(int j = 0; j < schedule.getScheduleForWeek()[i].getSubjects().size();++j){
            Subject subjectDay = schedule.getScheduleForWeek()[i].getSubjects()[j];
            ui->textBrowser->append("          " + QString::number(count++)+") " + subjectDay.name+" "+subjectDay.timeStart+" - "+subjectDay.timeEnd+" "+QString::number(subjectDay.audienceNumber)+"ауд.");
        }
    }
}

void MainWindow::handleReceivedUserAuthenticated(const UserInfo &user)
{
    ui->NameUserLabel->setText(user.getName());
    ui->NameGroupLabel->setText(user.getNameGroup());
    if(user.getIsAdmin()){
        ui->StatusLabel->setText("староста группы:");
        ui->AddStudentsPushButton->setVisible(true);
        ui->EditSchedulePushButton->setVisible(true);
    }
    else
        ui->StatusLabel->setText("студент группы:");
    ui->OpenLoginWindowPushButton->setText("Выйти");
    isLogin = true;
}

void MainWindow::on_OpenLoginWindowPushButton_clicked()
{
    if(!isLogin){
        LoginWindow* login = new LoginWindow();
        connect(login, &LoginWindow::loggedInSuccessfully, this, &MainWindow::handleReceivedUserAuthenticated);
        connect(login, &LoginWindow::closed, login, &QObject::deleteLater);
        login->show();
    }
    else{
        ui->textBrowser->clear();
        ui->NameUserLabel->clear();
        ui->NameGroupLabel->clear();
        ui->OpenLoginWindowPushButton->setText("Войти");
        isLogin = false;
        ui->StatusLabel->clear();
        ui->AddStudentsPushButton->setVisible(false);
        ui->EditSchedulePushButton->setVisible(false);
    }
}


void MainWindow::on_AddStudentsPushButton_clicked()
{
    AddStudentWindow* addStudentWindow = new AddStudentWindow();
    addStudentWindow->show();
    SocketManager::instance().sendUserListRequest();
}


void MainWindow::on_EditSchedulePushButton_clicked()
{
    EditScheduleWindow* editScheduleWindow = new EditScheduleWindow();
    editScheduleWindow->show();
}

