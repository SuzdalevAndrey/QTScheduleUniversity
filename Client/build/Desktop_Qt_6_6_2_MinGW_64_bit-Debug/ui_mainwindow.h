/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *NameUserLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *StatusLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *NameGroupLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *OpenLoginWindowPushButton;
    QLabel *label;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *AddStudentsPushButton;
    QPushButton *EditSchedulePushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 500);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        NameUserLabel = new QLabel(centralwidget);
        NameUserLabel->setObjectName("NameUserLabel");
        QFont font;
        font.setPointSize(16);
        NameUserLabel->setFont(font);

        horizontalLayout->addWidget(NameUserLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        StatusLabel = new QLabel(centralwidget);
        StatusLabel->setObjectName("StatusLabel");
        StatusLabel->setFont(font);

        horizontalLayout->addWidget(StatusLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        NameGroupLabel = new QLabel(centralwidget);
        NameGroupLabel->setObjectName("NameGroupLabel");
        NameGroupLabel->setFont(font);

        horizontalLayout->addWidget(NameGroupLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OpenLoginWindowPushButton = new QPushButton(centralwidget);
        OpenLoginWindowPushButton->setObjectName("OpenLoginWindowPushButton");
        QFont font1;
        font1.setPointSize(12);
        OpenLoginWindowPushButton->setFont(font1);

        horizontalLayout->addWidget(OpenLoginWindowPushButton);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font);

        verticalLayout->addWidget(label);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setFont(font1);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        AddStudentsPushButton = new QPushButton(centralwidget);
        AddStudentsPushButton->setObjectName("AddStudentsPushButton");
        AddStudentsPushButton->setFont(font1);

        horizontalLayout_2->addWidget(AddStudentsPushButton);

        EditSchedulePushButton = new QPushButton(centralwidget);
        EditSchedulePushButton->setObjectName("EditSchedulePushButton");
        EditSchedulePushButton->setFont(font1);

        horizontalLayout_2->addWidget(EditSchedulePushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        NameUserLabel->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        StatusLabel->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        NameGroupLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        OpenLoginWindowPushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265:", nullptr));
        AddStudentsPushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202\321\213", nullptr));
        EditSchedulePushButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
