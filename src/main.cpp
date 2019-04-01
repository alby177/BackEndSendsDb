#include <iostream>
#include "dbHandlerSrc/sqliteSrc/sqlitehandler.h"

int main()
{
    sqliteHandler sqlDb;
    if (sqlDb.open("testDB.db") == -1)
        std::cout << "Database opening error" << std::endl;
    else
        std::cout << "Database stored in " << sqlDb.getDbPath() << " opened" << std::endl;

    sqlDb.query("create table prova(one varchar(10), two smallint)");
    sqlDb.query("insert into prova values('ciao', 10)");
    sqlDb.query("insert into prova values('saluti', 20)");

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
