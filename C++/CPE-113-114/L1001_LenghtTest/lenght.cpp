#include "lenght.h"
#include <cstdlib>
Length::Length() : kilometre(0), metre(0)
{ }

Length::Length(int km) : kilometre(km), metre(0)
{
    round();
}

Length::Length(int km, int m) : kilometre(km), metre(m)
{
	round();
}

void Length::setAll(int km, int m)
{
	kilometre= km;
	metre = m;
	round();
}

void Length::setKilometre(int km)
{
	kilometre = km;
}

void Length::setMetre(int m)
{
	metre = m;
	round();
}

int Length::getKilometre()
{
	return(kilometre);
}

int Length::getMetre()
{
	return(metre);
}

int Length::getTotalMetre()
{
	return(kilometre*1000 + metre);
}

double Length::getDecimal()
{
	return (
		kilometre + static_cast<double>(metre)/1000.0
	);
}

void Length::round()
{
	if ( abs(metre) >= 1000)
	{
		kilometre += metre/1000;
		metre %= 1000;
	}
}

