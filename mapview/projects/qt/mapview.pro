QT          += core gui opengl network widgets
TARGET      = ltd_mapview
TEMPLATE    = app
DESTDIR = ../../bin

TANGRAM_ES_ROOT = ../../../../tangram-es
LIBS += -L$$TANGRAM_ES_ROOT/build/linux/lib \
        -L$$TANGRAM_ES_ROOT/build/qt/lib
LIBS += -ltangram
LIBS += -ldl -lrt -lm -ldl -lX11 -lpthread -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor -lGL
LIBS += -lduktape -lcss-color-parser-cpp -lgeojson-vt-cpp -lyaml-cpp -lalfons -licucommon -lfreetype -lharfbuzz -llinebreak

INCLUDEPATH += ../../include \
                $$TANGRAM_ES_ROOT/qt/src \
                $$TANGRAM_ES_ROOT/core/src

HEADERS += ../../include/mapview.h \
    ../../include/geographic.h \
    ../../include/camera.h \
    ../../include/projection.h \
    ../../platforms/qt/mapviewimpl.h \
    ../../include/ltdtypes.h \
    ../../include/marker.h \
    ../../platforms/qt/markerimpl.h

SOURCES += \
    ../../platforms/qt/mapviewimpl.cpp \
    ../../platforms/qt/main.cpp \
    ../../platforms/qt/camera.cpp \
    ../../platforms/qt/markermpl.cpp
