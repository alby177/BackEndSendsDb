#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include "sqlite3.h"
#include "../dbHandler.h"
#include <string>
#include <vector>

class sqliteHandler: public dbHandler
{
public:

    // Methods
    sqliteHandler();                                                                                            // Default class constructor
    sqliteHandler(const std::string &path);                                                                     // Class constructor
    ~sqliteHandler();                                                                                  // Class desstructor
    int open();                                                                                        // Open already inserted database
    int open(const std::string &path);                                                                          // Open database provided as argument
    int createTable(const std::string &table, const std::vector<std::string> &columns);                              // Create new table in the database
    int deleteTable(const std::string &table);                                                                // Delete a table
    int insertValues(const std::string &table, const std::vector<std::string> &values);                              // Insert values inside table
    int insertValues(const std::string &table, const std::vector<std::string> &columns, const std::vector<std::string> &values);     // Insert values under selected columns
    int showTableValues(const std::string &table, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr);                                       // Show all table values
    int showTableValues(const std::string &table, const std::vector<std::string> &columns, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr);              // Show selected columns values
    int close();                                                                                       // Close the database

private:

    // Methods
    int query(const std::string &query, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr); // Query database with std::string
    bool isNumber(std::string text);                                                                            // Check if text argument is a number
};

#endif // SQLITEHANDLER_H
