#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Circle{
    public :
        int x,y,radius;
        double calArea();
        double calPerimeter();
        void isCollision(Circle);
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
    
    a.isCollision(b);
}

 double Circle::calArea(){
     return M_PI*radius*radius;
 }

 double Circle::calPerimeter(){
     return M_PI*radius*2;
 }

void Circle::isCollision(Circle b){
    double l;
    l = sqrt(pow(x-b.x, 2)+pow(y-b.y, 2));
    if(l<radius+b.radius)
        cout << "\nThey are collide.";
    else 
        cout << "\nThey are not collide.";
}