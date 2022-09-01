#include <iostream>

using namespace std;

int main()
{
    int x,y;
    cout << "Enter x: ";
    cin >> x;
    y = (x>10) ? x*3 : x*4;
    cout << "y is " << y << endl;
    cout << ((x%2) ? "x is odd number\n" : "x is even number\n");
    x = (x>5) ? 5 : x;
    cout << "Now, x is " << x << endl << endl;
    return 0;
}
