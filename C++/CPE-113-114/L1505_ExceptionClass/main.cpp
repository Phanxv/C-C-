#include <iostream>
#include "error.h"

using namespace std;

void input(int &);

int main()
{
    int num;
    try {
        input(num);
        cout << "The result is " << 100/num;
    }
    catch(error Error){
        cout << Error.getMessage();
    }
}

void input(int &num){
    cout << "Enter a number : ";
    cin >> num;
    if(num==0)
        throw error("Can not divide by zero");
}
