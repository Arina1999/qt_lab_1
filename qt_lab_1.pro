QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

SOURCES += \
        FileManager.cpp \
        FileWatcher.cpp \
        main.cpp

HEADERS += \
    FileManager.h \
    FileWatcher.h

DEFINES += DIR=\\\"$$PWD\\\"
