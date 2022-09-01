#include "seniorEmployee.h"

SeniorEmployee::SeniorEmployee()
{}
SeniorEmployee::SeniorEmployee(string n,double s, int m)
{name = n; salary = s; months = m;}
double SeniorEmployee::calExtraWage()
{
    return static_cast<int>(months/3)*salary;
}

double SeniorEmployee::calEarning()
{
    return calExtraWage() + calTotalSalary();
}
