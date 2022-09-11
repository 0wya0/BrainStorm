#-------------------------------------------------
#
# Project created by QtCreator 2022-08-15T20:34:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        login.cpp \
    register.cpp \
    communicate.cpp \
    brainstorm.cpp \
    myftp.cpp

HEADERS += \
        login.h \
    register.h \
    communicate.h \
    brainstorm.h \
    myftp.h \
    comm.h

FORMS += \
        login.ui \
    register.ui \
    brainstorm.ui

RESOURCES += \
    Res/pic.qrc

