#ifndef COMMONSTRUCTURES_H
#define COMMONSTRUCTURES_H
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "mextypes.h"
#include <vector>
#include <string>

class MexStructure
{
public:
    MexStructure();
    ~MexStructure();
    void ReadArguments(const char *msg);
    void AddArguments(std::vector<std::string> &args);
    const char *GetMessage() {return mMessage;}

//private:
    const char *mMessage = nullptr;
    unsigned int mFirstArg;
    unsigned int mLength;
    std::string mDbName;
    mexTypes mMexType;
    std::vector<std::string> mMexArgs;
};
#endif
