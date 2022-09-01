#include <iostream>

using namespace std;

class Fraction{
    public :
        Fraction();
        Fraction(int nume,int deno);
        void setNumerator(int nume) {numerator = nume;}
        void setDenominator(int deno);
        void setBoth(int nume, int deno);
        double getValue();
        double getNumerator();
        double getDenominator();
        Fraction multiply(Fraction a,Fraction b);
    private :
        int numerator;
        int denominator;
};

Fraction add(Fraction a, Fraction b);

int main(){

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    Fraction Frac1, Frac2(3,4);
    int nume,deno;

    cout << "Enter first fraction data \n\tnumerator : ";
    cin >> nume;
    cout << "\tdenominator : ";
    cin >> deno;

    Frac1.setNumerator(nume);
    Frac1.setDenominator(deno);

    cout << "The first fraction gives " << Frac1.getValue() << endl
         << "The second fraction gives " << Frac2.getValue() << endl
         << "The multiplication gives " << Frac1.multiply(Frac1,Frac2).getValue() << endl
         << "The addition gives " << add(Frac1,Frac2).getValue() << endl;
}

Fraction::Fraction()  : numerator(0), denominator(1) {}

Fraction::Fraction(int nume,int deno){
    denominator = deno==0?1:deno;
    numerator = deno==0?0:nume;
}

void Fraction::setDenominator(int deno){
    denominator = deno==0?1:deno;
    numerator = deno==0?0:numerator;
}

void Fraction::setBoth(int nume, int deno){
    numerator = deno==0?0:nume;
    denominator = deno==0?1:deno;
}

double Fraction::getValue(){
    return static_cast<double>(numerator) / denominator;
}

double Fraction::getNumerator(){
    return numerator;
}

double Fraction::getDenominator(){
    return denominator;
}
Fraction Fraction::multiply(Fraction a,Fraction b){
    return Fraction(a.numerator * b.numerator,a.denominator * b.denominator);
}

Fraction add(Fraction a, Fraction b){
    return Fraction(a.getNumerator()*b.getDenominator() + b.getNumerator()*a.getDenominator(), a.getDenominator()*b.getDenominator());
}
