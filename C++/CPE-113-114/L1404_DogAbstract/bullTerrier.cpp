#include "bullTerrier.h"
#include <iostream>

using namespace std;

BullTerrier::BullTerrier(string n) : Terrier(n)
{
    cout << "  Specifically, it's a Bull Terrier." << endl;
}

void BullTerrier::greet()
{
    cout << "Yip Yip! My name is " << name << '.' << endl
         << " I'm a Bull Terrier dog. I have a bull face"
         << endl;
}
