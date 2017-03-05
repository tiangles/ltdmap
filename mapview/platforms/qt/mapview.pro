QT          += core gui opengl network widgets
TARGET      = ltd_mapview
TEMPLATE    = app
DESTDIR = ../../bin

TANGRAM_ES_ROOT = /media/btian/workspace/workspace/tangram-es.tangram.build
LIBS += -L$$TANGRAM_ES_ROOT/build/linux/lib \
        -L$$TANGRAM_ES_ROOT/build/qt/lib

LIBS += -ltangram
LIBS += -lduktape -lcss-color-parser-cpp -lyaml-cpp -lalfons -licucommon -lfreetype -lharfbuzz -llinebreak -lSQLiteCpp -lsqlite3
LIBS += -ldl -lrt -lm -lz -lX11 -lpthread -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lfreetype

INCLUDEPATH += ../../include \
                /media/btian/workspace/workspace/tangram-es.tangram.build/platforms/qt/src \
                /media/btian/workspace/workspace/tangram-es.tangram.build/core/include

HEADERS += ../../include/mapview.h \
    ../../include/geographic.h \
    ../../include/camera.h \
    ../../include/projection.h \
    ../../platforms/qt/mapviewimpl.h \
    ../../include/ltdtypes.h \
    ../../include/marker.h \
    ../../platforms/qt/markerimpl.h \
    ../../platforms/qt/projectionimpl.h \
    src/mapviewimpl.h \
    src/projectionimpl.h \
    src/markermpl.h

SOURCES += \
    ../../platforms/qt/src/main.cpp \
    ../../platforms/qt/src/mapviewimpl.cpp \
    ../../platforms/qt/src/camera.cpp \
    ../../platforms/qt/src/markermpl.cpp \
    ../../platforms/qt/src/projectionimpl.cpp
