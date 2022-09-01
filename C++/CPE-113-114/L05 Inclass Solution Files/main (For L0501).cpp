#include <iostream>
#include <cstring>

using namespace std;

class Man
{
public:
	char name[40];
	int birthYear;
	int calAge();
	int calAge(int);
	int calDifAge(Man);
};

int main()
{
	Man tom, poo;

	strcpy(tom.name, "Tom Tumtang");
	tom.birthYear = 2538;
	strcpy(poo.name, "Poo Papoa");
	poo.birthYear = 2510;

	cout << tom.name << " is " << tom.calAge()
	     << " years olds." << endl;
	cout << tom.name << " will be " << tom.calAge(2566)
	     << " years olds in year 2566." << endl;
	cout << "Tom and Poo are " << tom.calDifAge(poo)
	     << " years age diferent." << endl;

	return 0;
}

int Man::calAge()
{
	return (2564 - birthYear);
}

int Man::calAge(int currentYear)
{
	return (currentYear - birthYear);
}

int Man::calDifAge(Man anotherMan)
{
	return (birthYear - anotherMan.birthYear );
}
