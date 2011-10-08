#-------------------------------------------------
#
# Project created by QtCreator 2011-10-08T18:13:41
#
#-------------------------------------------------

QT       += network xml

QT       -= gui

TARGET = LibQTube
TEMPLATE = lib

DEFINES += LIBQTUBE_LIBRARY

SOURCES += qtube.cpp \
    qtubeparser.cpp \
    qtube.h \
    LibQTube_global.h \
    tuberequester.cpp \
    category.cpp \
    user.cpp \
    video.cpp \
    keyword.cpp

HEADERS += qtube.h\
        LibQTube_global.h \
    video.h \
    category.h \
    retrievable.h \
    tuberequester.h \
    qtubeparser.h \
    user.h \
    keyword.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE8327AA5
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = LibQTube.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}




