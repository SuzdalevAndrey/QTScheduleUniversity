#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "socketmanager.h"
#include "qmessagebox.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(&SocketManager::instance(), &SocketManager::userAuthenticated, this, &LoginWindow::handleUserAuthenticated);
    connect(&SocketManager::instance(), &SocketManager::userAuthenticationFailed, this, &LoginWindow::handleUserAuthenticationFailed);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginPushButton_clicked()
{
    if (ui->NumberStudentIdLineEdit->text() == "") {
        QMessageBox::critical(this, "Error", "Пожалуйста заполните номер студенческого билета!");
        return;
    }
    else{
        SocketManager::instance().autorizationUser(ui->NumberStudentIdLineEdit->text().toULongLong());
    }
}

void LoginWindow::handleUserAuthenticated(const UserInfo& user)
{
    QMessageBox::information(this, "Информация", "Вы успешно авторизовались!");
    emit loggedInSuccessfully(user);
    this->close();
}

void LoginWindow::handleUserAuthenticationFailed()
{
    QMessageBox::critical(this, "Ошибка", "Неверный номер студенческого билета!");
}

void LoginWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
    QWidget::closeEvent(event);
}

