
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "dog.h"
#include "poodle.h"
#include "terrier.h"
#include "bullTerrier.h"

using namespace std;

void testDog(Dog &);

int main()
{
    srand(time(NULL));
    Dog *pDog[20];
    for(int i=0;i<20;++i)
    {
        switch(rand()%3)
        {
            case 0:
                pDog[i] = new Poodle("");
                break;
            case 1:
                pDog[i] = new Terrier("");
                break;
            case 2:
                pDog[i] = new BullTerrier("");
                break;
        }
    }
    cout << endl << endl;
    for(int i=0;i<20;++i)
    {
        pDog[i]->greet();
    }
    for (int i=0; i<20; ++i)
    {
        delete pDog[i];
        pDog[i] = NULL;
    }
    return 0;

}

void testDog(Dog &rDog)
{
    rDog.greet();
}
