#ifndef BULLTERRIER_H
#define BULLTERRIER_H
#include "terrier.h"
#include <iostream>

using namespace std;

class BullTerrier : public Terrier
{
    public:
        BullTerrier(string);
        virtual void greet();
};

#endif // BULLTERRIER_H
