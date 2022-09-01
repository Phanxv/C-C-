#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
    float deposit, interest, balance;
    int year, i;
    cout << "Enter the deposit : ";
    cin >> deposit;
    balance = deposit;
    cout << "Enter the number of years from now on : ";
    cin >> year;
    cout << "Enter the interest rate : ";
    cin >> interest;
    cout << endl
         << "Calculating...." << endl << endl;
    for(i=1;i<=year;i++){
        balance += balance*(interest/100);
        cout << "After year " << i << ": " << balance << endl;
    }
    cout << endl
         << "The balance at the next " << year
         << " years is " << balance << endl;
    return 0;
}
