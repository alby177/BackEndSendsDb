#ifndef MEXENGINE_H
#define MEXENGINE_H

#include "../../src/com/server/TcpServer.h"

class MexStructure;

class MexEngine
{
public:
    MexEngine();
    ~MexEngine();
    static void Communication(ServerStruct *serverData);
    static MexStructure mMessage;

//private:
    TcpServer      *mServer {nullptr};
};

#endif
