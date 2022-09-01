#include <iostream>
#include <string>

using namespace std;

class Employee
{
    public:
        double calTotalSalary() const
        {
            return( salary*months );
        }
        double calEarning() const
        {
    //	  return( 0.9*salary*months );
          return( 0.9*calTotalSalary() );
        }
        string name;
        double salary;
        int months;
};

class SaleEmployee : public Employee
{
    public:
        double calCommission()
        {
            return( salesVolume*commissionRate/100.0 );
        }
        double calEarning()
        {
            return( 0.9*salary*months + 0.9*calCommission() );
            //return(Employee::calEarning() + 0.9*calCommission());
        }
        double salesVolume;
        double commissionRate;
};

class HolidayEmployee : public Employee
{
    public:
        double calExtraTime()
        {
            return(Employee::salary*0.01*hours);
        }
        double calEarning()
        {
            return((Employee::calTotalSalary()+calExtraTime())*0.9);
        }
        int hours;

};
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	/*SaleEmployee sak;
    cout << "Enter name: ";
    cin >> sak.name;
    cout << "Enter salary: ";
    cin >> sak.salary;
    cout << "Enter number of months: ";
    cin >> sak.months;
    cout << "Enter commission rate: ";
    cin >> sak.commissionRate;
    cout << "Enter sales volume: ";
    cin >> sak.salesVolume;
    cout << endl;
    cout << sak.name << "'s total salary is "
    << sak.calTotalSalary() << " Baht" << endl
    << "His commission is " << sak.calCommission()
    << " Baht" << endl
    << "His earning is " << sak.calEarning()
    << " Baht" << endl << endl;*/

    HolidayEmployee kob;
    cout << "Enter name: ";
    cin >> kob.name;
    cout << "Enter salary: ";
    cin >> kob.salary;
    cout << "Enter number of months: ";
    cin >> kob.months;
    cout << "Enter extra hours: ";
    cin >> kob.hours;
    cout << kob.name << "'s total salary is "
         << kob.calTotalSalary() << " Baht" << endl
         << "His extra wage is " << kob.calExtraTime()
         << " Baht" << endl
         << "His earning is " << kob.calEarning()
         << " Baht" << endl << endl;
    return 0;
}
