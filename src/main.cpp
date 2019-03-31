#include <iostream>
#include "sqliteSrc/sqlitehandler.h"

int main()
{
    sqliteHandler sqlDb;
    if (sqlDb.open("testDB.db") == -1)
        std::cout << "Database opening error" << std::endl;
    else
        std::cout << "Database stored in " << sqlDb.getDbPath() << " opened" << std::endl;

    auto dataVector = sqlDb.query("select * from prova");
    if (dataVector.size() != 0)
        for (auto &i: dataVector)
            std::cout << i << std::endl;
    else
        std::cout << "No query data" << std::endl;

    if (sqlDb.close() == -1)
        std::cout << "Database closing error" << std::endl;
    else
        std::cout << "Database closed correctly" << std::endl;

    return 0;
}
