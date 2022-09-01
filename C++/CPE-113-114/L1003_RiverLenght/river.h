#ifndef RIVER_H
#define RIVER_H
#include <string>
using namespace std;
#include "length.h"
class River
{
    public:
        River();
        River(char*, int, int);
        void set(char*, int, int);
        void setName(char*);
        char* getName();
        Length getLength();
    private:
        char name[40];
        Length riverLength;
};
#endif
