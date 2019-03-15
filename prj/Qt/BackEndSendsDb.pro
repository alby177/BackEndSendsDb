TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../src/main.cpp \
    ../../src/sqliteSrc/sqlite3.c \
    ../../src/sqliteSrc/sqlitehandler.cpp

HEADERS += \
    ../../src/sqliteSrc/sqlite3.h \
    ../../src/sqliteSrc/sqlitehandler.h
