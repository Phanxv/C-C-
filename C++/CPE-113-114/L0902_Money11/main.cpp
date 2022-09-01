#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Money
{
friend const Money operator+(const Money &, int);
friend const Money operator+(int, const Money &);
friend const Money operator*(double, const Money &);
friend bool operator<(double, const Money &);
friend bool operator<(const Money &, double);
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
    const Money operator/(double) const;
    const Money operator+=(const Money &);
// 1
    const Money operator-=(const Money &);
    const Money operator++();
// 4
    const Money operator++(int);

// 5
    const Money operator--();
    const Money operator--(int);

// 3
    double operator!() const;

private:
	int dollars;
	int cents;
};

bool divide(const Money &, double, Money &);
const Money operator+(const Money &, int);
const Money operator+(int, const Money &);
const Money operator*(double, const Money &);
bool operator<(double, const Money &);
bool operator<(const Money &, double);

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

    (m1 + m2).output();

 	(Money(20, 10) - Money(10, 5)).output();

 	cout << (Money(10, 5) < Money(20, 10) ?
	          "Yes" : "No") << endl;
 	cout << (Money(20, 10) < Money(10, 5) ?
	          "Yes" : "No") << endl;
 	cout << (Money(10, 5) > Money(20, 10) ?
	          "Yes" : "No") << endl;
 	cout << (Money(20, 10) > Money(10, 5) ?
	          "Yes" : "No") << endl;
 	cout << (Money(10, 5) == Money(10, 5) ?
	          "Yes" : "No") << endl;
 	cout << (Money(10, 5) == Money(20, 10) ?
	          "Yes" : "No") << endl;
 	(Money(20, 10) * 2.2).output();

 	if ( divide(Money(20, 10), 0, m3) )
        m3.output();
    else
        cout << "cannot devide" << endl;
 	if ( divide(Money(20, 10), 2.5, m3) )
        m3.output();
    else
        cout << "cannot devide" << endl;

	m3 = m1 += Money(2, 95);
	m3.output();

	m3  = Money(45, 32) / 2.2;
	m3.output();
	m3  = Money(45, 32) / 0;
	m3.output();

// 1
	m3 = m1 -= Money(2, 95);
	m3.output();

// 2
	m1 = Money(2, 50);
	m3 = ++m1;
	m1.output();
	m3.output();
    m1 = Money(2, 99);
	m3 = ++m1;
	m1.output();
	m3.output();

// 3
    cout << !Money(2, 45) << endl;

// 4
	m1= Money(2, 50);
	m3 = m1++;
	m1.output();
	m3.output();
    m1 = Money(2, 99);
	m3 = m1++;
	m1.output();
	m3.output();

// 5
	m1 = Money(2, 50);
	m3 = --m1;
	m1.output();
	m3.output();
    m1 = Money(3, 0);
	m3 = --m1;
	m1.output();
	m3.output();

// 5
	m1= Money(2, 50);
	m3 = m1--;
	m1.output();
	m3.output();
    m1 = Money(3, 00);
	m3 = m1--;
	m1.output();
	m3.output();

    cout << "m1 + 95 Cents is $" << !(m1+95) << endl;
    cout << "95 Cents + m1 is $" << !(95+m1) << endl;
    cout << "2.5 * m1 is $" << !(2.5*m1) << endl;

    cout << "m1 < 7.85 ?";
    if(m1 < 7.85)
        cout << " Yes";
    else
        cout << " No";

    cout << endl << "7.85 < m1 ?";
    if(7.85 < m1)
        cout << " Yes";
    else
        cout << " No";
    return 0;
}

Money::Money() : dollars(0), cents(0)
{ }

Money::Money(int c) : dollars(c/100), cents(c%100)
{ }

Money::Money(int d, int c) : dollars(d + c/100), cents(c%100)
{ }

Money::Money(double amt) : dollars(amt), cents((amt - dollars)*100)
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
}

void Money::output() const
{
	cout << (dollars < 0 ? '-' : ' ')
	     << '$' << abs(dollars) << '.'
	     << setw(2) << setfill('0') << abs(cents)
	     << endl;
}

const Money Money::operator+(const Money &m) const
{
	int cnt = cents + m.cents;
	int dlr = dollars + m.dollars;
	return ( Money( dlr, cnt ) );
}

const Money Money::operator-(const Money &m) const
{
	int total_cents = dollars*100 + cents
                      - m.dollars*100 - m.cents;
 	return ( Money( total_cents ) );
}

bool Money::operator<(const Money &m) const
{
 	return ( dollars < m.dollars ||
             dollars == m.dollars && cents < m.cents );
}

bool Money::operator>(const Money &m) const
{
 	return ( dollars > m.dollars ||
             dollars == m.dollars && cents > m.cents );
}

bool Money::operator==(const Money &m) const
{
 	return ( dollars == m.dollars && cents == m.cents );
// OR
// 	return ( !(*this < m) && !(*this > m) );
}

const Money Money::operator*(double d) const
{
	int total_cents = ( dollars*100 + cents )*d;

 	return ( Money( total_cents ) );
}

const Money Money::operator/(double d) const
{
	if (fabs(d) < 0.005)
		return ( Money() );

	int total_cents = ( dollars*100 + cents )/d;
 	return( Money( total_cents ) );

// OR
// 	if ( divide(*this, d) )
//		return ( Money() );
//  return (*this);
}

const Money Money::operator+=(const Money &m)
{
	int cnt = cents + m.cents;
	int dlr = dollars + m.dollars;
	setBoth(dlr, cnt);                  // OR   *this = Money( dlr, cnt );
	return ( Money( dlr, cnt ) );       //      return ( *this );

// OR
//	*this = *this + m;
//  return ( *this );
}

// 1
const Money Money::operator-=(const Money &m)
{
	int total_cents = dollars*100 + cents - m.dollars*100 - m.cents;

	setBoth(0, total_cents);            // OR   *this = Money( dlr, cnt );
	return ( Money( 0, total_cents ) ); //      return ( *this );

// OR
//	*this = *this - m;
//  return ( *this );
}

// 2
const Money Money::operator++()
{
    if (cents == 99) {
        cents = 0;
        ++dollars;
    } else
        ++cents;

    return Money(dollars, cents); // OR return ( *this );
}

// 4
const Money Money::operator++(int)
{
    int dlr = dollars;
    int cnt = cents;

    if (cents == 99) {
        cents = 0;
        ++dollars;
    } else
        ++cents;

    return Money(dlr, cnt); // OR return ( *this );

// OR
//  Money m = *this;
//  ++(*this);
//  return ( m );
}

// 5
const Money Money::operator--()
{
    if (cents == 0) {
        cents = 99;
        --dollars;
    } else
        --cents;

    return Money(dollars, cents); // OR return ( *this );
}

// 5
const Money Money::operator--(int)
{
    int dlr = dollars;
    int cnt = cents;

    if (cents == 0) {
        cents = 99;
        --dollars;
    } else
        --cents;

    return Money(dlr, cnt); // OR return ( *this );

// OR
//  Money m = *this;
//  --(*this);
//  return ( m );
}

// 3
double Money::operator!() const
{
	return (dollars + cents/100.0); // OR return ( getAmount() );
}

bool divide(const Money &a, double d, Money &b)
{
	if (fabs(d) < 0.005)
		return (false);

	int total_cents = ( a.getDollars()*100 + a.getCents() )/d;
 	b = Money( total_cents );
 	return (true);
}

const Money operator+(const Money &m, int c){
    int cnt = m.cents+c;
    return (Money(m.dollars+cnt/100, cnt%100));
}

const Money operator+(int c, const Money &m){
    int cnt = m.cents+c;
    return (Money(m.dollars+cnt/100, cnt%100));
}

const Money operator*(double d, const Money &m){
    int total_cents = ( m.dollars*100 + m.cents )*d;

 	return ( Money( total_cents ) );
}

bool operator<(double d, const Money &m){
    return ( d < m.dollars+m.cents/100.0);
}

bool operator<(const Money &m, double d){
    return ( m.dollars+m.cents/100.0 < d);
}
