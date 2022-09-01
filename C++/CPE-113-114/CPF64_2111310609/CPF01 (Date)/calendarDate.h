#ifndef CALENDARDATE_H
#define CALENDARDATE_H
#include <string>
#include "simpleDate.h"

using namespace std;

class calendarDate : public simpleDate
{
public :
    calendarDate();
    calendarDate(int y ,int d, int m);
    string getString();
private :
    int year;
};

#endif
