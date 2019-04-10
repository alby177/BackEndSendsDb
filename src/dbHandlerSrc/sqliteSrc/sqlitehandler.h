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
    sqliteHandler();                                                                                            // Default class constructor
    sqliteHandler(const std::string &path);                                                                     // Class constructor
    ~sqliteHandler() override;                                                                                  // Class desstructor
    int open() override;                                                                                        // Open already inserted database
    int open(const std::string &path);                                                                          // Open database provided as argument
    int createTable(std::string table, std::vector<std::string> columns) override;                              // Create new table in the database
    int deleteTable(std::string table) override;                                                                // Delete a table
    int insertValues(std::string table, std::vector<std::string> values) override;                              // Insert values inside table
    int insertValues(std::string table, std::vector<std::string> columns, std::vector<std::string> values);     // Insert values under selected columns
    int showTableValues(std::string table, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr) override;                                       // Show all table values
    int showTableValues(std::string table, std::vector<std::string> columns, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr);              // Show selected columns values
    int close() override;                                                                                       // Close the database

private:

    // Methods
    int query(const std::string &query, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr) override; // Query database with std::string
    bool isNumber(std::string text);                                                                            // Check if text argument is a number
};

#endif // SQLITEHANDLER_H
