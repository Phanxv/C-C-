#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

class Money
{
public:
	Money() ;
	Money(int);
	Money(int, int);
	Money(double);

	void setBoth(int, int);
	void setDollars(int);
	void setCents(int);

	int getDollars() const;
	int getCents() const;
	double getAmount() const;

	void output() const;

private:
	int dollars;
	int cents;
};

const Money operator+(const Money &, const Money &);
const Money subtract(const Money &, const Money &);
bool isLessThan(const Money & , const Money & );
bool isGreaterThan(const Money &, const Money &);
bool isEqualTo(const Money &, const Money &);
const Money multiply(const Money &, double);
bool divide(const Money &, double, Money &);
void addToItself(Money &, const Money &);

int main()
{
	Money m1, m2(7, 135), m3(820), m4(4.78);

	m1.output();
	m2.output();
	m3.output();
	m4.output();

	m1 = Money(5, 10);
	m1.output();
	m2 = Money(25, 10);
	m2.output();
	m3 = Money();
	m3.output();

 	m3 = m1 + Money(25, 10);
	m3.output();

// 	m3 = subtract(Money(20, 10), Money(10, 5));
//	m3.output();
 	subtract(Money(20, 10), Money(10, 5)).output();

// 	if ( isLessThan(Money(10, 5), Money(20, 10)) )
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;

 	cout << ( isLessThan(Money(10, 5), Money(20, 10)) ?
	          "Yes" : "No") << endl;
 	cout << ( isLessThan(Money(20, 10), Money(10, 5)) ?
	          "Yes" : "No") << endl;

 	cout << ( isGreaterThan(Money(10, 5), Money(20, 10)) ?
	          "Yes" : "No") << endl;
 	cout << ( isGreaterThan(Money(20, 10), Money(10, 5)) ?
	          "Yes" : "No") << endl;

 	cout << ( isEqualTo(Money(10, 5), Money(10, 5)) ?
	          "Yes" : "No") << endl;
 	cout << ( isEqualTo(Money(10, 5), Money(20, 10)) ?
	          "Yes" : "No") << endl;

 	multiply(Money(20, 10), 2.2).output();

 	if ( divide(Money(20, 10), 0, m3) )
		m3.output();
	else
		cout << "cannot devide" << endl;

 	if ( divide(Money(20, 10), 2.5, m3) )
		m3.output();
	else
		cout << "cannot devide" << endl;
    (m1 + m2).output();
    addToItself(m1, Money(2, 95));
    m1.output();
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

Money::Money(double amt) : dollars(amt), cents((amt - dollars)*100)
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

int Money::getDollars() const
{
	return (dollars);
}

int Money::getCents() const
{
	return (cents);
}

double Money::getAmount() const
{
	return (dollars + cents/100.0);
//  or
//	return (dollars + static_cast<double>(cents)/100);
}

void Money::output() const
{
	cout << (dollars < 0 ? '-' : ' ')
	     << '$' << abs(dollars) << '.'
	     << setw(2) << setfill('0') << abs(cents)
	     << endl;
}

const Money operator+(const Money &a, const Money &b)
{
	int cnt = a.getCents() + b.getCents();
	int dlr = a.getDollars() + b.getDollars();
	return ( Money( dlr, cnt ) );
}

const Money subtract(const Money &a, const Money &b)
{
	int total_cents
	   = a.getDollars()*100 + a.getCents()
	     - b.getDollars()*100 - b.getCents();
	return ( Money( total_cents ) );
}

bool isLessThan(const Money &a, const Money &b)
{
 	return (
	    a.getDollars() < b.getDollars() ||
	   a.getDollars() == b.getDollars() && a.getCents() < b.getCents()
	);
}

bool isGreaterThan(const Money &a, const Money &b)
{
 	return (
	   a.getDollars() > b.getDollars() ||
	   a.getDollars() == b.getDollars() && a.getCents() > b.getCents()
	);
}

bool isEqualTo(const Money &a, const Money &b)
{
// 	return (
//	   a.getDollars() == b.getDollars() &&
//	   a.getCents() == b.getCents()
//	);
 	return ( !isLessThan(a, b) && !isGreaterThan(a, b) );
//or
// 	return ( !(isLessThan(a, b) || isGreaterThan(a, b)) );
}

const Money multiply(const Money &m, double d)
{
	int total_cents = ( m.getDollars()*100 + m.getCents() )*d;

 	return ( Money( total_cents ) );
}

bool divide(const Money &a, double d, Money &b)
{
	if (fabs(d) < 0.005)
		return (false);

	int total_cents = ( a.getDollars()*100 + a.getCents() )/d;
	b = Money( total_cents );

 	return (true);
}

void addToItself(Money &a, const Money &b)
{
    int cnt = a.getCents() + b.getCents();
	int dlr = a.getDollars() + b.getDollars();
	a = Money(dlr, cnt);
}