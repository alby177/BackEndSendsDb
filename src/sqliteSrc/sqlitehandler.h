#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include "sqlite3.h"
#include <string>
#include <vector>

typedef struct sqlite3 sqlite3;

class sqliteHandler
{
public:
    sqliteHandler();                                            // Default class constructor
    sqliteHandler(const std::string &path);                     // Class constructor
    ~sqliteHandler();                                           // Class desstructor
    void addDb(const std::string &path);                        // Add database path
    int open();                                                 // Open already inserted database
    int open(const std::string &path);                          // Open database provided as argument
    std::string getDbPath();                                    // Get database path
    std::vector<std::string> query(const std::string &query);   // Query database with std::string
    int close();                                                // Close the database

private:
    sqlite3 *db;                                                // Database object pointer
    std::string dbPath;                                         // Database path
};

#endif // SQLITEHANDLER_H
