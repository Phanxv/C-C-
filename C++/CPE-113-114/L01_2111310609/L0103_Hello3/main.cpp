#include <iostream>

using namespace std;

int main()
{
    char name[50], lastName[50];
    int studentID, birthYear;
    cout << "What's your name? ";
    cin  >> name >> lastName;
    cout << "What's your student ID? ";
    cin  >> studentID;
    cout << "What's your birth year? ";
    cin  >> birthYear;
    cout << "\n"
         << "Hello " << name << " " << lastName << ", ID " << studentID << "." << endl
         << "You are " << 2021-birthYear << " years old.";
    return 0;
}
