#ifndef HOLIDAYEMPLOYEE_H
#define HOLIDAYEMPLOYEE_H
#include "employee.h"

class HolidayEmployee : public Employee
{
    public:
        HolidayEmployee();
        HolidayEmployee(string n, double s, int m, int h);
        double calExtraTime();
        double calEarning();
    protected:
        int hours;
};
#endif
