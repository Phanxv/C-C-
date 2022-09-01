#include <iostream>
#include <string>

using namespace std;

class Human
{
    public :
        Human(string n) : name(n) {cout << "A human is born named " << name << endl; }
        virtual void greet() = 0;
        string name;
};

class American : public Human
{
    public :
        American(string n) : Human(n) {cout << "\t He is an American";}
        void greet();
};

int main(){
    American max("max");
}
