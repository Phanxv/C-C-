#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Shape
{
public:
    Shape(double w) : width(w) { }
    virtual double calArea() = 0;
    double width;
};

class Square : public Shape
{
public:
    Square(double w) : Shape(w) { }
    double calArea() { return width*width; }
};

class Circle : public Shape
{
public:
    Circle(double w) : Shape(w) { }
    double calArea() { return 0.7854*width*width; }
};

class Triangle : public Shape
{
public:
    Triangle(double w) : Shape(w) { }
    double calArea() { return 0.443*width*width; }
};

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    srand(time(0));
    Shape *sh[50];
    double usrInput;
    int randIndex;
    cout << "Enter the width of shape : " ;
    cin >> usrInput;
    randIndex = rand()%50;
    sh[randIndex] = new Triangle(usrInput);
    for(int i=0;i<50;i++){
            if(i!=randIndex){
                switch(rand()%2){
                    case 0 :
                        sh[i] = new Square(usrInput);
                        break;
                    case 1 :
                        sh[i] = new Circle(usrInput);
                        break;
                }
            }
    }
    for(int i=0;i<50;i++){
        cout << sh[i]->calArea() << endl;
    }
    for(int i=0;i<50;i++){
        delete sh[i];
        sh[i] = NULL;
    }
    return 0;
}
