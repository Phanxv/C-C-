#ifndef ERROR_H
#define ERROR_H

#include <string>
using namespace std;

class error{
public :
    error(string);
    string getMessage();
private :
    string message;
};

#endif // ERROR_H
