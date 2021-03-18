QT += core gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        FileManager.cpp \
        FileWatcher.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
    FileManager.h \
    FileWatcher.h \
    mainwindow.h

DEFINES += DIR=\\\"$$PWD\\\"

FORMS += \
    mainwindow.ui
