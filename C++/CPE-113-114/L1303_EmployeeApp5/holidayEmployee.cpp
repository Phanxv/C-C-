#include "holidayEmployee.h"

HolidayEmployee::HolidayEmployee() : hours(0)
{}

HolidayEmployee::HolidayEmployee(string n, double s, int m, int h) : hours(h)
{name = n; salary = s; months = m;}

double HolidayEmployee::calExtraTime()
{
    return( salary*hours*0.01 );
}

double HolidayEmployee::calEarning()
{
    return( Employee::calEarning() + 0.9*calExtraTime() );
}
