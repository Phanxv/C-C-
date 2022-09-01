#include <iostream>

using namespace std;

void foo(int &, int);

int main()
{
    int a = 10, b = 20;
    foo(a,b);
    cout << a << ", " << b << endl;
    foo(b,a);
    cout << a << ", " << b << endl;
    return 0;
}

void foo(int &x, int y)
{
    cout << x << ", " << y << endl;
    x = x + 5;
    y = y + 8;
}