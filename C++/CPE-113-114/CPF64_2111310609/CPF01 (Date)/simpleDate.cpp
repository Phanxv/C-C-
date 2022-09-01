#include "simpleDate.h"

simpleDate::simpleDate() : day(1), month(1) { }

simpleDate::simpleDate(int d, int m) : day(d<1||d>31?1:d), month(m>=1&&m<=12?m:1) { }

int simpleDate::getDay(){ return day; }

int simpleDate::getMonth(){ return month; }

string simpleDate::getString()
{
    if (day < 10)
        return NAME_OF_MONTHS[month-1] + ' ' + getDigit(day%10);

    return NAME_OF_MONTHS[month-1] + ' ' + getDigit(day/10) + getDigit(day%10);
}
