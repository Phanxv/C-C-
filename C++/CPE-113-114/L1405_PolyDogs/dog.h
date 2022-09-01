#ifndef DOG_H
#define DOG_H
#include <string>

using namespace std;

class Dog
{
    public:
        Dog(string);
        virtual void greet() = 0;
        string name;
};
#endif
