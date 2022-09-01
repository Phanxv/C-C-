#include <iostream>

using namespace std;

class Money
{
public:
	void setBoth(int, int);
	void setDollars(int);
	void setCents(int);

	int getDollars();
	int getCents();
	double getAmount();

private:
	int dollars;
	int cents;
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

void Money::setBoth(int d, int c)
{
	dollars = d + c/100;
	cents = c%100;
}

void Money::setDollars(int d)
{
	dollars = d;
}

void Money::setCents(int c)
{
	dollars = dollars + c/100;
	cents = c%100;
}

int Money::getDollars()
{
	return (dollars);
}

int Money::getCents()
{
	return (cents);
}

double Money::getAmount()
{
   return (dollars + cents/100.0);
// or
//    return (dollars + static_cast<double>(cents)/100);
}
