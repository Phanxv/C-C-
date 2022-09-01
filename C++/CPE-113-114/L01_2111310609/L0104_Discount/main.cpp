#include <iostream>

using namespace std;

int main()
{
    int price, VAT;
    cout << "Price (Baht): ";
    cin  >> price;
    cout << "Value Added Tax: ";
    cin  >> VAT;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "The price after adding tax is "
         << price + static_cast<float>(VAT)/100*price << " Baht." << endl;
    return 0;
}
