#include <iostream>

using namespace std;

float calFuturePrice(float cost, int years);

int main()
{
    float cost;
    int years, presentYear, futureYear;

    cout << "Enter current price : ";
    cin >> cost;
    cout << "Enter current year : ";
    cin >> presentYear;
    cout << "Enter the target year : ";
    cin >> futureYear;

    years = futureYear - presentYear;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << endl
         << "In the year " << futureYear
         << ", the price is " << calFuturePrice(cost,years);

    return 0;
}

float calFuturePrice(float cost, int years){
    int i;
    for (int i = 0; i < years; ++i)
        cost = cost + cost*1.5/100.0;
        return cost;
}
