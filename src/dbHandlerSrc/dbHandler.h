#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <string>
#include <vector>

class dbHandler
{
public:
    dbHandler();                                                                                    // Default class constructor
    dbHandler(const std::string &path);                                                             // Class constructor
    virtual ~dbHandler();                                                                           // Class desstructor
    void addDb(const std::string &path);                                                            // Add database path
    std::string getDbPath();                                                                        // Get database path

protected:
    virtual int open() = 0;                                                                         // Open already inserted database
    virtual int open(const std::string &path) = 0;                                                  // Open database provided as argument
    virtual std::vector<std::string> query(const std::string &query) = 0;                           // Query database with std::string
    virtual int createTable(std::string tableName, std::vector<std::string> columns) = 0;           // Create new table in the database
    virtual int insertValues(std::string table, std::vector<std::string> values) = 0;               // Insert values inside table
    virtual std::vector<std::string> showTableValues(std::string table) = 0;                        // Show all table values
    virtual int close() = 0;                                                                        // Close the database
    void *db = nullptr;                                                                             // Database object pointer
    std::string dbPath;                                                                             // Database path
};

#endif // DBHANDLER_H
