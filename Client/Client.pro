QT       += core gui network testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudentwindow.cpp \
    editschedulewindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    schedulemanager.cpp \
    socketmanager.cpp \
    ..\Data\basedata.cpp\
    ..\Data\authanswer.cpp\
    ..\Data\authrequest.cpp\
    ..\Data\scheduleforday.cpp\
    ..\Data\scheduleforweek.cpp\
    ..\Data\userinfo.cpp \
    ..\Data\userlist.cpp

HEADERS += \
    addstudentwindow.h \
    editschedulewindow.h \
    loginwindow.h \
    mainwindow.h \
    schedulemanager.h \
    socketmanager.h \
    ..\Data\basedata.h\
    ..\Data\authanswer.h\
    ..\Data\authrequest.h\
    ..\Data\scheduleforday.h\
    ..\Data\scheduleforweek.h\
    ..\Data\userinfo.h \
    ..\Data\userlist.h

FORMS += \
    addstudentwindow.ui \
    editschedulewindow.ui \
    loginwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
