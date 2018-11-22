QT += core
QT += gui widgets
QT       += opengl

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = form
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    openglviewer.cpp

HEADERS += \
    mainwindow.h \
    openglheader.h \
    openglviewer.h

FORMS    += mainwindow.ui


DESTDIR = bin

OBJECTS_DIR = ./OBJ_FILES
MOC_DIR = ./MOC_FILES


INCLUDEPATH += C:\\local\\OpenSceneGraph\\include

LIBS += -LC:\\local\\OpenSceneGraph\\lib \
        -lOpenThreads\
        -losg\
        -losgDB\
        -losgUtil\
        -losgViewer\
        -losgGA\
        -losgwTools

