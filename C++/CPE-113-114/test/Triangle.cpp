#include <iostream>

using namespace std;

class Triangle{
    friend void output(Triangle);
    public:
        Triangle() : width(0), height(0) {}
        double calArea() {return 0;}
    protected :
        double calPerimeter();
        double width, height;
};

class Prism : public Triangle{
    public :
        double calPerimeter();
        double calVolume();
        bool isSymmetry();
        double length;
};

int main(){
    Triangle tr;
    Prism ps;
    double d = tr.calVolume();
}