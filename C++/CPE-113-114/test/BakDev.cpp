 #include <iostream>

 using namespace std;
 
 class Bak 
 {
    public: 
    Bak(int a) : mv(a) {}
    int foo() {return(mv/2);} 
    int goo() {return(mv+ 3);} 
    int mv; 
 };

class Dev : public Bak 
{
    public: 
    Dev() : Bak(10) {}
    int goo() {return(mv+3);}
};

int main(){
    Bak ba(22);
    Dev de;
    cout << ba.foo() << ", "
         << de.foo() << ", "
         << ba.goo() << ", "
         << de.goo();
}