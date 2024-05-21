/********************************************************************************
** Form generated from reading UI file 'editschedulewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITSCHEDULEWINDOW_H
#define UI_EDITSCHEDULEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditScheduleWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *DayWeekComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *SubjectsTextBrowser;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *NumberSubjectLineEdit;
    QPushButton *DeleteSubjectPushButton;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QLineEdit *NameSubjectLineEdit;
    QLabel *label_5;
    QTimeEdit *StartTimeEdit;
    QLabel *label_6;
    QTimeEdit *EndTimeEdit;
    QLabel *label_7;
    QLineEdit *AudionceNumberLineEdit;
    QPushButton *AddSubjectPushButton;
    QPushButton *SaveSchedulePushButton;

    void setupUi(QDialog *EditScheduleWindow)
    {
        if (EditScheduleWindow->objectName().isEmpty())
            EditScheduleWindow->setObjectName("EditScheduleWindow");
        EditScheduleWindow->resize(600, 386);
        verticalLayout_3 = new QVBoxLayout(EditScheduleWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_2 = new QLabel(EditScheduleWindow);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(16);
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(EditScheduleWindow);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        DayWeekComboBox = new QComboBox(EditScheduleWindow);
        DayWeekComboBox->setObjectName("DayWeekComboBox");
        QFont font2;
        font2.setPointSize(12);
        DayWeekComboBox->setFont(font2);

        horizontalLayout->addWidget(DayWeekComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_3 = new QLabel(EditScheduleWindow);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        SubjectsTextBrowser = new QTextBrowser(EditScheduleWindow);
        SubjectsTextBrowser->setObjectName("SubjectsTextBrowser");
        SubjectsTextBrowser->setFont(font2);

        verticalLayout_2->addWidget(SubjectsTextBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        NumberSubjectLineEdit = new QLineEdit(EditScheduleWindow);
        NumberSubjectLineEdit->setObjectName("NumberSubjectLineEdit");

        horizontalLayout_2->addWidget(NumberSubjectLineEdit);

        DeleteSubjectPushButton = new QPushButton(EditScheduleWindow);
        DeleteSubjectPushButton->setObjectName("DeleteSubjectPushButton");
        DeleteSubjectPushButton->setFont(font2);

        horizontalLayout_2->addWidget(DeleteSubjectPushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(EditScheduleWindow);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        verticalLayout->addWidget(label_4);

        NameSubjectLineEdit = new QLineEdit(EditScheduleWindow);
        NameSubjectLineEdit->setObjectName("NameSubjectLineEdit");

        verticalLayout->addWidget(NameSubjectLineEdit);

        label_5 = new QLabel(EditScheduleWindow);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        StartTimeEdit = new QTimeEdit(EditScheduleWindow);
        StartTimeEdit->setObjectName("StartTimeEdit");

        verticalLayout->addWidget(StartTimeEdit);

        label_6 = new QLabel(EditScheduleWindow);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);

        verticalLayout->addWidget(label_6);

        EndTimeEdit = new QTimeEdit(EditScheduleWindow);
        EndTimeEdit->setObjectName("EndTimeEdit");

        verticalLayout->addWidget(EndTimeEdit);

        label_7 = new QLabel(EditScheduleWindow);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);

        verticalLayout->addWidget(label_7);

        AudionceNumberLineEdit = new QLineEdit(EditScheduleWindow);
        AudionceNumberLineEdit->setObjectName("AudionceNumberLineEdit");

        verticalLayout->addWidget(AudionceNumberLineEdit);

        AddSubjectPushButton = new QPushButton(EditScheduleWindow);
        AddSubjectPushButton->setObjectName("AddSubjectPushButton");
        AddSubjectPushButton->setFont(font2);

        verticalLayout->addWidget(AddSubjectPushButton);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        SaveSchedulePushButton = new QPushButton(EditScheduleWindow);
        SaveSchedulePushButton->setObjectName("SaveSchedulePushButton");
        SaveSchedulePushButton->setFont(font1);

        verticalLayout_3->addWidget(SaveSchedulePushButton);


        retranslateUi(EditScheduleWindow);

        QMetaObject::connectSlotsByName(EditScheduleWindow);
    } // setupUi

    void retranslateUi(QDialog *EditScheduleWindow)
    {
        EditScheduleWindow->setWindowTitle(QCoreApplication::translate("EditScheduleWindow", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("EditScheduleWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\217:", nullptr));
        label->setText(QCoreApplication::translate("EditScheduleWindow", "\320\224\320\265\320\275\321\214 \320\275\320\265\320\264\320\265\320\273\320\270:", nullptr));
        label_3->setText(QCoreApplication::translate("EditScheduleWindow", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\321\200\320\265\320\264\320\274\320\265\321\202\320\260:", nullptr));
        DeleteSubjectPushButton->setText(QCoreApplication::translate("EditScheduleWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("EditScheduleWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_5->setText(QCoreApplication::translate("EditScheduleWindow", "\320\235\320\260\321\207\320\260\320\273\320\276 \320\277\320\260\321\200\321\213:", nullptr));
        label_6->setText(QCoreApplication::translate("EditScheduleWindow", "\320\232\320\276\320\275\320\265\321\206 \320\277\320\260\321\200\321\213:", nullptr));
        label_7->setText(QCoreApplication::translate("EditScheduleWindow", "\320\220\321\203\320\264\320\270\321\202\320\276\321\200\320\270\321\217:", nullptr));
        AddSubjectPushButton->setText(QCoreApplication::translate("EditScheduleWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        SaveSchedulePushButton->setText(QCoreApplication::translate("EditScheduleWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditScheduleWindow: public Ui_EditScheduleWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITSCHEDULEWINDOW_H
