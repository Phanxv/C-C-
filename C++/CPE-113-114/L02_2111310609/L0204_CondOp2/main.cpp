#include <iostream>

using namespace std;

int main()
{
    int a,b,c,largest;
    cout << "Enter 3 numbers : " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    largest = (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
    cout << "The largest is " << largest;
    return 0;
}
