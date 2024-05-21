/********************************************************************************
** Form generated from reading UI file 'addstudentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTWINDOW_H
#define UI_ADDSTUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddStudentWindow
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QTextBrowser *UserListTextBrowser;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *NameLineEdit;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *NumberStudentIdLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AddStudentPushButton;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *NumberStudentIdlForDeleteLineEdit;
    QPushButton *DeleteStudentpushButton;

    void setupUi(QDialog *AddStudentWindow)
    {
        if (AddStudentWindow->objectName().isEmpty())
            AddStudentWindow->setObjectName("AddStudentWindow");
        AddStudentWindow->resize(514, 393);
        verticalLayout_7 = new QVBoxLayout(AddStudentWindow);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        label = new QLabel(AddStudentWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_4 = new QLabel(AddStudentWindow);
        label_4->setObjectName("label_4");
        QFont font1;
        font1.setPointSize(14);
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);

        UserListTextBrowser = new QTextBrowser(AddStudentWindow);
        UserListTextBrowser->setObjectName("UserListTextBrowser");
        QFont font2;
        font2.setPointSize(12);
        UserListTextBrowser->setFont(font2);

        verticalLayout_3->addWidget(UserListTextBrowser);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_5 = new QLabel(AddStudentWindow);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);

        verticalLayout_4->addWidget(label_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(AddStudentWindow);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        NameLineEdit = new QLineEdit(AddStudentWindow);
        NameLineEdit->setObjectName("NameLineEdit");

        verticalLayout_2->addWidget(NameLineEdit);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_3 = new QLabel(AddStudentWindow);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        NumberStudentIdLineEdit = new QLineEdit(AddStudentWindow);
        NumberStudentIdLineEdit->setObjectName("NumberStudentIdLineEdit");

        verticalLayout->addWidget(NumberStudentIdLineEdit);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        AddStudentPushButton = new QPushButton(AddStudentWindow);
        AddStudentPushButton->setObjectName("AddStudentPushButton");
        AddStudentPushButton->setFont(font2);

        horizontalLayout_3->addWidget(AddStudentPushButton);


        verticalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);

        label_6 = new QLabel(AddStudentWindow);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);

        verticalLayout_5->addWidget(label_6);

        label_7 = new QLabel(AddStudentWindow);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_7);

        NumberStudentIdlForDeleteLineEdit = new QLineEdit(AddStudentWindow);
        NumberStudentIdlForDeleteLineEdit->setObjectName("NumberStudentIdlForDeleteLineEdit");

        verticalLayout_5->addWidget(NumberStudentIdlForDeleteLineEdit);

        DeleteStudentpushButton = new QPushButton(AddStudentWindow);
        DeleteStudentpushButton->setObjectName("DeleteStudentpushButton");
        DeleteStudentpushButton->setFont(font2);

        verticalLayout_5->addWidget(DeleteStudentpushButton);


        verticalLayout_6->addLayout(verticalLayout_5);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_7->addLayout(horizontalLayout_2);


        retranslateUi(AddStudentWindow);

        QMetaObject::connectSlotsByName(AddStudentWindow);
    } // setupUi

    void retranslateUi(QDialog *AddStudentWindow)
    {
        AddStudentWindow->setWindowTitle(QCoreApplication::translate("AddStudentWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddStudentWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_4->setText(QCoreApplication::translate("AddStudentWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\262:", nullptr));
        label_5->setText(QCoreApplication::translate("AddStudentWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("AddStudentWindow", "\320\230\320\274\321\217 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_3->setText(QCoreApplication::translate("AddStudentWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\203\320\264\320\265\320\275\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\261\320\270\320\273\320\265\321\202\320\260:", nullptr));
        AddStudentPushButton->setText(QCoreApplication::translate("AddStudentWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("AddStudentWindow", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\260:", nullptr));
        label_7->setText(QCoreApplication::translate("AddStudentWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\203\320\264\320\265\320\275\321\207\320\265\321\201\320\272\320\276\320\263\320\276 \320\261\320\270\320\273\320\265\321\202\320\260:", nullptr));
        DeleteStudentpushButton->setText(QCoreApplication::translate("AddStudentWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudentWindow: public Ui_AddStudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTWINDOW_H
