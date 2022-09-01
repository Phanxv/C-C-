#ifndef POODLE_H
#define POODLE_H
#include "dog.h"

class Poodle : public Dog
{
    public:
        Poodle(string);
        /*void greet()
        {
            cout << "Hew Hew! My name is " << name << '.' << endl
                 << " I'm a poodle dog. I've a brown nose."
                 << endl;
        }*/
};
#endif
