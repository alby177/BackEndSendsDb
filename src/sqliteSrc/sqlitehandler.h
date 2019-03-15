#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include "sqlite3.h"
#include <string>

typedef struct sqlite3 sqlite3;

class sqliteHandler
{
public:
    sqliteHandler();
    sqliteHandler(const std::string &path);
    ~sqliteHandler();
    int addDb(const std::string &path);
    int open();
    int open(const std::string &path);
    std::string getDbPath();

private:
    sqlite3 *db;
    std::string dbPath;
};

#endif // SQLITEHANDLER_H
