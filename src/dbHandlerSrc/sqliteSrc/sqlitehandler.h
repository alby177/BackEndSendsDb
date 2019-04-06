#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include "sqlite3.h"
#include "../dbHandler.h"
#include <string>
#include <vector>

typedef struct sqlite3 sqlite3;
class sqliteHandler: public dbHandler
{
public:
    sqliteHandler();                                                    // Default class constructor
    sqliteHandler(const std::string &path);                             // Class constructor
    ~sqliteHandler();                                                   // Class desstructor
    int open();                                                         // Open already inserted database
    int open(const std::string &path);                                  // Open database provided as argument
    int createTable(std::string tableName, std::vector<std::string> columns);      // Create new table in the database
    int insertValues(std::string table, std::vector<std::string> values);
    int insertValues(std::string table, std::vector<std::string> columns, std::vector<std::string> values);
    std::vector<std::string> showTableValues(std::string table);
    int close();                                                        // Close the database

private:
    std::vector<std::string> query(const std::string &query);           // Query database with std::string
    bool isNumber(std::string text);                                    // Check if text argument is a number
};

#endif // SQLITEHANDLER_H
