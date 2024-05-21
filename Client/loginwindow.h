#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include "../Data/userinfo.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_LoginPushButton_clicked();

    void handleUserAuthenticated(const UserInfo &user);
    void handleUserAuthenticationFailed();
protected:
    void closeEvent(QCloseEvent *event) override;

signals:
    void loggedInSuccessfully(const UserInfo user);
    void closed();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
