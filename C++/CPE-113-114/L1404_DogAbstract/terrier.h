#ifndef TERRIER_H
#define TERRIER_H
#include "dog.h"
#include <iostream>

using namespace std;

class Terrier : public Dog
{
    public:
        Terrier(string);
        virtual void greet();
};
#endif // TERRIER_H
