#include <iostream>
#include <iomanip>
#include "money.h"
using namespace std;

bool divide(const Money &, double, Money &);

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

 	m3 = m1 + Money(25, 10);
	m3.output();

 	(Money(20, 10) - Money(10, 5)).output();

 	cout << (Money(10, 5) < Money(20, 10) ?
	          "Yes" : "No") << endl;
 	cout << (Money(20, 10) < Money(10, 5) ?
	          "Yes" : "No") << endl;

 	cout << (Money(10, 5) > Money(20, 10) ?
	          "Yes" : "No") << endl;
 	cout << (Money(20, 10) > Money(10, 5) ?
	          "Yes" : "No") << endl;

 	cout << (Money(10, 5) == Money(10, 5) ?
	          "Yes" : "No") << endl;
 	cout << (Money(10, 5) == Money(20, 10) ?
	          "Yes" : "No") << endl;

 	(Money(20, 10) * 2.2).output();

 	if ( divide(Money(20, 10), 0, m3) )
        m3.output();
    else
        cout << "cannot devide" << endl;
 	if ( divide(Money(20, 10), 2.5, m3) )
        m3.output();
    else
        cout << "cannot devide" << endl;

    (m1 + m2).output();

	m3 = m1 += Money(2, 95);
	m3.output();

	m3  = Money(45, 32) / 2.2;
	m3.output();
	m3  = Money(45, 32) / 0;
	m3.output();

	m3 = m1 -= Money(2, 95);
	m3.output();

	m3 = ++m1;
	m1.output();
	m3.output();
    m1 = Money(2, 99);
	m1.output();
	m3.output();

    cout << !m3 << endl;

	m3 = m1++;
	m1.output();
	m3.output();

	m3 = --m1;
	m1.output();
	m3.output();

	m3 = --m1;
	m1.output();
	m3.output();

	m3 = m1--;
	m1.output();
	m3.output();

	cout << "m1 + 95 Cents is $" << !(m1 + 95) << endl;
	cout << "95 Cents + m1 is $" << !(95 + m1) << endl;

	cout << "2.5 * m1 is $" << !(2.5 * m1) << endl;

 	cout << (Money(10, 5) < 10.06 ?
	          "Yes" : "No") << endl;
 	cout << (Money(10, 6) < 10.05 ?
	          "Yes" : "No") << endl;
 	cout << (10.06 < Money(10, 5) ?
	          "Yes" : "No") << endl;
 	cout << (10.05 < Money(10, 6)  ?
	          "Yes" : "No") << endl;

    return 0;
}

bool divide(const Money &a, double d, Money &b)
{
    if (d == 0.0)
        return (false);

	int total_cents = ( a.getDollars()*100 + a.getCents() )/d;
 	b = Money( total_cents/100, total_cents%100 );

 	return (true);
}
