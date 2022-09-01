#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
public:
    void output();
    Money();
    Money(int);
    Money(int, int);
    Money(double);
private:
    int dollars;
    int cents;
};

int main()
{
    Money m1, m2(7, 135), m3(820),m4(420.69);
    m1 = Money(5, 10);
    m2 = Money(25, 10);
    m3 = Money(0, 0);
    m1.output();
    m2.output();
    m3.output();
    m4.output();

    return 0;
}

void Money::output()
{
    cout << (dollars < 0 ? '-' : ' ')
         << '$' << abs(dollars) << '.'
         << setw(2) << setfill('0') << abs(cents)
         << endl;
}
Money::Money():dollars(0),cents(0)
{
  //  dollars = 0; cents = 0;
}
Money::Money(int c):dollars(c/100),cents(c%100)
{
    //dollars = c/100; cents = c%100;
}
Money::Money(int d, int c):dollars(d+c/100),cents(c%100)
{
    //dollars = d+c/100; cents = c%100;
}
Money::Money(double c):dollars(c/1),cents(static_cast<int>(c*100)%100)
{
    //dollars = c/1 ; cents = static_cast<int>(c100)%100;
}