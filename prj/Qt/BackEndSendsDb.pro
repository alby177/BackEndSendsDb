TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../src/main.cpp \
    ../../src/dbHandlerSrc/dbHandler.cpp \
    ../../src/dbHandlerSrc/sqliteSrc/sqlitehandler.cpp \
    ../../src/dbHandlerSrc/sqliteSrc/sqlite3.c

HEADERS += \
    ../../src/dbHandlerSrc/dbHandler.h \
    ../../src/dbHandlerSrc/sqliteSrc/sqlite3.h \
    ../../src/dbHandlerSrc/sqliteSrc/sqlitehandler.h \
    ../../src/dbHandlerSrc/commonstructures.h
