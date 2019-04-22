#ifndef COMMONSTRUCTURES_H
#define COMMONSTRUCTURES_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "mextypes.h"
#include <vector>
#include <string>

class mexStructure
{
public:
    mexStructure();
    ~mexStructure();
    void readArguments(char &&msg);
    void addArguments(std::vector<std::string> &args);
    char *getMessage() {return message;}

private:
    char *message = nullptr;
    unsigned int firstArg;
    unsigned int length;
    std::string dbName;
    mexTypes mexType;
    std::vector<std::string> mexArgs;
};
#endif
