#include <iostream>

using namespace std;

int main()
{
    double num;
    cout << "Enter a number : ";
    cin >> num;
    cout << "Start//";

    try {
        if(num==0)
            throw num;
        cout << "The number is OK";
    }
    catch (...){
        cout << " Invalid input";
    }
    cout << " //End" << endl;
    return 0;
}
