#include <iostream>
#include <string>

using namespace std;

class Body{
    public :
        Body(double w, double h) : wgh(w), hgh(h) {}
        void reset() {wgh = hgh = 1.0;}
        virtual double calResult() = 0;
        double getWgh() {return wgh;}
        double getHgh() {return hgh;}
    private :
        double wgh, hgh;
};

class BodyMass : public Body{
    public :
        BodyMass(double w, double h) : Body(w,h) {}
        /*overridden*/ double calResult() {return (getWgh()/(getHgh()*getHgh()));}
};

class BodyWeight : public Body{
    public :
        BodyWeight(double w, double h) : Body(w,h) {}
        /*overridden*/ double calResult() {return (getWgh()-getHgh()+107.5/getWgh());}
};

int main(){
    BodyWeight b1(55,1.63);
    BodyMass b2(55,1.63);
    cout << b1.getWgh() << " " << b1.getHgh() << endl
         << b2.getWgh() << " " << b2.getHgh() << endl
         << b1.calResult() << " " << b2.calResult() << endl;
    b1.reset();b2.reset();
    cout << b1.getWgh() << " " << b1.getHgh() << endl
         << b2.getWgh() << " " << b2.getHgh() << endl;
    
}
