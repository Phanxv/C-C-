#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string, double, int );
        double calTotalSalary() const;
        double calEarning() const;
        string name;
        double salary;
        int months;
};

#endif
