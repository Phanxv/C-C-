#include "terrier.h"
#include <iostream>

using namespace std;

Terrier::Terrier(string n) : Dog(n)
{
    cout << " It's a Terrier." << endl;
}

void Terrier::greet()
{
    cout << "Ahoy Ahoy! My name is " << name << '.' << endl
         << " I'm a Terrier dog. Hunting rat is my job."
         << endl;
}
