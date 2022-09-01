#include <iostream>
#include <cstring>
#include <cmath> //ใช้ cstdlib แล้วเกิด overload ambigous จึงใช้ cmath ปทน
#include "length.h"
#include "river.h"

using namespace std;

int main()
{
    River centralRiver("Chao Phraya", 371, 850);
	River southRiver("Tapee", 232, 150);

	cout << centralRiver.getName() << " river is "
	     << centralRiver.getLength().getKilometre() << " km. and "
         << centralRiver.getLength().getMetre() << " m. long." << endl;
	cout << southRiver.getName() << " river is "
	     << southRiver.getLength().getKilometre() << " km. and "
         << southRiver.getLength().getMetre() << " m. long." << endl << endl;

   Length length_dif = southRiver.getLength() - centralRiver.getLength();
   double value_dif = abs(length_dif.getDecimal());

	cout << centralRiver.getName() << " river is " << value_dif << " km. "
	     << (centralRiver.getLength() < southRiver.getLength() ?
               "shorter" : "longer")
         << " than " << southRiver.getName() << " river." << endl;

    return 0;
}
