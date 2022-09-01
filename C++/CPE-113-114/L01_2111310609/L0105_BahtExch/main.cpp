#include <iostream>

using namespace std;

int main()
{
    int item;
    float rate, baht;
    const float THBUSD = 30.93, THBCNY = 5.10, THBJPY = 0.3816;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "======================" << endl
	     << "Money Exchange Program" << endl
	     << "======================" << endl
	     << "1. US (Dollar)" << endl
	     << "2. Chinese (Yuan)" << endl
	     << "3. Japanese (Yen)" << endl
	     << "Any number: Other currency" << endl
	     << endl;

	cout << "Select the currency: ";
	cin >> item;

	switch (item)
	{
		case 1:
		    rate = THBUSD;
			cout << "Exchange rate is " << rate
			     << " Baht for 1 Dollar" << endl << endl;
			cout << "Enter amount in Baht: ";
			cin >> baht;
			cout << "Amount in Dollar is " << baht/rate;
			break;
		case 2:
		    rate = THBCNY;
			cout << "Exchange rate is " << rate
			     << " Baht for 1 Yuan" << endl << endl;
			cout << "Enter amount in Baht: ";
			cin >> baht;
			cout << "Amount in Yuan is " << baht/rate;
			break;
		case 3:
		    rate = THBJPY;
			cout << "Exchange rate is " << rate
			     << " Baht for 100 Yen" << endl << endl;
			cout << "Enter amount in Baht: ";
			cin >> baht;
			cout << "Amount in Yen is " << baht/rate;
			break;
		default:
			cout << "Enter the exchange rate: ";
			cin >> rate;
			cout << endl;
			cout << "Enter amount in Baht: ";
			cin >> baht;
			cout << "Amount in your currency is " << baht/rate;
	}

	cout << endl << endl;

    return 0;
}
