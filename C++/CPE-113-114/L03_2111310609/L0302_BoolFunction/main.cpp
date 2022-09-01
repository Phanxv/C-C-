#include <iostream>

using namespace std;

bool isTeenager(int age);

int main()
{
    int age;

    cout << "Enter your age : ";
    cin >> age;

    cout << "You are ";
    if(isTeenager(age) == true)
        cout << "teenager";
    else
        cout << "not teenager";
    return 0;
}

bool isTeenager(int age){
    return (age>=15 && age<=18);
}