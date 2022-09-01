#include <iostream>

using namespace std;

double LandPriceCalc(double area, double price);
double LandPriceCalc(double width, double height, double price);

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double area,width,height,price;

    cout << "Enter area of the land : " ;
    cin >> area;
    cout << "Enter price of the land : ";
    cin >> price;
    cout << endl << "This land costs " << LandPriceCalc(area,price) << " Bahts" << endl << endl;
    cout << "Enter widht of the land : " ;
    cin >> width;
    cout << "Enter height of the land : " ;
    cin >> height;
    cout << "Enter price of the land : ";
    cin >> price;
    cout << endl << "This land costs " << LandPriceCalc(width,height,price) << " Bahts" << endl << endl;
}

double LandPriceCalc(double area, double price){
    return area*price;
}

double LandPriceCalc(double width, double height, double price){
    return width*height*price;
}