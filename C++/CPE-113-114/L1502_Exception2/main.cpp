#include <iostream>

using namespace std;

int main()
{
    int num, result;
    /*cout << "Enter a number : ";
    cin >> num;*/
    try {
        cout << "Enter a number : ";
        cin >> num;
        if(num==0)
            throw num;
        result = 100/num;
        cout << "The result is " << result;
    }
    catch(...){
        cout << "Error : Can not divide by zero";
    }
}
