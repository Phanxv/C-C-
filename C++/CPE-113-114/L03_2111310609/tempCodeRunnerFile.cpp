#include <iostream>

using namespace std;

bool inOrder(int a, int b, int c);

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << inOrder(a,b,c);
}

bool inOrder(int a, int b, int c){
    return a < b && b < c;
}