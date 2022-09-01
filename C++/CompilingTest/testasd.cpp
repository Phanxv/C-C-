#include <iostream>
#include <string>

using namespace std;

class Dog{
    public : 
        Dog() : age(0), hairColor("NULL") {cout << "A dog is born" << endl;}
        Dog(int a, string hC) : age(a), hairColor(hC) {cout << "A dog is born" << endl;}
        string getName() {return name;}
        virtual void Bark() {cout << " ";}
        int age;
        string hairColor;
    protected :
        friend void assignName(string n, Dog &);
        friend Dog combineName(Dog &Dog1, Dog &Dog2);
        string name;
};

class Poodle : public Dog{
    public :
        Poodle() : Dog() {cout << "\tIt is a poodle";}
        Poodle(int a, string hC) : Dog(a,hC) {cout << "\tIt is a poodle";}
        /*overridden*/ void Bark() {cout << "Ahoy" << endl;}
};

class Golden : public Dog{
    public :
        Golden() : Dog() {cout << "\tIt is a Golden";}
        Golden(int a, string hC) : Dog(a,hC) {cout << "\tIt is a Golden";}
        void Bark() {cout << "Woy" << endl;}
};


class Lucky : public Poodle{

};

void testBark(Dog &Dog1);
void assignName(string n, Dog &);
Dog combineName(Dog &Dog1, Dog &Dog2);

int main(){
    //Dog Dog1(69,"White");
    //cout << endl << Dog1.hairColor;
    Dog *ptrDog;
    Poodle Poodle1(420,"Green");
    ptrDog = &Poodle1;
    cout << endl << ptrDog->hairColor << endl;
    Golden GD1(1,"Golden");
    Poodle1.Bark();
    GD1.Bark();
    testBark(Poodle1);
    assignName("Lucky", Poodle1);
    cout << Poodle1.getName();
    Dog Dog2;
    Dog2 = combineName(Poodle1,GD1);
    cout << Dog2.getName();
}

void testBark(Dog &Dog1){
    Dog1.Bark();
}

void assignName(string n, Dog &Dog1){
    Dog1.name = n;
}

Dog combineName(Dog &Dog1, Dog &Dog2){
    return Dog(0,(Dog1.getName() + Dog2.getName()));
}