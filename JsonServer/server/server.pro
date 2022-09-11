TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    thread.cpp \
    tcpserver.cpp \
    tcpsocket.cpp \
    myserver.cpp \
    db.cpp \
    user.cpp

HEADERS += \
    thread.h \
    tcpserver.h \
    tcpsocket.h \
    myserver.h \
    db.h \
    user.h \
    comm.h

LIBS += -L/usr/local/lib -levent -lpthread -lmysqlclient -ljson
