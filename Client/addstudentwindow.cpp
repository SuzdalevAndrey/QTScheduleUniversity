#include "addstudentwindow.h"
#include "ui_addstudentwindow.h"

AddStudentWindow::AddStudentWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStudentWindow)
{
    ui->setupUi(this);
    connect(&SocketManager::instance(), &SocketManager::userListReceived, this, &AddStudentWindow::handleReceivedUserList);
    connect(&SocketManager::instance(), &SocketManager::registrationAnswer, this, &AddStudentWindow::handleReceivedRegistrationAnswer);
    connect(&SocketManager::instance(), &SocketManager::deleteUserAnswer, this, &AddStudentWindow::handleReceivedDeleteUsernAnswer);
    connect(this, &AddStudentWindow::closed, this, &QObject::deleteLater);
}

AddStudentWindow::~AddStudentWindow()
{
    delete ui;
}

void AddStudentWindow::handleReceivedUserList(const UserList &users)
{
    ui->UserListTextBrowser->clear();
    int count = 1;
    for(int i = 0; i<users.getUsers().size();++i){
        ui->UserListTextBrowser->append(QString::number(count++) + ") " + QString::number(users.getUsers()[i].getId())+ " " + users.getUsers()[i].getName()+ " " + users.getUsers()[i].getNameGroup());
    }
}

void AddStudentWindow::handleReceivedRegistrationAnswer(bool answer)
{
    if(answer)
        SocketManager::instance().sendUserListRequest();
    else
        QMessageBox::critical(this, "Ошибка","Такой номер студенческого уже есть!");
}

void AddStudentWindow::handleReceivedDeleteUsernAnswer(bool answer)
{
    if(answer)
        SocketManager::instance().sendUserListRequest();
    else
        QMessageBox::critical(this, "Ошибка","Такого студенческого номера нет!");
}

void AddStudentWindow::on_AddStudentPushButton_clicked()
{
    QString nameStudent = ui->NameLineEdit->text();
    QString numberStudentId = ui->NumberStudentIdLineEdit->text();
    if(nameStudent == "" || numberStudentId == ""){
        QMessageBox::critical(this, "Ошибка", "Не все поля заполнены!");
        return;
    }
    else{
        bool isNumber = false;
        numberStudentId.toInt(&isNumber);
        if(!isNumber){
            QMessageBox::critical(this, "Ошибка", "Номер студенческого должен быть числом!");
            return;
        }
        else{
            SocketManager::instance().registerUser(numberStudentId.toInt(), nameStudent);
            ui->NumberStudentIdLineEdit->clear();
            ui->NameLineEdit->clear();
        }
    }
}

void AddStudentWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
    QWidget::closeEvent(event);
}


void AddStudentWindow::on_DeleteStudentpushButton_clicked()
{
    QString numberStudentIdForDelete = ui->NumberStudentIdlForDeleteLineEdit->text();
    if(numberStudentIdForDelete == ""){
        QMessageBox::critical(this, "Ошибка", "Не все поля заполнены!");
        return;
    }
    else{
        bool isNumber = false;
        numberStudentIdForDelete.toInt(&isNumber);
        if(!isNumber){
            QMessageBox::critical(this, "Ошибка", "Номер студенческого должен быть числом!");
            return;
        }
        else{
            SocketManager::instance().deleteUser(numberStudentIdForDelete.toInt());
            ui->NumberStudentIdlForDeleteLineEdit->clear();
        }
    }
}

