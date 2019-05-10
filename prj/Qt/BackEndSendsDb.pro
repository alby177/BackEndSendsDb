TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    ../../src/main.cpp \
    ../../src/dbHandlerSrc/dbHandler.cpp \
    ../../src/dbHandlerSrc/sqliteSrc/sqlitehandler.cpp \
    ../../src/dbHandlerSrc/sqliteSrc/sqlite3.c \
    ../../src/com/mexEngine.cpp \
    ../../src/com/mexStructure.cpp \
    ../../src/com/server/TcpServer.cpp

HEADERS += \
    ../../src/dbHandlerSrc/dbHandler.h \
    ../../src/dbHandlerSrc/sqliteSrc/sqlite3.h \
    ../../src/dbHandlerSrc/sqliteSrc/sqlitehandler.h \
    ../../src/dbHandlerSrc/commonstructures.h \
    ../../src/com/mexEngine.h \
    ../../src/com/mexStructure.h \
    ../../src/com/rapidjson/error/en.h \
    ../../src/com/rapidjson/error/error.h \
    ../../src/com/rapidjson/internal/biginteger.h \
    ../../src/com/rapidjson/internal/diyfp.h \
    ../../src/com/rapidjson/internal/dtoa.h \
    ../../src/com/rapidjson/internal/ieee754.h \
    ../../src/com/rapidjson/internal/itoa.h \
    ../../src/com/rapidjson/internal/meta.h \
    ../../src/com/rapidjson/internal/pow10.h \
    ../../src/com/rapidjson/internal/regex.h \
    ../../src/com/rapidjson/internal/stack.h \
    ../../src/com/rapidjson/internal/strfunc.h \
    ../../src/com/rapidjson/internal/strtod.h \
    ../../src/com/rapidjson/internal/swap.h \
    ../../src/com/rapidjson/msinttypes/inttypes.h \
    ../../src/com/rapidjson/msinttypes/stdint.h \
    ../../src/com/rapidjson/allocators.h \
    ../../src/com/rapidjson/cursorstreamwrapper.h \
    ../../src/com/rapidjson/document.h \
    ../../src/com/rapidjson/encodedstream.h \
    ../../src/com/rapidjson/encodings.h \
    ../../src/com/rapidjson/filereadstream.h \
    ../../src/com/rapidjson/filewritestream.h \
    ../../src/com/rapidjson/fwd.h \
    ../../src/com/rapidjson/istreamwrapper.h \
    ../../src/com/rapidjson/memorybuffer.h \
    ../../src/com/rapidjson/memorystream.h \
    ../../src/com/rapidjson/ostreamwrapper.h \
    ../../src/com/rapidjson/pointer.h \
    ../../src/com/rapidjson/prettywriter.h \
    ../../src/com/rapidjson/rapidjson.h \
    ../../src/com/rapidjson/reader.h \
    ../../src/com/rapidjson/schema.h \
    ../../src/com/rapidjson/stream.h \
    ../../src/com/rapidjson/stringbuffer.h \
    ../../src/com/rapidjson/writer.h \
    ../../src/com/mextypes.h \
    ../../src/com/constants.h \
    ../../src/com/server/TcpServer.h
