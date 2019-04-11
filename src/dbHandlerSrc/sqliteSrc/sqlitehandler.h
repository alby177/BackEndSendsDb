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
    int open(ErrStruct *err = nullptr);                                                                                        // Open already inserted database
    int open(const std::string &path, ErrStruct *err = nullptr);                                                                          // Open database provided as argument
    int createTable(const std::string &table, const std::vector<std::string> &columns, ErrStruct *err = nullptr);                              // Create new table in the database
    int deleteTable(const std::string &table, ErrStruct *err = nullptr);                                                                // Delete a table
    int insertValues(const std::string &table, const std::vector<std::string> &values, ErrStruct *err = nullptr);                              // Insert values inside table
    int insertValues(const std::string &table, const std::vector<std::string> &columns, const std::vector<std::string> &values, ErrStruct *err = nullptr);     // Insert values under selected columns
    int showTableValues(const std::string &table, std::vector<std::string> *retVec = nullptr, ErrStruct *err = nullptr);                                       // Show all table values
    int showTableValues(const std::string &table, const std::vector<std::string> &columns, std::vector<std::string> *retVec = nullptr, ErrStruct *err = nullptr);              // Show selected columns values
    int close(ErrStruct *err = nullptr);                                                                                       // Close the database

private:

    // Methods
    int query(const std::string &query, std::vector<std::string> *retVec = nullptr, ErrStruct *err = nullptr); // Query database with std::string
    bool isNumber(std::string text);                                                                            // Check if text argument is a number
};

#endif // SQLITEHANDLER_H
