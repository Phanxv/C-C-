#include <iostream>
#include <cmath>

using namespace std;

class Body{
    public :
        Body() : weight(0), height(0) {}
        Body(double w, double h) 
            {weight = w>0?w:abs(w); height = h>0?h:abs(h);}
        void setBoth(double w, double h) 
            {weight = w>0?w:abs(w); height = h>0?h:abs(h);}
        double getWeight() {return weight;}
        double getHeight() {return height;}
        double calDiffBmi(Body a, Body b)
            {return abs(a.calBmi() - b.calBmi());}
    private :
        double calBmi(){return weight/pow(height,2);}
        double weight, height;
};

int main(){
    Body b1(63,1.78), b2(49,1.58);
    cout << "weight : " << b1.getWeight() <<endl
         << "height : " << b1.getHeight() <<endl
         << "BMI difference : " << b1.calDiffBmi(b1,b2);
}