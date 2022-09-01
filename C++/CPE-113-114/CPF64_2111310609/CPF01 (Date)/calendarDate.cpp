#include "calendarDate.h"

calendarDate::calendarDate() : simpleDate(), year(2000) {}

calendarDate::calendarDate(int y ,int d, int m) : simpleDate(d,m), year(y<2000||y>2099?2000+y%100:y) {}

string calendarDate::getString()
{
    return (simpleDate::getString() + ", " + to_string(year));
}
