#include <iostream>

using namespace std;

void input(int &);

int main()
{
    int num;
    try {
        input(num);
        cout << "The result is " << 100/num;
    }
    catch(...){
        cout << "Error : Can not divide by zero";
    }
}

void input(int &num){
    cout << "Enter a number : ";
    cin >> num;
    if(num==0)
        throw num;
}
