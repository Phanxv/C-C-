#include <iostream>
#include <string>

using namespace std;

class Father{
    public :
        void Mutator(string n) {name = n;}
        string Accessor() {return name;}
    private :
        string name;
};

class Son : public Father{
    public :
        //Son(string n) {Mutator(n);}
    private :
};

int main(){
    Son Cat;
    cout << Cat.Accessor();
}