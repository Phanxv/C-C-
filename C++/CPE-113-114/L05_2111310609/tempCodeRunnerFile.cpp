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
        double amount;
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
    amount += InputDollars;
}

void Money::setCents(int InputCents){
    amount += InputCents/100.0;
}

int Money::getDollars(){
    return amount/1;
}

int Money::getCents(){
    return static_cast<int>(amount*100)%100;
}

void Money::setBoth(int InputDollars, int InputCents){
    amount += InputDollars;
    amount += InputCents/100.0; 
}

double Money::getAmount(){
    return amount;
}