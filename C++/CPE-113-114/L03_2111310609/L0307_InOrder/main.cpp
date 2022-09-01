#include <iostream>

using namespace std;

bool inOrder(int a, int b, int c);

int main()
{
    int stNum, ndNum, rdNum;
    cout << "Enter 3 numbers : ";
    cin >> stNum >> ndNum >> rdNum;
    if(inOrder(stNum,ndNum,rdNum))
        cout << "They are in order";
    else
        cout << "They are not in order";
    return 0;
}

bool inOrder(int a, int b, int c){
    return a<b && a<c && b<c;
}
