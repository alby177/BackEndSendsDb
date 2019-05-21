#include "mexEngine.h"
#include <iostream>
#include <thread>

MexEngine::MexEngine()
{
    // Create new server object instance
    mServer = new TcpServer;

    // Connect to server
    mServer->CreateSocket();

    // Set up function to run with clients
    mServer->AddClientFunction(&Communication, &mMessage);
}

MexEngine::~MexEngine()
{
    // Free heap memory
    delete mServer;
}

void Communication(ServerStruct *serverData)
{
    // Build message vector
    std::vector<std::string> args;
    args.push_back("0");
    args.push_back("1");
    args.push_back("Prova");
    args.push_back("2");
    args.push_back("all");

    std::string clientMessage;

    // Extract user data from server data
    MexStructure *message = static_cast<MexStructure*>(serverData->userData);

    // Save data
    message->mDbName = "DbProva";
    message->mMexType = createTable;

    // Add message arguments
    message->AddArguments(args);

    // Send Message vector
    TcpServer::Send(serverData, message->mMessage);

    // Receive client data
    TcpServer::Receive(serverData, clientMessage);

    // Add message vector
    message->ReadArguments(clientMessage);

    std::cout << message->mFirstArg << std::endl;
    std::cout << message->mLength << std::endl;
    std::cout << message->mDbName << std::endl;
    for (auto &i : message->mMexArgs)
        std::cout << i << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

