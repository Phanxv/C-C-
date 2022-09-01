#ifndef SENIOREMPLOYEE_H
#define SENIOREMPLOYEE_H
#include "employee.h"

class SeniorEmployee : public Employee
{
    public:
        SeniorEmployee();
        SeniorEmployee(string ,double, int);
        double calExtraWage();
        double calEarning();
};
#endif
