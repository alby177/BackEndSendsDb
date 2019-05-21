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
                                MexStructure            ();
    virtual                    ~MexStructure            ();
    void                        ReadArguments           (std::string &msg);
    void                        AddArguments            (std::vector<std::string> &args);
    //const char *GetMessage() {return mMessage;}

//private:
    std::string                 mMessage                {""};
    unsigned int                mFirstArg               {0};
    unsigned int                mLength                 {0};
    std::string                 mDbName                 {""};
    mexTypes                    mMexType;
    std::vector<std::string>    mMexArgs;
};
#endif
