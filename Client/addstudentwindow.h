#ifndef ADDSTUDENTWINDOW_H
#define ADDSTUDENTWINDOW_H

#include <QDialog>
#include "socketmanager.h"
#include "../Data/userlist.h"
#include "qmessagebox.h"

namespace Ui {
class AddStudentWindow;
}

class AddStudentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentWindow(QWidget *parent = nullptr);
    ~AddStudentWindow();
private slots:
    void on_AddStudentPushButton_clicked();

    void on_DeleteStudentpushButton_clicked();

signals:
    void closed();
protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void handleReceivedUserList(const UserList& users);
    void handleReceivedRegistrationAnswer(bool answer);

    void handleReceivedDeleteUsernAnswer(bool answer);

private:
    Ui::AddStudentWindow *ui;
};

#endif // ADDSTUDENTWINDOW_H
