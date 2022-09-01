#include <iostream>
#include <string>

using namespace std;

int main(){
    int x = 10; //save to stack memory.
    int *num = new int; //save to heap memory 4 byte
    *num = 5;
    //cout << *num;
    delete num;
    num = NULL;
    num = &x;
    cout << *num;
}

