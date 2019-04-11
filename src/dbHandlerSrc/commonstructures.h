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

enum ErroCodes
{
    errCodInvPath       = 1,                                            // Invalid database path
    errCodNoDbEx        = 2,                                            // No database extension provided
    errCodDbOpen        = 3,                                            // Error opening database
    errCodTableCreate   = 4,                                            // Error creating data table
    errCodDeleteTable   = 5,                                            // Error deleting table
    errCodeDbClose      = 6,                                            // Error closing the database
};

#endif // COMMONSTRUCTURES_H
