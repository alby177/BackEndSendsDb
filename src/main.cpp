#include <iostream>
#include "sqliteSrc/sqlite3.h"

typedef struct sqlite3 sqlite3;

int main()
{
    sqlite3 *db;
    sqlite3_open("testDb.db", &db);

    return 0;
}
