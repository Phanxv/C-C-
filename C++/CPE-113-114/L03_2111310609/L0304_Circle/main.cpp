#include <iostream>

using namespace std;

void calCircle(float radius, float &area, float &circumference);

const float PI = 3.1416;

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    float radius, area, circum;

    cout << "Enter the radius : ";
    cin >> radius;

    calCircle(radius, area, circum);

    cout << endl
         << "The parameter is " << circum << endl
         << "The area is " << area;

    return 0;
}

void calCircle(float radius, float &area, float &circumference){
    area = PI*radius*radius;
    circumference = 2*PI*radius;
}