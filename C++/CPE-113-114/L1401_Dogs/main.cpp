#include <iostream>
#include "dog.h"
#include "poodle.h"

using namespace std;

void testDog(Dog &);

int main()
{
    Dog chai("Chai Bangna");
    Poodle lucky("Lucky London");
    chai.greet();
    lucky.greet();
    cout << "\n-------------------------------------\n";
    Dog *pDog;
    Poodle *pPoodle;
    pDog = &chai;
    pPoodle = &lucky;
    pDog->greet();
    pPoodle->greet();
    pDog = &lucky;
    pDog->greet();
    cout << "\n-------------------------------------\n";
    testDog(chai);
    testDog(lucky);
    return 0;}

void testDog(Dog &rDog)
{
    rDog.greet();
}
