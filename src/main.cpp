#include <iostream>
#include <vector>
#include "dbHandlerSrc/sqliteSrc/sqlitehandler.h"
#include "dbHandlerSrc/commonstructures.h"
#include "com/mexEngine.h"

int main()
{
    ErrStruct err;

    sqliteHandler sqlDb;
    if (sqlDb.open("testDB.db", &err) == -1)
    {
        std::cout << err << std::endl;
        return -1;
    }

    if (sqlDb.createTable("prova", {"id integer", "name text"}, &err) == -1)
    {
        std::cout << err << std::endl;
        return -1;
    }

    if (sqlDb.insertValues("prova", {"12", "alberto"}, &err) == -1)
    {
        std::cout << err << std::endl;
        return -1;
    }

    if (sqlDb.insertValues("prova", {"name"}, {"angelo", "francesco"}, &err) == -1)
    {
        std::cout << err << std::endl;
        return -1;
    }

    std::vector<std::string> retVec;
    if(sqlDb.showTableValues("prova", &retVec, &err))
    {
        std::cout << err << std::endl;
        return -1;
    }
    if (retVec.size() != 0)
        for (auto &i: retVec)
            std::cout << i << std::endl;

    if(sqlDb.deleteTable("prova", &err) == -1)
    {
        std::cout << err << std::endl;
        return -1;
    }

    if (sqlDb.close(&err) == -1)
    {
        std::cout << err << std::endl;
        return -1;
    }
    MexEngine engine;
    engine.mServer->WaitForServerEnd();

    return 0;
}
