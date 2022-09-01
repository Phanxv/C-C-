#include <iostream>
#include <string>

using namespace std;

string stringYear(int number);

int main(){
    int year;
    cin >> year;
    cout << stringYear(year);
}

string stringYear(int number){
    char numberArray[5];
    for (int i = 3; i >= 0; --i)
    {
        numberArray[i] = (number % 10) + '0';
        number/=10;
    }
    numberArray[4] = '\0';
    return numberArray;
}