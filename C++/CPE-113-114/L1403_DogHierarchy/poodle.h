#ifndef POODLE_H
#define POODLE_H
#include "dog.h"

class Poodle : public Dog
{
    public:
        Poodle(string);
        void greet();
};
#endif

