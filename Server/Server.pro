QT = core network sql

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        clientmanager.cpp \
        databasemanagerauth.cpp \
        databasemanagerclient.cpp \
        databasemanagerschedule.cpp \
        main.cpp \
        server.cpp \
        ..\Data\basedata.cpp\
        ..\Data\authanswer.cpp\
        ..\Data\authrequest.cpp\
        ..\Data\scheduleforday.cpp\
        ..\Data\scheduleforweek.cpp\
        ..\Data\userinfo.cpp \
        ..\Data\userlist.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    clientmanager.h \
    databasemanagerauth.h \
    databasemanagerclient.h \
    databasemanagerschedule.h \
    server.h \
    ..\Data\basedata.h\
    ..\Data\authanswer.h\
    ..\Data\authrequest.h\
    ..\Data\scheduleforday.h\
    ..\Data\scheduleforweek.h\
    ..\Data\userinfo.h \
    ..\Data\userlist.h
