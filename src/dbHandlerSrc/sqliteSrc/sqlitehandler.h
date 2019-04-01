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
    sqliteHandler();                                            // Default class constructor
    sqliteHandler(const std::string &path);                     // Class constructor
    ~sqliteHandler();                                           // Class desstructor
    int open();                                                 // Open already inserted database
    int open(const std::string &path);                          // Open database provided as argument
    std::vector<std::string> query(const std::string &query);   // Query database with std::string
    int close();                                                // Close the database
};

#endif // SQLITEHANDLER_H
