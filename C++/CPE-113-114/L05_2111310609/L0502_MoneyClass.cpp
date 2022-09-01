#include <iostream>

using namespace std;

class Money
{
    public: 
        void setDollars(int);
        void setCents(int);
        void setBoth(int, int);
        int getDollars();
        int getCents();
        double getAmount();
    private:
        int Dollars;
        int Cents;
};

int main()
{
	Money m1, m2;

	m1.setDollars(7);
	m1.setCents(235);
	cout << "Money object 1 has " << m1.getDollars()
	     << " Dollars and " << m1.getCents()
	     << " Cents." << endl
	     << "It's equal to $" << m1.getAmount()
	     << '.' << endl;

	m2.setBoth(8, 472);
	cout << "Money object 2 has " << m2.getDollars()
	     << " Dollars and " << m2.getCents()
	     << " Cents." << endl
	     << "It's equal to $" << m2.getAmount()
	     << '.' << endl;
	return 0;
}

void Money::setDollars(int InputDollars){
    Dollars = InputDollars;
}

void Money::setCents(int InputCents){
    Cents = InputCents;
}

int Money::getDollars(){
    return Dollars;
}

int Money::getCents(){
    return Cents;
}

void Money::setBoth(int InputDollars, int InputCents){
    Dollars = InputDollars;
    Cents = InputCents; 
}

double Money::getAmount(){
    return Dollars + Cents/100 + Cents%100/100.0;
}
