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

    const Money operator+(const Money &) const;
	const Money operator-(const Money &) const;
	bool operator<(const Money &) const;
	bool operator>(const Money &) const;
	bool operator==(const Money &) const;
	const Money operator*(double) const;
	bool divide(double, Money &) const;
	const Money operator/(const Money &);

	const Money operator+=(const Money &);
	const Money operator/(double);
    const Money operator-=(const Money &);
    const Money operator++();

    double operator!() const;


private:
	int dollars;
	int cents;
};

/*const Money operator+(const Money &, const Money &);
const Money operator-(const Money &, const Money &);
bool operator<(const Money &, const Money &);
bool operator>(const Money &, const Money &);
bool operator==(const Money &, const Money &);
const Money operator*(const Money &, double);
bool divide(const Money &, double, Money &);
const Money operator++(Money &);
const Money operator+=(Money &, const Money &);
const Money operator/(const Money &, double );*/

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

 	m3 = m1 + Money(25,10);
    m3.output();

    (m1+m2).output();

 	m3 = Money(20, 10)-Money(10, 5);
	m3.output();
 	(Money(20, 10)-Money(10, 5)).output();

// 	if ( isLessThan(Money(10, 5), Money(20, 10)) )
//		cout << "Yes" << endl;
//	else
//		cout << "No" << endl;
 	cout << ( (Money(10, 5) < Money(20, 10)) ?
	          "Yes" : "No") << endl;
 	cout << ( (Money(20, 10) < Money(10, 5)) ?
	          "Yes" : "No") << endl;

 	cout << ( (Money(10, 5) > Money(20, 10)) ?
	          "Yes" : "No") << endl;
 	cout << ( (Money(20, 10) > Money(10, 5)) ?
	          "Yes" : "No") << endl;

 	cout << ( (Money(10, 5) == Money(10, 5)) ?
	          "Yes" : "No") << endl;
 	cout << ( (Money(10, 5) == Money(20, 10)) ?
	          "Yes" : "No") << endl;

 	(Money(20, 10) * 2.2).output();

 	if ( Money(20, 10).divide(0, m3) )
		m3.output();
	else
		cout << "cannot devide" << endl;

 	if ( Money(20, 10).divide(2.5, m3) )
		m3.output();
	else
		cout << "cannot devide" << endl;
	(m1 += Money(2, 95));
	m1.output();

	m3 = Money(45,32) / 2.2;
	m3.output();
	m3 = Money(45,32) / 0;
	m3.output();

	m3 = m1 += Money(2,95);
	m3.output();

	m3 = m1 -= Money(2,95);
	m3.output();

    cout << !(Money(420,69));
	return 0;
}
Money::Money() : dollars(0), cents(0)
{ }

Money::Money(int c) : dollars(c/100), cents(c%100)
{ }

Money::Money(int d, int c) : dollars(d + c/100), cents(c%100)
{ }

Money::Money(double amt)  : dollars(amt), cents((amt - dollars)*100)
{ }

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
// OR
//	return (dollars + static_type<double>cent/100);
}

void Money::output() const
{
	cout << (dollars < 0 ? '-' : ' ')
	     << '$' << abs(dollars) << '.'
	     << setw(2) << setfill('0') << abs(cents)
	     << endl;
}

const Money Money::operator+(const Money & m) const
{
	int cnt = cents + m.cents;
	int dlr = dollars + m.dollars;
	return ( Money( dlr, cnt ) );
}

const Money Money::operator-(const Money & m) const
{
	int total_cents = dollars*100 + cents - m.dollars*100 - m.cents;
	return ( Money( total_cents ) );
}

bool Money::operator<(const Money & m) const
{
 	return ( dollars < m.dollars ||
	         dollars == m.dollars && cents < m.cents );
}

bool Money::operator>(const Money & m) const
{
 	return ( dollars > m.dollars ||
	         dollars == m.dollars && cents > m.cents );
}

bool Money::operator==(const Money & m) const
{
// 	return ( dollars == m.dollars && cents == m.cents );
 	return ( ! (Money(dollars,cents)<m)  && ! ! ((Money(dollars,cents)>m) ));
// OR
// 	return ( !(isLessThan(a, b) || isGreaterThan(a, b)) );
}

const Money Money::operator*(double d) const
{
	int total_cents = ( dollars*100 + cents )*d;

	return ( Money( total_cents ) );
}

bool Money::divide(double d, Money &m) const
{
	if ( fabs(d) < 0.005)
		return (false);

	int total_cents = ( dollars*100 + cents )/d;
 	m = Money( total_cents );

 	return (true);
}

const Money Money::operator+=(const Money &m)
{
	int cnt = cents + m.cents;
	dollars += m.dollars + cnt/100;
	cents = cnt%100;
// OR
//	*this = add( m );
    return Money(dollars,cents);
}

const Money Money::operator/(double d){
    int total_cents = ( dollars*100 + cents )/d;
    return fabs(d)<0.005?Money():Money(total_cents);
}

const Money Money::operator-=(const Money &m){
    int cnt = cents - m.cents;
	dollars -= m.dollars - cnt/100;
	cents = cnt%100;
// OR
//	*this = add( m );
    return Money(dollars,cents);
}

const Money Money::operator++(){
    cents++;
    if(cents > 100){
        dollars++;
        cents = 0;
    }
    return Money(dollars,cents);
}

double Money::operator!() const{
    return (dollars + cents/100.0);
}
