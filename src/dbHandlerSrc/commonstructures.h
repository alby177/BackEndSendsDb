#ifndef COMMONSTRUCTURES_H
#define COMMONSTRUCTURES_H
#include <string>

enum ErrorCodes
{
    errCodInvPath       = 1,                                            // Invalid database path
    errCodNoDbEx        = 2,                                            // No database extension provided
    errCodDbOpen        = 3,                                            // Error opening database
    errCodTableCreate   = 4,                                            // Error creating data table
    errCodDeleteTable   = 5,                                            // Error deleting table
    errCodeDbClose      = 6,                                            // Error closing the database
};

struct ErrStruct
{
public:
    void operator<< (const std::string &in) {errString = in;}
    void operator<< (const char *in) {errString = in;}
    void operator<< (int in) {errCode = in;}
    void operator << (const ErrorCodes &in) {errCode = in;}
    friend std::ostream &operator << (std::ostream &out, ErrStruct &err)
      {out << err.errString + ". Error code: " + std::to_string(static_cast<int>(err.errCode)); return out;}

private:
    int errCode;
    std::string errString;
};

#endif // COMMONSTRUCTURES_H
