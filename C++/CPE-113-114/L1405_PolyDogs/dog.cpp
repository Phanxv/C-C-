#include <iostream>
#include "dog.h"
#include <string>

using namespace std;

Dog::Dog(string n) : name(n)
{
    cout << "A dog is born." << endl;
}
