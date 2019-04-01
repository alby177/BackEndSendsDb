#ifndef DBHANDLER_H
#define DBHANDLER_H

#include <string>
#include <vector>

class dbHandler
{
public:
    dbHandler();                                                    // Default class constructor
    dbHandler(const std::string &path);                             // Class constructor
    virtual ~dbHandler();                                           // Class desstructor
    void addDb(const std::string &path);                                // Add database path
    std::string getDbPath();                                            // Get database path

protected:
    virtual int open() = 0;                                                 // Open already inserted database
    virtual int open(const std::string &path) = 0;                          // Open database provided as argument
    virtual std::vector<std::string> query(const std::string &query) = 0;   // Query database with std::string
    virtual int close() = 0;                                                // Close the database
    void *db = 0;                                                   // Database object pointer
    std::string dbPath;                                                 // Database path
};

#endif // DBHANDLER_H
