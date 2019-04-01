#include "dbHandler.h"
#include <iostream>

dbHandler::dbHandler()
{
}

dbHandler::~dbHandler()
{
}

dbHandler::dbHandler(const std::string &path)
{
    // Save user path string
    dbPath = path;
}

int dbHandler::open(const std::string &path)
{
    // Save db file path
    dbPath = path;

    // Open db file
    return open();
}

void dbHandler::addDb(const std::string &path)
{
    // Save db file path
    dbPath = path;
}

std::string dbHandler::getDbPath()
{
    // Get database path
    return dbPath;
}


