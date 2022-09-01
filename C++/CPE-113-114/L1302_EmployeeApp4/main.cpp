#include <iostream>
#include "employee.h"
#include "saleEmployee.h"
#include "holidayEmployee.h"

using namespace std;

int main()
{
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

    Employee e1, e2("Chaichorn", 1000, 3);
    SaleEmployee se1, se2("Sakwon", 500, 8, 10, 1000);
    HolidayEmployee he1, he2("Kobdarn", 2000, 5, 10);

    cout << e1.name << "'s total salary is "
	     << e1.calTotalSalary() << " Baht" << endl
	     << "His earning is " << e1.calEarning()
	     << " Baht" << endl << endl
	     << e2.name << "'s total salary is "
	     << e2.calTotalSalary() << " Baht" << endl
	     << "His earning is " << e2.calEarning()
	     << " Baht" << endl << endl
	     << se1.name << "'s total salary is "
	     << se1.calTotalSalary() << " Baht" << endl
	     << "His commission is " << se1.calCommission()
	     << " Baht" << endl
	     << "His earning is " << se1.calEarning()
	     << " Baht" << endl << endl
	     << se2.name << "'s total salary is "
	     << se2.calTotalSalary() << " Baht" << endl
	     << "His commission is " << se2.calCommission()
	     << " Baht" << endl
	     << "His earning is " << se2.calEarning()
	     << " Baht" << endl << endl
	     << he1.name << "'s total salary is "
	     << he1.calTotalSalary() << " Baht" << endl
	     << "His extra wage is " << he1.calExtraTime()
	     << " Baht" << endl
	     << "His earning is " << he1.calEarning()
	     << " Baht" << endl << endl
	     << he2.name << "'s total salary is "
	     << he2.calTotalSalary() << " Baht" << endl
	     << "His extra wage is " << he2.calExtraTime()
	     << " Baht" << endl
	     << "His earning is " << he2.calEarning()
	     << " Baht" << endl << endl;
    return 0;
}
