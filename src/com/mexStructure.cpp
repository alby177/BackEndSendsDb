#include "mexStructure.h"
#include "constants.h"

mexStructure::mexStructure()
{

}

mexStructure::~mexStructure()
{
    // Destroy JSON message
    delete message;
}

void mexStructure::readArguments(char &&msg)
{
    // Save pointer to JSON message
    message = &msg;

    // Parse JSON message
    rapidjson::Document tmp;
    tmp.Parse(message);

    // Check for message
    if(message != nullptr)
    {
        // Save received parameters
        firstArg            = tmp[constants::FirstArg.c_str()].GetUint();
        length              = tmp[constants::Length.c_str()].GetUint();
        dbName              = tmp[constants::DbName.c_str()].GetString();
        mexType             = static_cast<mexTypes>(tmp[constants::OperationType.c_str()].GetInt());

        // Save reference to arguments array
        const rapidjson::Value& args = tmp[constants::Args.c_str()];

        // Access received array
        for (unsigned int i = firstArg; i < length; i++)

            // Save arguments inside message object
            mexArgs.push_back(args[i].GetString());

        // Update position for the arguments add
        firstArg += length;
    }
}

void mexStructure::addArguments(std::vector<std::string> &args)
{
    // Update array length
    length += args.size();

    // Create JSON message for new arguments
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    // Start the JSON object
    writer.StartObject();

    // Update necessary message parameters
    writer.Key(constants::FirstArg.c_str());
    writer.Uint(firstArg);
    writer.Key(constants::Length.c_str());
    writer.Uint(length);
    writer.Key(constants::Length.c_str());
    writer.Uint(length);
    writer.Key(constants::DbName.c_str());
    writer.String(dbName.c_str(), static_cast<unsigned int>(dbName.size()));
    writer.Key(constants::OperationType.c_str());
    writer.Int(mexType);

    // Start argument array
    writer.Key(constants::Args.c_str());
    writer.StartArray();

    // Add new arguments
    for (unsigned int i = 0; i < length; i++)
        writer.String(args[i].c_str(), static_cast<unsigned int>(args[i].size()));

    // End array data adding
    writer.EndArray(length);

    // End JSON object
    writer.EndObject();

    // Get string pointer
    message = (char *)(buffer.GetString());
}
