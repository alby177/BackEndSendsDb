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

int sqliteHandler::query(const std::string &query, std::vector<std::string> *retVec, ErrStruct *err)
{
    // Reset query text
    if (retVec != nullptr)
        retVec->clear();

    // Compiled database statement handler
    sqlite3_stmt *dbStatement;

    // Prepare database query object
    int errCode = sqlite3_prepare_v2((struct sqlite3*) db, query.c_str(), static_cast<int>(query.size()), &dbStatement, nullptr);

    // Check for errors
    if(errCode != SQLITE_OK)
    {
        // Check for allocated error structure
        if (err != nullptr)
        {
            // Save error error
            *err << "Error translating the query to send to the database";
            *err << errCode;
        }

        // Destroy statement object
        sqlite3_finalize(dbStatement);

        // Return void vector
        return -1;
    }

    // Save number of columns
    int numCol = sqlite3_column_count(dbStatement);

    // Execute the query
    while ((errCode = sqlite3_step(dbStatement)) == SQLITE_ROW)
    {
        // String to populate
        std::string str;

        // Acquire data from all the database columns
        for (auto i = 0; i < numCol; ++i)
        {
            // Save data from table column
            const char *data = reinterpret_cast<const char*>(sqlite3_column_text(dbStatement, i));

            // Check for data
            if (data == nullptr)
                str.append("");
            else
                str.append(data);
            str += "|";
        }

        // Add new line
        if (retVec != nullptr)
            retVec->push_back(str);
    }

    // Check for errors
    if(errCode != SQLITE_DONE)
    {
        // Check for allocated error structure
        if (err != nullptr)
        {
            // Save error error
            *err << "Error sending the query to the database";
            *err << errCode;
        }

        // Destroy statement object
        sqlite3_finalize(dbStatement);

        // Return void vector
        return -1;
    }

    // Destroy statement object
    if (sqlite3_finalize(dbStatement) != SQLITE_OK)
    {
        // Check for allocated error structure
        if (err != nullptr)
        {
            // Save error error
            *err << "Error destroying query statement object";
            *err << errCode;
        }

        // Return error code
        return -1;
    }

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

int sqliteHandler::open(ErrStruct *err)
{
    // Check for db file path
    if (dbPath.size() == 0)
    {
        // Check for allocated error structure
        if(err != nullptr)
        {
            *err << "Invalid Database path inserted";
            *err << errCodInvPath;
        }
        return -1;
    }
    else if (dbPath.find(".db") == std::string::npos)
    {
        // Check for allocated error structure
        if(err != nullptr)
        {
            *err << "No database extension inserted";
            *err << errCodNoDbEx;
        }
        return -1;
    }

    // Open database
    int ret = sqlite3_open(dbPath.c_str(), (struct sqlite3**)&db);
    //int ret = sqlite3_open(dbPath.c_str(), static_cast<sqlite3**>(&db));

    // Check for errors
    if (ret != SQLITE_OK)
    {
        // Check for allocated error structure
        if(err != nullptr)
        {
            *err << "Error opening database " + dbPath;
            *err << errCodDbOpen;
        }
        return -1;
    }
    return 0;
}

int sqliteHandler::open(const std::string &path, ErrStruct *err)
{
    // Call base class open method
    return dbHandler::open(path, err);
}

int sqliteHandler::createTable(const std::string &table, const std::vector<std::string> &columns, ErrStruct *err)
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
    if (res != 0)
    {
        // Check for allocated error structure
        if(err != nullptr)
        {
            *err << "Cannot create table with name " + table + " inside database " + dbPath;
            *err << errCodTableCreate;
        }
    }
    return res;
}

int sqliteHandler::deleteTable(const std::string &table, ErrStruct *err)
{
    // Set basic delete table query command string
    std::string arg {"drop table if exists " + table + ";"};

    // Execute query
    int res = query(arg);
    if (res != 0)

    // Check for allocated error structure
    if(err != nullptr)
    {
        *err << "Cannot delete table with name " + table + " inside database " + dbPath;
        *err << errCodDeleteTable;
    }
    return res;
}

int sqliteHandler::insertValues(const std::string &table, const std::vector<std::string> &values, ErrStruct *err)
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

int sqliteHandler::insertValues(const std::string &table, const std::vector<std::string> &columns, const std::vector<std::string> &values, ErrStruct *err)
{
    // Set basic insert query command string
    std::string arg {"insert into " + table + " ("};

    // Add columns
    for (auto &i: columns)
    {
        arg += i;
        arg += ", ";
    }

    // Remove last comma and add values
    arg.erase(arg.length() - 2, 2) += std::string(") values ");

    // Add values
    for(auto &i : values)
    {
        arg += "(";

        // Check for text
        if (isNumber(i))
            arg += std::string(i);
        else
            arg += std::string("'" + i + "'");
        arg += "), ";
    }

    // Remove last comma and add closing parenthesis
    arg.erase(arg.length() - 2, 2) += std::string(";");

    // Execute query
    int res = query(arg);
    if (res == 0)
        std::cout << "Inserted values inside table with name " << table << " of database " << dbPath << std::endl;
    else
        std::cout << "Cannot insert values inside table with name " << table << " of database " << dbPath << std::endl;
    return res;
}

int sqliteHandler::showTableValues(const std::string &table, std::vector<std::string> *retVec, ErrStruct *err)
{
    // Prepare query argument
    std::string arg {"select * from " + table + ";"};

    // Execute query
    return query(arg, retVec, err);
}

int sqliteHandler::showTableValues(const std::string &table, const std::vector<std::string> &columns, std::vector<std::string> *retVec, ErrStruct *err)
{
    // Prepare query argument
    std::string arg {"select "};

    // Iterate on columns
    for (auto &i: columns)
    {
        // Add columns name
        arg += i;
        arg += ", ";
    }

    // Remove last comma and add closing parenthesis
    arg.erase(arg.length() - 2, 2) += std::string(" from ");

    // Add rest table and terminator
    arg += table;
    arg += ";";

    // Execute query
    return query(arg, retVec, err);
}

int sqliteHandler::close(ErrStruct *err)
{
    // Close the database
    int errCode = sqlite3_close_v2((struct sqlite3*) db);

    // Check for errors
    if (errCode != SQLITE_OK)
    {
        // Visualize error
        *err << "Error closing the database";
        *err << errCodeDbClose;

        // Return error flag
        return -1;
    }
    return 0;
}

