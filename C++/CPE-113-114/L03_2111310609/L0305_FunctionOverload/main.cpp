#include <iostream>

using namespace std;

void foo();
void foo(int);
void foo(int, int);
void foo(int, double);
//void foo(double, int);

int main(){
    foo(7, 8);
    foo();
    foo(3);
    foo(2.5);
    //foo(7, 8.9);
    foo(7.5, 8);
    foo(7.5, 8.9);
}

void foo(){
    cout << "1st foo is invoked" << endl;
}

void foo(int var){
    cout << "2nd foo is invoked" << endl;
}

void foo(int var1, int var2){
    cout << "3rd foo is invoked" << endl;
}

void foo(int, double){
    cout << "4th foo is invoked" << endl;
}

/*void foo(double, int){
    cout << "5th foo is invoked" << endl;
}*/