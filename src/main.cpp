#include <iostream>
#include <vector>
#include "dbHandlerSrc/sqliteSrc/sqlitehandler.h"

int main()
{
    sqliteHandler sqlDb;
    if (sqlDb.open("testDB.db") == -1)
        return -1;

    if (sqlDb.createTable("prova", {"id integer", "name text"}) == -1)
        return -1;

    if (sqlDb.insertValues("prova", {"12", "alberto"}) == -1)
        return -1;

    if (sqlDb.insertValues("prova", {"name"}, {"angelo", "francesco"}) == -1)
        return -1;

    auto dataVector = sqlDb.showTableValues("prova", {"name"});
    if (dataVector.size() != 0)
        for (auto &i: dataVector)
            std::cout << i << std::endl;

    if(sqlDb.deleteTable("prova") == -1)
        return -1;

    if (sqlDb.close() == -1)
        return -1;

    return 0;
}
