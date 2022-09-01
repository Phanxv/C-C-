#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
public:
    void setDollars(int);
    void setCents(int);
    void setBoth(int,int);
    int getDollars();
    int getCents();
    double getAmount();
    void output();
    Money();
    Money(int);
    Money(int, int);
    Money(double);

private:
    int dollars;
    int cents;
};
Money add(Money a, Money b);
Money subtract(Money a,Money b);
bool isGreaterThan(Money a,Money b);
int main()
{
	Money m1, m2(7, 135), m3(820),m4(4.78);
    m1 = Money(5, 10);
    m2 = Money(25, 10);
    m3 = Money(0, 0);
    m1.output();
    m2.output();
    m3.output();
    m4.output();
    add(Money(10, 5), Money(20, 10)).output();
    m3 = subtract(Money(10, 5), Money(20, 10));
    m3.output();
    cout << ( isGreaterThan(Money(10, 5), Money(20, 10)) ?
              "Yes" : "No") << endl;

	return 0;
}
void Money::setDollars(int x)
{
    dollars = x;
}
void Money::setCents(int x)
{
    dollars += x/100;
    cents = x%100;
}
int Money::getDollars()
{
    return dollars;
}
int Money::getCents()
{
    return cents;
}
void Money::setBoth(int InDollars,int InCents)
{
    dollars = InDollars + InCents / 100;
    cents = InCents%100;
}
double Money::getAmount()
{
    return  (dollars * 100 + cents)/100.0;
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
    //dollars = c/1 ; cents = static_cast<int>(c*100)%100;
}
Money add(Money a, Money b)
{
    return( Money(
    a.getDollars() + b.getDollars(),
    a.getCents() + b.getCents()
    ) );
}
Money subtract(Money a, Money b)
{
    return( Money(
    a.getDollars() - b.getDollars(),
    a.getCents() - b.getCents()
    ) );
}
bool isGreaterThan(Money a,Money b)
{
    return a.getAmount() > b.getAmount();
}
