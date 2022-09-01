#include "poodle.h"
#include <iostream>

using namespace std;

Poodle::Poodle(string n) : Dog(n)
{
    cout << " It's a poodle." << endl;
}

void Poodle::greet()
{
    cout << "Hew Hew! My name is " << name << '.' << endl
         << " I'm a poodle dog. I've a brown nose."
         << endl;
}
