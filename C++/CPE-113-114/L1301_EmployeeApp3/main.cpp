#include <iostream>
#include <string>

using namespace std;

class Employee
{
    public:
        Employee() : name("no name"), salary(0.0), months(0) {}
        Employee(string n, double s, int m) : name(n), salary(s), months(m) {}
        double calTotalSalary() const
        {
            return( salary*months );
        }
        double calEarning() const
        {
    //	  return( 0.9*salary*months );
    // OR
          return( 0.9*calTotalSalary() );
        }

    // private:
        string name;
        double salary;
        int months;
};

class SaleEmployee : public Employee
{
public:
    SaleEmployee() : salesVolume(0.0), commissionRate(0.0) {}
    SaleEmployee(string n, double s, int m, double sv, double cr) : salesVolume(sv), commissionRate(cr)
    {name = n; salary = s; months = m;}
	double calCommission()
	{
		return( salesVolume*commissionRate/100.0 );
	}

	double calEarning()
	{
//		return( 0.9*salary*months + 0.9*calCommission() );
// OR
//      return( 0.9*calTotalSalary() + 0.9*calCommission() );
// OR
		return( Employee::calEarning() + 0.9*calCommission() );
	}
	double salesVolume;
	double commissionRate;
};

// 7
class HolidayEmployee : public Employee
{
public:
    HolidayEmployee() : hours(0) {}
    HolidayEmployee(string n, double s, int m, int h) : hours(h)
    {name = n; salary = s; months = m;}
	double calExtraTime()
	{
		return( salary*hours*0.01 );
	}
	double calEarning()
	{
		return( Employee::calEarning() + 0.9*calExtraTime() );
	}
	int hours;
};

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
