#include <iostream>

using namespace std;

class Money
{
public:
    void setDollars(int);
    void  setCents(int);
    void  setBoth(int,int);
    int getDollars();
    int getCents();
    double getAmount();

private:
    int dollar,cent;
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
void Money::setDollars(int num){
    dollar = num;
}
void Money::setCents(int num1){
    cent = num1;
}
void Money::setBoth(int dollar1,int cent1){
    dollar = dollar1;
    cent = cent1;
}
int Money::getDollars(){
    return dollar;
}
int Money::getCents(){
    return cent;
}
double Money::getAmount(){
    return dollar+(cent/100.00)+(cent%100);
}
