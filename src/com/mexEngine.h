#ifndef MEXENGINE_H
#define MEXENGINE_H

#include "../../src/com/server/TcpServer.h"
#include "../../src/com/mexStructure.h"

class MexStructure;

class MexEngine
{
public:
    MexEngine();
    ~MexEngine();
    //void Communication(ServerStruct *serverData);
    MexStructure   *mMessage  {nullptr};

//private:
    TcpServer      *mServer {nullptr};
};

void Communication(ServerStruct *serverData);
#endif
