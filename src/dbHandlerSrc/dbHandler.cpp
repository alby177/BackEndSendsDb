#include "dbHandler.h"
#include <iostream>

dbHandler::dbHandler()
{

}

dbHandler::~dbHandler()
{

}

int dbHandler::open(const std::string &path, ErrStruct *err)
{
    // Save db file path
    dbPath = path;

    // Open db file
    return open(err);
}

void dbHandler::addDb(const std::string &path)
{
    // Save db file path
    dbPath = path;
}

std::string dbHandler::getDbPath() const
{
    // Get database path
    return dbPath;
}


