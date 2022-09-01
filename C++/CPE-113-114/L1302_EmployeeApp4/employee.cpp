#include "employee.h"

Employee::Employee() : name("no name"), salary(0.0), months(0)
{}

Employee::Employee(string n, double s, int m) : name(n), salary(s), months(m)
{}

double Employee::calTotalSalary() const
{
    return( salary*months );
}

double Employee::calEarning() const
{
    return( 0.9*calTotalSalary() );
}
