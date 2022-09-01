#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Money
{
public:
    Money(){dollars=0,cents=0;} ;
    Money(int c){dollars = c/100,cents = c%100;};
    Money(int d, int c){dollars = d+c/100, cents = c%100;};
    Money(double amt){dollars = amt/1, cents = (amt-dollars)*100;};

    void setBoth(int d, int c){dollars = d + c/100,cents = c%100;};
    void setDollars(int d){dollars = d;};
    void setCents(int c){cents = c;};

    int getDollars(){return (dollars);};
    int getCents(){return (cents);};
    double getAmount(){return (dollars + cents/100.0);};

    void output();

private:
    int dollars;
    int cents;
};

int main()
{
    Money m1, m2(7, 135), m3(820), m4(4.78);

    m1.output();
    m2.output();
    m3.output();
    m4.output();

    m1 = Money(5, 10);
    m1.output();

    m2 = Money(25, 10);
    m2.output();

    m3 = Money();
    m3.output();

    return 0;
}


/*Money::Money() : dollars(0), cents(0)
{
}

Money::Money(int c) : dollars(c/100), cents(c%100)
{
}

Money::Money(int d, int c) : dollars(d + c/100), cents(c%100)
{
}

Money::Money(double amt) : dollars(amt), cents((amt - dollars)*100)
{
}

void Money::setBoth(int d, int c)
{
    dollars = d + c/100;
    cents = c%100;
}

void Money::setDollars(int d)
{
    dollars = d;
}

void Money::setCents(int c)
{
    dollars = dollars + c/100;
    cents = c%100;
}

int Money::getDollars()
{
    return (dollars);
}

int Money::getCents()
{
    return (cents);
}

double Money::getAmount()
{
    return (dollars + cents/100.0);
//  or
//	return (dollars + static_cast<double>(cents)/100);
}*/

void Money::output()
{
    cout << (dollars < 0 ? '-' : ' ')
         << '$' << abs(dollars) << '.'
         << setw(2) << setfill('0') << abs(cents)
         << endl;
}