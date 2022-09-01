#include <iostream>
#include <iomanip>
#include "money.h"

using namespace std;

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

double Money::operator!() const
{
    return (dollars + cents/100.0);
}

void Money::output() const
{
	cout << '$' << dollars << '.'
	     << setw(2) << setfill('0') << getCents()
	     << endl;
}

const Money Money::operator+(const Money &m) const
{
	int cnt = cents + m.cents;
	int dlr = dollars + m.dollars;
	return ( Money( dlr + cnt/100, cnt%100 ) );
}

const Money Money::operator-(const Money &m) const
{
	int total_cents
        = dollars*100 + cents
        - m.dollars*100 - m.cents;
 	return ( Money( total_cents/100, total_cents%100 ) );
}

bool Money::operator<(const Money &m) const
{
 	return (
        dollars < m.dollars ||
        dollars == m.dollars && cents < m.cents
    );
}

bool Money::operator>(const Money &m) const
{
 	return (
        dollars > m.dollars ||
        dollars == m.dollars && cents > m.cents
    );
}

bool Money::operator==(const Money &m) const
{
// 	return (
//       dollars == m.dollars &&
//       cents == m.cents
//    );
// OR
 	return ( !(*this < m) && !(*this > m) );
}

const Money Money::operator*(double d) const
{
	int total_cents = ( dollars*100 + cents )*d;

 	return ( Money( total_cents/100, total_cents%100 ) );
}

const Money Money::operator+=(const Money &m)
{
	int cnt = cents + m.cents;
	dollars += m.dollars + cnt/100;
	cents = cnt%100;

    return( *this );
}

const Money Money::operator/(double d) const
{
    if (d == 0.0)
        return ( Money() );

	int total_cents = ( dollars*100 + cents )/d;
 	return ( Money( total_cents/100, total_cents%100 ) );
}

const Money Money::operator-=(const Money &m)
{
	int total_cents
        = dollars*100 + cents
        - m.dollars*100 - m.cents;
    setBoth(total_cents/100, total_cents%100);

 	return ( Money(total_cents/100, total_cents%100) );
// OR
// 	*this = Money(total_cents/100, total_cents%100);
//  return (*this);
}

const Money Money::operator++()
{
    ++cents;
    if (cents == 100)
    {
        ++dollars;
        cents = 0;
    }
    return (*this);
}

const Money Money::operator++(int)
{
    Money temp = *this;

    ++cents;
    if (cents == 100)
    {
        ++dollars;
        cents = 0;
    }
    return (temp);

/* OR
    Money temp = *this;
    ++(*this);
    return (temp); */
}

const Money Money::operator--()
{
    if (cents == 0)
    {
        --dollars;
        cents = 99;
    }
    else
        --cents;
    return (*this);
}

const Money Money::operator--(int)
{
    Money temp = *this;

    if (cents == 0)
    {
        --dollars;
        cents = 99;
    }
    else
        --cents;
    return (temp);

/* OR
    Money temp = *this;
    --(*this);
    return (temp); */
}

const Money Money::operator+(int c) const
{
	int cnt = cents + c;
	return ( Money(dollars+cnt/100, cnt%100) );
}

const Money operator+(int c, const Money &m)
{
	int cnt = c + m.cents;
	return ( Money(m.dollars+cnt/100, cnt%100) );
}

const Money operator*(double d, const Money &m)
{
	int total_cents = ( m.dollars*100 + m.cents )*d;
 	return ( Money( total_cents/100, total_cents%100 ) );
}


bool Money::operator<(double amt) const
{
    int dll = amt;
    int cnt = (amt - dll)*100;
 	return (
        dll < dollars  ||
        dll == dollars && cnt < cents
    );
}

bool operator<(double amt, const Money &m)
{
    int dll = amt;
    int cnt = (amt - dll)*100;
 	return (
        m.dollars < dll ||
        m.dollars == dll && m.cents < cnt
    );
}

