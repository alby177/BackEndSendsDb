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

int sqliteHandler::query(const std::string &query)
{
    // Reset query text
    queryResult.clear();

    // Compiled database statement handler
    sqlite3_stmt *dbStatement;

    // Prepare database query object
    int errCode = sqlite3_prepare_v2((struct sqlite3*) db, query.c_str(), static_cast<int>(query.size()), &dbStatement, nullptr);

    // Check for errors
    if(errCode != SQLITE_OK)
    {
        // Print error
        std::cout << "Error translating the query to send to the database. Error code: " << errCode << std::endl;

        // Destroy statement object
        sqlite3_finalize(dbStatement);

        // Return void vector
        return -1;
    }

    // Save number of columns
    int numCol = sqlite3_column_count(dbStatement);

    // Return vector
    std::vector<std::string> retVet;

    // Execute the query
    while ((errCode = sqlite3_step(dbStatement)) == SQLITE_ROW)
    {
        // String to populate
        std::string str;

        // Acquire data from all the database columns
        for (auto i = 0; i < numCol; ++i)
        {
            str.append(reinterpret_cast<const char*>(sqlite3_column_text(dbStatement, i)));
            str += "|";
        }

        // Add new line
        retVet.push_back(str);
    }

    // Check for errors
    if(errCode != SQLITE_DONE)
    {
        // Print error
        std::cout << "Error sending the query to the database. Error code: " << errCode << std::endl;

        // Destroy statement object
        sqlite3_finalize(dbStatement);

        // Return void vector
        return -1;
    }

    // Destroy statement object
    if (sqlite3_finalize(dbStatement) != SQLITE_OK)
    {
        // Visualize error
        std::cout << "Error destroying query statement object. Error code: " << errCode << std::endl;

        // Return void vector
        return -1;
    }

    // Save text returned from query
    queryResult = retVet;

    // Return no error value
    return 0;
}

bool sqliteHandler::isNumber(std::string text)
{
    // Iterate on the string
    for (auto &i: text)
    {
        // Check for integers or floating
        if (!std::isdigit(i) && !(i == '.') && !(i == '-'))
            return false;
    }
    return true;
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
    int ret = sqlite3_open(dbPath.c_str(), (struct sqlite3**)&db);
    //int ret = sqlite3_open(dbPath.c_str(), static_cast<sqlite3**>(&db));

    // Check for errors
    if (ret != SQLITE_OK)
    {
        std::cout << "Error opening database " << dbPath << std::endl;
        return -1;
    }

    std::cout << "Opened database " << dbPath << std::endl;
    return 0;
}

int sqliteHandler::open(const std::string &path)
{
    // Call base class open method
    dbHandler::open(path);
}

int sqliteHandler::createTable(std::string table, std::vector<std::string> columns)
{
    // Set basic create table query command string
    std::string arg {"create table if not exists " + table + " ("};

    // Iterate on column passed as arguments
    for(auto &i : columns)
    {
        // Add column
        arg += i;
        arg += ", ";
    }

    // Remove last comma and add closing parenthesis
    arg.erase(arg.length() - 2, 2) += std::string(");");

    // Execute query
    int res = query(arg);
    if (res == 0)
        std::cout << "Created table with name " << table << " inside database " << dbPath << std::endl;
    else
        std::cout << "Cannot create table with name " << table << " inside database " << dbPath << std::endl;
    return res;
}

int sqliteHandler::deleteTable(std::string table)
{
    // Set basic delete table query command string
    std::string arg {"drop table if exists " + table + ";"};

    // Execute query
    int res = query(arg);
    if (res == 0)
        std::cout << "Deleted table with name " << table << " inside database " << dbPath << std::endl;
    else
        std::cout << "Cannot delete table with name " << table << " inside database " << dbPath << std::endl;
    return res;
}

int sqliteHandler::insertValues(std::string table, std::vector<std::string> values)
{
    // Set basic insert query command string
    std::string arg {"insert into " + table + " values ("};

    // Iterate on column passed as arguments
    for(auto &i : values)
    {
        // Check for text
        if (isNumber(i))
            arg += std::string(i);
        else
            arg += std::string("'" + i + "'");
        arg += ", ";
    }

    // Remove last comma and add closing parenthesis
    arg.erase(arg.length() - 2, 2) += std::string(");");

    // Execute query
    int res = query(arg);
    if (res == 0)
        std::cout << "Inserted values inside table with name " << table << " of database " << dbPath << std::endl;
    else
        std::cout << "Cannot insert values inside table with name " << table << " of database " << dbPath << std::endl;
    return res;
}

int sqliteHandler::insertValues(std::string table, std::vector<std::string> columns, std::vector<std::string> values)
{

}

std::vector<std::string> sqliteHandler::showTableValues(std::string table)
{
    // Prepare query argument
    std::string arg {"select * from " + table + ";"};

    // Execute query
    if (query(arg) != -1)

        // Return table values
        return queryResult;
    else
    {
      std::cout << "Error accessing data of table " << table << " of database " << dbPath << std::endl;
      return std::vector<std::string> {};
    }
}

int sqliteHandler::close()
{
    // Close the database
    int errCode = sqlite3_close_v2((struct sqlite3*) db);

    // Check for errors
    if (errCode != SQLITE_OK)
    {
        // Visualize error
        std::cout << "Error closing the database. Error code: " << errCode << std::endl;

        // Return void string
        return -1;
    }

    std::cout << "Closed database " << dbPath << std::endl;
    return 0;
}

