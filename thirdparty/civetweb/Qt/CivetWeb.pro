TEMPLATE = lib
QT       -= core gui

SOURCES += \
    ../src/md5.inl \
    ../src/mod_lua.inl \
    ../src/timer.inl \
    ../src/civetweb.c \
    ../src/CivetServer.cpp

HEADERS += \
    ../include/civetweb.h \
    ../include/CivetServer.h

INCLUDEPATH +=  \
    ../include/

win32 {
LIBS += -lws2_32
}

#DEFINES += USE_IPV6
#DEFINES += USE_WEBSOCKET
