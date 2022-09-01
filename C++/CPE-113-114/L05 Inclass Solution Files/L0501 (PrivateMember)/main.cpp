#include <iostream>
#include <cstring>

using namespace std;

class Man
{
public:
// 3
	void set(char *, int);
	void setName(char *);
	void setBirthYear(int);
// 4
	char* getName();
	int getBirthYear();

	int calAge();
	int calAge(int);
    int calDifAge(Man);

// 1
private:
	char name[40];
	int birthYear;
};

int main()
{
// 2, 5
	Man tom, poo;

	tom.setName("Tom Tumtang");
	tom.setBirthYear(2538);

	poo.setName("Poo Papoa");
	poo.setBirthYear(2510);
// 6
	cout << tom.getName() << " is "
         << tom.calAge() << " years olds."
         << endl;
	cout << tom.getName() << " will be "
	     << tom.calAge(2566)
	     << " years olds in year 2566."
	     << endl;

	cout << "Tom and Poo are "
	     << tom.calDifAge(poo)
	     << " years age diferent."
 	     << endl;
// 7
    Man porn;
    char n1[40], n2[40];
    int b;

    cout << "Enter Porn's name: ";
    cin >> n1 >> n2;
    strcat( strcat(n1, " "), n2 );
    cout << "Enter Porn's birth year: ";
    cin >> b;
    porn.set(n1, b);

	cout << porn.getName() << " was born on "
         << porn.getBirthYear() << '.' << endl;

    return 0;
}

// 3
void Man::set(char *n, int b)
{
	strcpy(name, n);
	birthYear = b > 2564 ? 2564 : b < 2465 ? 2465 : b;
}

// 3
void Man::setName(char *n)
{
	strcpy(name, n);
}

// 3
void Man::setBirthYear(int b)
{
	birthYear = b > 2564 ? 2564 : b < 2465 ? 2465 : b;
}

// 4
char* Man::getName()
{
	return(name);
}

// 4
int Man::getBirthYear()
{
	return(birthYear);
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
	return (birthYear - anotherMan.birthYear);
}
