#include <iostream>
#include <cstring>

using namespace std;

struct Thing
{
    int a, b;
};

void foo(Thing, Thing &);
Thing goo(Thing, int);

int main()
{
    Thing x = {10, 20}, y = {30, 40}, z;
    foo(x, y);
    z = goo(x, 5);
    cout << "x is (" << x.a << ',' << x.b << "), "
    << "y is (" << y.a << ',' << y.b << "), "
    << "z is (" << z.a << ',' << z.b << ")"
    << endl << endl;
}

void foo(Thing m, Thing &n)
{
    m.a += 10;
    m.b -= 10;
    n.a += 10;
    n.b -= 10;  
}

Thing goo(Thing m, int n)
{
    Thing t;
    t = m;
    t.a += n;
    return(t);
}