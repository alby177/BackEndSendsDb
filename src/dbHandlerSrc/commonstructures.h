#ifndef COMMONSTRUCTURES_H
#define COMMONSTRUCTURES_H
#include <string>

struct ErrStruct
{
    int errCode;
    std::string errString;

public:
    void operator<< (const std::string &in) {errString = in;};
    void operator<< (const char *in) {errString = in;};
    void operator<< (int in) {errCode = in;};
};

#endif // COMMONSTRUCTURES_H
