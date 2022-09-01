#include <iostream>

using namespace std;

class Fraction
{
public:
    Fraction() : numerator(0), denominator(1) { }
    Fraction(int n, int d)
        : numerator(d == 0 ? 0 : n), denominator(d == 0 ? 1 : d)
    { }
    void setNumerator(int n) { numerator = n; }
    void setDenominator (int d) {
        numerator = d == 0 ? 0 : numerator;
        denominator = d == 0 ? 1 : d;
    }
    void setBoth (int n, int d)
    {   numerator = d == 0 ? 0 : n;
        denominator = d == 0 ? 1 : d;
    }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    double getValue() const
    { return static_cast<double>(numerator)/denominator; }

    const Fraction operator*(const Fraction &) const;
    const Fraction operator+(const Fraction &) const;
    const Fraction operator/(const Fraction &) const;

private:
	int numerator;
	int denominator;
};

int main()
{
	Fraction f1(2, 5), f2;
	int num, denom;

	cout << "Enter the 2nd fraction data" << endl
         << "  numerator: ";
	cin >> num;
	cout << "  denomerator: ";
	cin >> denom;

    f2.setBoth(num, denom);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

	cout << endl
	     << "The first fraction gives " << f1.getValue() << endl
	     << "The second fraction gives " << f2.getValue() << endl
	     << "The multiplication gives " << (f1*f2).getValue() << endl
	     << "The addition gives " << (f1+f2).getValue() << endl;
    try{
        cout << "The division gives " << (f1/f2).getValue() << endl;
    }
    catch(int){
        cout << "Can not divide" << endl;
    }

    return 0;
}

const Fraction Fraction::operator*(const Fraction &f) const
{
    return Fraction( numerator * f.numerator, denominator * f.denominator);
}

const Fraction Fraction::operator+(const Fraction &f) const
{
    return Fraction(
          getNumerator() * f.getDenominator() + f.getNumerator() * getDenominator(),
          getDenominator() * f.getDenominator() );
}

const Fraction Fraction::operator/(const Fraction &f) const
{
    if(getDenominator() * f.getNumerator() == 0)
        throw 0;
    return Fraction(getNumerator() * f.getDenominator(), getDenominator() * f.getNumerator());
}

