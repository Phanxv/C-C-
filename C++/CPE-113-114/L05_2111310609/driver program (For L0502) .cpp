#include <iostream>

using namespace std;

class Money
{
/* 
	member variables and member functions declaration
*/
};

int main()
{
	Money m1, m2;

	m1.setDollars(7);
	m1.setCents(235);
	cout << "Money object 1 has " << m1.getDollars()
	     << " Dollars and " << m1.getCents()
	     << " Cents." << endl
	     << "It's equal to $" << m1.getAmount()
	     << '.' << endl;

	m2.setBoth(8, 472);
	cout << "Money object 2 has " << m2.getDollars()
	     << " Dollars and " << m2.getCents()
	     << " Cents." << endl
	     << "It's equal to $" << m2.getAmount()
	     << '.' << endl;

	return 0;
}

 /* 
	member functions definition 
*/

