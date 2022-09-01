#include "river.h"
#include <cstring>

River::River() : name("Undefined"), riverLength(0, 0)
{
}

River::River(char* n, int km, int m)
{
   strcpy(name, n);
	riverLength.set(km, m);
}

void River::set(char* n, int km, int m)
{
	strcpy(name, n);
	riverLength.set(km, m);
}

void River::setName(char* n)
{
	strcpy(name, n);
}

char* River::getName()
{
	return name;
}

Length River::getLength()
{
	return riverLength;
}
