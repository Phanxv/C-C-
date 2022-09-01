#include <iostream>
#include <string>

using namespace std;

class Steel{
    public : 
        Steel(){}
        Steel(int n) : hole(n/5), top(n%10) {}
        Steel(int n, int m) : hole(n-m), top(n+m) {}
        int getHole() {return (hole);}
        int getTop() {return (top);}
    private :
    int hole, top;
};

void show(Steel s){
    cout << "[" << s.getHole() << "," << s.getTop() << "] ";
}

int main(){
    Steel one(20,10), two;
    two = Steel(55);
    show(one);
    show(two);
}