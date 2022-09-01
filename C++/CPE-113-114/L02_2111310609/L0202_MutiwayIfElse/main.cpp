#include <iostream>

using namespace std;

int main()
{
    int a,b,c,largest;
    cout << "Enter 3 numbers : " << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if(a>b&&a>c){
        largest = a;
    }
    else if(b>a&&b>c){
        largest = b;
    }
    else{
        largest = c;
    }
    cout << "The largest is " << largest;
    return 0;
}
