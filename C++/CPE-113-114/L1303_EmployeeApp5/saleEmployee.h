#ifndef SALEEMPLOYEE_H
#define SALEEMPLOYEE_H
#include "employee.h"

class SaleEmployee : public Employee
{
    public:
        SaleEmployee();
        SaleEmployee(string , double , int , double , double );
        double calCommission();
        double calEarning();
    protected:
        double salesVolume;
        double commissionRate;
};
#endif
