#ifndef SIMPLEDATE_H
#define SIMPLEDATE_H
#include <string>

using namespace std;

const string NAME_OF_MONTHS[] =
    {"January", "Febuary", "March", "April", "May", "June",
     "July", "August", "September", "October", "November", "December"};

class simpleDate
{
public:
	simpleDate();
	simpleDate(int d, int m);

	int getDay();
	int getMonth();

    string getString();
protected:
    char getDigit(int digit) { return digit+'0'; }
	int day, month;
};

#endif // SIMPLEDATE_H
