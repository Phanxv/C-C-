#include "poodle.h"
#include <iostream>

using namespace std;

Poodle::Poodle(string n) : Dog(n)
{
    cout << " It's a poodle." << endl;
}
