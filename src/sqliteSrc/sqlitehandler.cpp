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

void sqliteHandler::addDb(const std::string &path)
{
    // Save db file path
    dbPath = path;
}

std::string sqliteHandler::getDbPath()
{
    // Get database path
    return dbPath;
}

std::string sqliteHandler::query(const std::string &query)
{
    // Compiled database statement handler
    sqlite3_stmt *dbStatement;

    // Prepare database query object
    int errCode = sqlite3_prepare_v2(db, query.c_str(), query.size(), &dbStatement, nullptr);

    // Check for errors
    if(errCode != SQLITE_OK)
    {
        // Print error
        std::cout << "Error translating the query to send to the database. Error code: " << errCode << std::endl;

        // Return void string
        return "";
    }

    // Execute the query
    do
    {
        errCode = sqlite3_step(dbStatement);
    }
    while (errCode == SQLITE_ROW);

    // Check for errors
    if(errCode != SQLITE_DONE)
    {
        // Print error
        std::cout << "Error sending the query to the database. Error code: " << errCode << std::endl;

        // Return void string
        return "";
    }

    // Return string
    std::string ret;




}

