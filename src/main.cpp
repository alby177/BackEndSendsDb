#include <iostream>
#include <vector>
#include "dbHandlerSrc/sqliteSrc/sqlitehandler.h"

int main()
{
    sqliteHandler sqlDb;
    if (sqlDb.open("testDB.db") == -1)
        std::cout << "Database opening error" << std::endl;
    else
        std::cout << "Database stored in " << sqlDb.getDbPath() << " opened" << std::endl;

    if (sqlDb.createTable("prova", {"id integer", "name text"}) == -1)
        return -1;

    if (sqlDb.insertValues("prova", {"12", "alberto"}) == -1)
        return -1;

    auto dataVector = sqlDb.showTableValues("prova");
    if (dataVector.size() != 0)
        for (auto &i: dataVector)
            std::cout << i << std::endl;

    if (sqlDb.close() == -1)
        return -1;

    std::cout << "Database closed correctly" << std::endl;

    return 0;
}
