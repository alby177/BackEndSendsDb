#include <iostream>
#include "sqliteSrc/sqlitehandler.h"

int main()
{
    sqliteHandler sqlDb;
    if (sqlDb.open("/Users/albertogotta/Documents/sqlite-tools-osx-x86-3270200/testDb.db") == -1)
        std::cout << "Database opening error" << std::endl;
    else
        std::cout << "Database stored in " << sqlDb.getDbPath() << " opened" << std::endl;

    std::cout << sqlDb.query("select * from tbll");

    if (sqlDb.close() == -1)
        std::cout << "Database closing error" << std::endl;
    else
        std::cout << "Database closed correctly" << std::endl;

    return 0;
}
