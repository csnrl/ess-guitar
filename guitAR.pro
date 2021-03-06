#-------------------------------------------------
#
# Project created by QtCreator 2014-02-04T11:44:15
#
#-------------------------------------------------

QT += core gui opengl webkit network

TARGET = guitAR
TEMPLATE = app
CONFIG += release

INCLUDEPATH += $$_PRO_FILE_PWD_/metaioSDK/include

LIBS += \
    -L"$$_PRO_FILE_PWD_/metaioSDK/bin" \
    -lmetaioSDK \
    -lwinmm

SOURCES += \
    main.cpp \
    chord.cpp \
    training_metaio.cpp \
    datamanager.cpp \
    chordset.cpp \
    business.cpp \
    mainwindow.cpp

HEADERS += \
    chord.h \
    training_metaio.h \
    datamanager.h \
    chordset.h \
    business.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    Resources.qrc
