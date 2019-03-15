#include <iostream>
#include "sqliteSrc/sqlitehandler.h"

int main()
{
    sqliteHandler sqlDb;
    if (sqlDb.open("testDb.db") == -1)
        std::cout << "Database opening error" << std::endl;
    else
        std::cout << "Database stored in " << sqlDb.getDbPath() << " opened" << std::endl;

    return 0;
}
