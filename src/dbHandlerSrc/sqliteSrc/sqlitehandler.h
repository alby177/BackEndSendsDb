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

    // Methods
    sqliteHandler();                                                    // Default class constructor
    sqliteHandler(const std::string &path);                             // Class constructor
    ~sqliteHandler();                                                   // Class desstructor
    int open() override;                                                         // Open already inserted database
    int open(const std::string &path);                                  // Open database provided as argument
    int createTable(std::string table, std::vector<std::string> columns) override;      // Create new table in the database
    int deleteTable(std::string table) override;
    int insertValues(std::string table, std::vector<std::string> values) override;
    int insertValues(std::string table, std::vector<std::string> columns, std::vector<std::string> values);
    std::vector<std::string> showTableValues(std::string table) override;
    int close() override;                                                        // Close the database

private:

    // Methods
    int query(const std::string &query);                                // Query database with std::string
    bool isNumber(std::string text);                                    // Check if text argument is a number

    // Members
    std::vector<std::string> queryResult;                               // Result generated from a query
};

#endif // SQLITEHANDLER_H
