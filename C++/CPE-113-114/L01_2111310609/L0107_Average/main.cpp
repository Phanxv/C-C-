#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

    int num1,num2,num3;
    const int DENOMINATOR = 3;
    cout << "Enter first number : ";
    cin  >> num1;
    cout << "Enter second number : ";
    cin  >> num2;
    cout << "Enter third number : ";
    cin  >> num3;

    cout << "\n"
         << "The average is "
         << static_cast<float>(num1+num2+num3)/DENOMINATOR << endl;
    return 0;
}
