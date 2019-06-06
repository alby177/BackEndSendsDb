#include "mexStructure.h"
#include "constants.h"

#include <iostream>

MexStructure::MexStructure()
{

}

MexStructure::~MexStructure()
{

}

void MexStructure::ReadArguments(std::string &msg)
{
    // Save pointer to JSON message
    //mMessage = msg;

    // Parse JSON message
    rapidjson::Document tmp;
    tmp.Parse(msg.c_str());

    // Save received parameters
    mLength             = tmp[constants::Length.c_str()].GetUint();
    mDbName             = tmp[constants::DbName.c_str()].GetString();
    mMexType            = static_cast<mexTypes>(tmp[constants::OperationType.c_str()].GetInt());

    // Save reference to arguments array
    //const rapidjson::Value args = tmp[constants::Args.c_str()];

    // Access received array
    //for (unsigned int i = mFirstArg; i < mLength; i++)
    for (auto &v : tmp[constants::Args.c_str()].GetArray())
        // Save arguments inside message object

    {
        //mMexArgs.push_back(std::string(v.GetString()));
        std::cout << "Vector argument is: " << v.GetString() << std::endl;

        // Save argument inside arguments array
        mMexArgs.push_back(v.GetString());
    }

    // Update position for the arguments add
    mFirstArg += mLength;
}

void MexStructure::AddArguments(std::vector<std::string> &args)
{
    // Update array length
    mLength += args.size();

    // Create JSON message for new arguments
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    // Start the JSON object
    writer.StartObject();

    // Update necessary message parameters
    writer.Key(constants::Length.c_str());
    writer.Uint(mLength);

    writer.Key(constants::DbName.c_str());
    writer.String(mDbName.c_str(), static_cast<unsigned int>(mDbName.length()));

    writer.Key(constants::OperationType.c_str());
    writer.Int(mMexType);

    // Start argument array
    writer.Key(constants::Args.c_str());
    writer.StartArray();

    // Add new arguments
    for (unsigned int i = mFirstArg; i < mLength; i++)
    {
        writer.String(args[i].c_str(), static_cast<unsigned int>(args[i].length()));
    }

    // End array data adding
    writer.EndArray();

    // End JSON object
    writer.EndObject();

    // Get string pointer
    mMessage = static_cast<std::string>(buffer.GetString());
}
