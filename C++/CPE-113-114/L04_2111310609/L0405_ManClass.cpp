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
        int calDifAge(Man anotherMan);
};

int main(){
    Man tom, poo;

    strcpy(tom.name, "Tom Tumtang");
    strcpy(poo.name, "Poo Papoa");
    tom.birthYear = 2538;
    poo.birthYear = 2510;
    cout << tom.name << " will be " << tom.calAge(2566)
         << " years olds in year 2566." << endl;
    cout << "Tom and Poo are " << tom.calDifAge(poo)
         << " years different." << endl;
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