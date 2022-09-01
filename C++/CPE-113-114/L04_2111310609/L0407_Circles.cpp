#include <iostream>
#include <cstring>

using namespace std;

const float PI = 3.14159;

class Circle{
    public :
        int x,y,radius;
        double calArea();
        double calPerimeter();
};

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    Circle a,b;
    cout << "Enter data for circle a\n"
         << "location x : ";
    cin >> a.x;
    cout << "location y : ";
    cin >> a.y;
    cout << "radius : ";
    cin >> a.radius;
    cout << "Enter data for circle b\n"
         << "location x : ";
    cin >> b.x;
    cout << "location y : ";
    cin >> b.y;
    cout << "radius : ";
    cin >> b.radius;

    cout << "\nCircle a locates at (" << a.x <<"," << a.y << "),"
         << " area is " << a.calArea() << ", perimeter is " << a.calPerimeter() << endl;
    cout << "Circle a locates at (" << b.x <<"," << b.y << "),"
         << " area is " << b.calArea() << ", perimeter is " << b.calPerimeter() << endl;
 }

 double Circle::calArea(){
     return PI*radius*radius;
 }

 double Circle::calPerimeter(){
     return PI*radius*2;
 }