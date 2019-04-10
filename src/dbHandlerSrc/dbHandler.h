#ifndef DBHANDLER_H
#define DBHANDLER_H

#include "commonstructures.h"
#include <string>
#include <vector>

class dbHandler
{
public:
    void addDb(const std::string &path);                                                            // Add database path
    std::string getDbPath() const;                                                                        // Get database path


protected:
    int open(const std::string &path);                                                              // Open database provided as argument
    virtual int open() = 0;                                                                         // Open already inserted database
    virtual int query(const std::string &query, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr) = 0;      // Query database with std::string
    virtual int createTable(const std::string &table, const std::vector<std::string> &columns) = 0;               // Create new table in the database
    virtual int deleteTable(const std::string &table) = 0;                                                 // Delete table in the database
    virtual int insertValues(const std::string &table, const std::vector<std::string> &values) = 0;               // Insert values inside table
    virtual int showTableValues(const std::string &table, std::vector<std::string> *retVec = nullptr, errStruct *err = nullptr) = 0;                        // Show all table values
    virtual int close() = 0;                                                                        // Close the database
    void *db = nullptr;                                                                             // Database object pointer
    std::string dbPath;                                                                             // Database path
};

#endif // DBHANDLER_H
