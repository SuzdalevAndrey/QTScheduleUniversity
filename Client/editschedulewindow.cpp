#include "editschedulewindow.h"
#include "ui_editschedulewindow.h"

EditScheduleWindow::EditScheduleWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditScheduleWindow)
{
    ui->setupUi(this);
    QList<QString> DaysWeek{"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    ui->DayWeekComboBox->addItems(DaysWeek);
}

EditScheduleWindow::~EditScheduleWindow()
{
    delete ui;
}

void EditScheduleWindow::on_AddSubjectPushButton_clicked()
{
    QString nameSubject = ui->NameSubjectLineEdit->text();
    QString timeStart = ui->StartTimeEdit->text();
    QString timeEnd = ui->EndTimeEdit->text();
    QString numberAudience = ui->AudionceNumberLineEdit->text();
    if(nameSubject == "" || numberAudience == ""){
        QMessageBox::critical(this, "Ошибка", "Не все поля заполнены!");
    }
    else{
        bool isNumber = false;
        numberAudience.toInt(&isNumber);
        if(!isNumber){
            QMessageBox::critical(this, "Ошибка", "Номер аудитории должен быть числом!");
            return;
        }
        else{
            scheduleForDay.addSubject(Subject{-1, nameSubject, timeStart, timeEnd, numberAudience.toInt()});
            updateData();
            ui->NameSubjectLineEdit->clear();
            ui->AudionceNumberLineEdit->clear();
        }
    }
}


void EditScheduleWindow::on_SaveSchedulePushButton_clicked()
{
    SocketManager::instance().updateScheduleDay(scheduleForDay);
    this->close();
}


void EditScheduleWindow::on_DayWeekComboBox_currentTextChanged(const QString &arg1)
{
    ui->SubjectsTextBrowser->clear();
    scheduleForDay = ScheduleManager::instance().getScheduleForDayByNameDayWeek(arg1);
    updateData();
}


void EditScheduleWindow::on_DeleteSubjectPushButton_clicked()
{
    QString numberDelete = ui->NumberSubjectLineEdit->text();
    if(numberDelete == ""){
        QMessageBox::critical(this, "Ошибка", "Введите номер предмета для удаления!");
        return;
    }
    else{
        bool isNumber = false;
        numberDelete.toInt(&isNumber);
        if(!isNumber){
            QMessageBox::critical(this, "Ошибка", "Номер аудитории должен быть числом!");
            return;
        }
        scheduleForDay.remove((numberDelete.toInt() - 1));
        updateData();
        ui->NumberSubjectLineEdit->clear();
    }
}

void EditScheduleWindow::updateData()
{
    ui->SubjectsTextBrowser->clear();
    int count = 1;
    for(int i =0; i<scheduleForDay.getSubjects().size(); ++i){
        Subject subject;
        subject = scheduleForDay.getSubjects()[i];
        ui->SubjectsTextBrowser->append(QString::number(count++) + ") " + subject.name + " " + subject.timeStart+ " - " + subject.timeEnd + " "+ QString::number(subject.audienceNumber)+"ауд.");
    }
}

