#include "length.h"
#include <cstdlib>

Length::Length() : kilometre(0), metre(0) { }

Length::Length(int km) : kilometre(km), metre(0) { }

Length::Length(int km, int m)	: kilometre(km + m/1000), metre(m%1000) { }

void Length::set(int km, int m)
{
	kilometre = km;
	metre = m;
	adjust();
}

void Length::setKilometre(int km)
{
	kilometre = km;
}

void Length::setMetre(int m)
{
	metre = m;
	adjust();
}

int Length::getKilometre()
{
	return kilometre;
}

int Length::getMetre()
{
	return metre;
}

double Length::getDecimal()
{
	return kilometre + static_cast<double>(metre)/1000.0;
}

void Length::adjust()
{
	if ( abs(metre) >= 1000)
	{
		kilometre += metre/1000;
		metre %= 1000;
	}
}

bool Length::operator<(Length any)
{
	if (kilometre < any.kilometre)
		return true;
	else if (kilometre == any.kilometre &&
	         metre < any.metre)
		return true;

	return false;
}

bool Length::operator>(Length any)
{
	if (kilometre > any.kilometre)
		return true;
	else if (kilometre == any.kilometre &&
	         metre > any.metre)
		return true;

	return false;
}

bool Length::operator==(Length any)
{
	if (kilometre == any.kilometre &&
	         metre == any.metre)
		return true;

	return false;
}

bool Length::operator!=(Length any)
{
	if (kilometre == any.kilometre &&
	         metre == any.metre)
		return false;

	return true;
}

Length Length::operator+(Length any)
{
	int m = metre + any.metre;
	int km = kilometre + any.kilometre + m/1000;
	m %= 1000;
	return Length(km, m);
}

Length Length::operator-(Length any)
{
   any.kilometre = -any.kilometre;
   any.metre = -any.metre;
   return( *this + any );
}
