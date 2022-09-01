#include <iostream>
#include <string>

using namespace std;

class Human
{
    public :
        Human(string n) : name(n) {cout << "A human is born named " << name << endl; }
        virtual void greet() {cout << "Hello" << endl;}
        string name;
};

class American : public Human
{
    public : 
        American(string n) : Human(n) {cout << "\t He is an American" << endl;}
        //void greet() {cout << "Hello, my name is " << name << ". I am American" << endl << endl;}
};

class Japanese : public Human{
    public :
        Japanese(string n) : Human(n) {cout << "\t He is a Japanese" << endl;}
        void greet() {cout << "Konnichiha Watashi ha " << name << " desu, Watashi ha nihonjin desu " << endl << endl;}
};

class Spanish : public Human{
    public :
        Spanish(string n) : Human(n) {cout << "\t He is a Spanish" << endl;}
        void greet() {cout << "Hola soy " << name << ". soy espanol." << endl << endl;}
};

void testGreet(Human testSubject);

int main(){
    Human man1("man");
    Human *ptrMan;
    ptrMan = &man1;
    ptrMan->greet();
    
    American chris("Chris");/*
    Japanese fushi("Fushi");
    Spanish juan("Juan");
    cout << endl;*/
    testGreet(chris);/*
    testGreet(&fushi);
    testGreet(&juan);
*/
    
}

void testGreet(Human testSubject){
    testSubject.greet();
}