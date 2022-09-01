#include <iostream>
#include <string>
#include "dog.h"
#include "poodle.h"
#include "terrier.h"
#include "bullTerrier.h"

using namespace std;

void testDog(Dog &);

int main()
{
    // Declare a derived-class object.
    Poodle lucky("Lucky London");
    // Declare a base-class pointer.
    Dog *pDog;
    // Point base-class pointer at derived-class object.
    // When call its function, which function will be
    // called, base-class or derived-class function?
    pDog = &lucky;
    pDog->greet();
    Terrier nui("Nui Ravii");
    pDog = &nui;
    pDog->greet();
    BullTerrier kim("Kim seoul");
    pDog = &kim;
    pDog->greet();
    cout << endl;
    // Pass objects by reference.
    testDog(lucky);
    testDog(nui);
    testDog(kim);
    cout << endl;
    //Dog chai("Chai Bangna");
    return 0;
}

void testDog(Dog &rDog)
{
    rDog.greet();
}
