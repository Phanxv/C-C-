#include <iostream>

using namespace std;

int main()
{
    char aWord[40];
    cout << "Hello what? ";
    cin  >> aWord;
    cout << "Yes, hello " << aWord << '!'
         << endl;
    int age, birthYear;
    cout << "What's your age and birth year?" << endl;
    cin  >> age >> birthYear;
    cout << age << " and born in "
         << birthYear << ", so young."
         << endl;
    return 0;
}
