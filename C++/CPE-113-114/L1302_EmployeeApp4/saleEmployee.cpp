#include "saleEmployee.h"

SaleEmployee::SaleEmployee() : salesVolume(0.0), commissionRate(0.0)
{}

SaleEmployee::SaleEmployee(string n, double s, int m, double sv, double cr) : salesVolume(sv), commissionRate(cr)
{name = n; salary = s; months = m;}

double SaleEmployee::calCommission()
{
    return( salesVolume*commissionRate/100.0 );
}

double SaleEmployee::calEarning()
{
    return( Employee::calEarning() + 0.9*calCommission() );
}
