#include <iostream>

using namespace std;

class Ring{
    public :
        bool setRadiuses(double , double);
        double calArea();
    private :
        double r_inner;
        double r_outer;
};

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double r_in, r_out;
    Ring ring;
    
    cout << "Enter inner radius : ";
    cin >> r_in;
    cout << "Enter outer radius : ";
    cin >> r_out;
    if(ring.setRadiuses(r_in,r_out))
        cout << "It's area is " << ring.calArea();
    else
        cout << "Can not calculate area";
}

bool Ring::setRadiuses(double r_in, double r_out){
    if(r_in < r_out)
        r_inner = r_in; r_outer = r_out;
    return r_in < r_out;
}

double Ring::calArea(){
    return 3.1416 * ( r_outer*r_outer - r_inner*r_inner);
}