#include <iostream>
#include <string>
#include "simpleDate.h"
#include "calendarDate.h"

using namespace std;

int main()
{
	simpleDate dt1, dt2(23, 2);

	cout << "Date 1 is " << dt1.getString() << endl;
	cout << "Date 2 is " << dt2.getString() << endl;

	calendarDate dt3, dt4(2015, 23, 2), dt5(875, 23, 2), dt6(9, 23, 2);

	cout << "Date 3 is " << dt3.getString() << endl;
	cout << "Date 4 is " << dt4.getString() << endl;
	cout << "Date 5 is " << dt5.getString() << endl;
	cout << "Date 6 is " << dt6.getString() << endl;

    return 0;
}

