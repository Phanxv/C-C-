#include <iostream>
#include <cstdlib>
#include "lenght.h"
using namespace std;

void output( Length, char*);

int main()
{
	Length l1, l2(5, 250), l3(2, 1150);

	output(l1, "Length 1");
	output(l2, "Length 2");
	output(l3, "Length 3");

    l1.setAll(5, 1275);
	output(l1, "Length 1");

	l1 = Length();
	l2 = Length(2, 300);
	output(l1, "Length 1");
	output(l2, "Length 2");

	l3 = Length(7, 750);
	output(l3, "Length 3");

	return 0;
}

void output(Length l, char* word)
{
	cout << word << " is " << l.getKilometre()
	     << " km " << l.getMetre() << " m." << endl
	     << "It equal to " << l.getDecimal() << " km. or "
	     << l.getTotalMetre() << " m." << endl << endl;
}
