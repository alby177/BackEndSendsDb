#include "sqlitehandler.h"
#include <iostream>

sqliteHandler::sqliteHandler()
{
}

sqliteHandler::sqliteHandler(const std::string &path)
{
    // Save user path string
    dbPath = path;
}


sqliteHandler::~sqliteHandler()
{
}

int sqliteHandler::open()
{
    // Check for db file path
    if (dbPath.size() == 0)
    {
        std::cout << "Error: Invalid Database path inserted" << std::endl;
        return -1;
    }
    else if (dbPath.find(".db") == std::string::npos)
    {
        std::cout << "Error: No database extension inserted" << std::endl;
        return -1;
    }

    // Open database
    int ret = sqlite3_open(dbPath.c_str(), &db);

    // Check for errors
    if (ret != SQLITE_OK)
        return -1;
    else
        return 0;
}

int sqliteHandler::open(const std::string &path)
{
    // Save db file path
    dbPath = path;

    // Open db file
    return open();
}

std::string sqliteHandler::getDbPath()
{
    // Get database path
    return dbPath;
}
