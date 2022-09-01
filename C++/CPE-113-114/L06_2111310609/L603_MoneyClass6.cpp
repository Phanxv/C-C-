#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
    public:
        Money();
        Money(int);
        Money(int, int);
        Money(double);
        void setBoth(int, int);
        void setDollars(int);
        void setCents(int);
        void output();
        int getDollars();
        int getCents();
        double getAmount();
        Money add(Money a, Money b);
        Money subtract(Money a, Money b);
        bool isLessThan(Money a, Money b);
        bool isGreaterThan(Money a, Money b);
        bool isEqualTo(Money a, Money b);
        bool divide(Money a,double b, Money &c);
    private:
        int dollars;
        int cents;
};

int main()
{
	Money m1, m2(7, 135), m3(820), m4(4.78), m5, m;

	m1.output();
	m2.output();
	m3.output();
	m4.output();

	m1 = Money(5, 10);
	m2 = Money(25, 10);
	m3 = Money();

	m1.output();
	m2.output();
	m3.output();

	m.add(Money(10, 5), Money(20, 10)).output();

	m3 = m.subtract(Money(10, 5), Money(20, 10));
	m3.output();

	cout << (m.isLessThan(Money(10, 5), Money(20, 10)) ? "Yes" : "No") << endl;
	cout << (m.isGreaterThan(Money(10, 5), Money(20, 10)) ? "Yes" : "No") << endl;
	cout << (m.isEqualTo(Money(10, 5), Money(20, 10)) ? "Yes" : "No") << endl;
	cout << (m.divide(Money(10, 5), 0, m5) ? "Divide complete" : "Divide incomplete") << endl;
	m5.output();


	return 0;
}

Money::Money() : dollars(0), cents(0)
{
}

Money::Money(int c) : dollars(c/100), cents(c%100)
{
}

Money::Money(int d, int c) : dollars(d + c/100), cents(c%100)
{
}

Money::Money(double total) : dollars(total), cents((static_cast<int>(total*100))%100)
{
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

void Money::output()
{
    cout << (dollars < 0 ? '-' : ' ')
         << '$' << abs(dollars) << '.'
         << setw(2) << setfill('0') << abs(cents)
         << endl;
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
}

Money Money::add(Money a, Money b)
{
    return (Money(a.getDollars() + b.getDollars(), a.getCents() + b.getCents()));
}

Money Money::subtract(Money a, Money b)
{
    return(Money(a.getDollars() - b.getDollars(), a.getCents() - b.getCents()));
}

bool Money::isLessThan(Money a, Money b)
{
    return a.getAmount() < b.getAmount();
}

bool Money::isGreaterThan(Money a, Money b)
{
    return a.getAmount() > b.getAmount();
}

bool Money::isEqualTo(Money a, Money b)
{
    return a.getAmount() == b.getAmount();
}

bool Money::divide(Money a, double b, Money &c)
{
    if(b > 0.005)
    {
        c = Money(a.getAmount()/b);
    }
    else
        c = a.getAmount();
    return b > 0.005;
}
