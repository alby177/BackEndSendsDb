#include "mexEngine.h"
#include "../../src/com/mexStructure.h"
#include <iostream>
#include <thread>

MexStructure MexEngine::mMessage;

MexEngine::MexEngine()
{
    // Create new server object instance
    mServer = new TcpServer;

    // Connect to server
    mServer->CreateSocket();

    // Set up function to run with clients
    mServer->AddClientFunction(&Communication);
}

MexEngine::~MexEngine()
{
    // Free heap memory
    delete mServer;
}

void MexEngine::Communication(ServerStruct *serverData)
{
    // Builòd message vector
    std::vector<std::string> args;
    args.push_back("0");
    args.push_back("1");
    args.push_back("Prova");
    args.push_back("NewTable");
    args.push_back("all");

    std::string clientMessage;

    MexEngine::mMessage.AddArguments(args);

    // Send Message vector
    TcpServer::Send(serverData, MexEngine::mMessage.mMessage);

    // Receive client data
    TcpServer::Receive(serverData, clientMessage);

    // Add message vector
    MexEngine::mMessage.ReadArguments(clientMessage.c_str());

    std::cout << MexEngine::mMessage.mFirstArg << std::endl;
    std::cout << MexEngine::mMessage.mLength << std::endl;
    std::cout << MexEngine::mMessage.mDbName << std::endl;
    for (auto &i : MexEngine::mMessage.mMexArgs)
        std::cout << i << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}
