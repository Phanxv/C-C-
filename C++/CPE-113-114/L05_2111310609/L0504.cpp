#include <iostream>
#include <cstring>

using namespace std;

class Temperature{
    public : 
        void setTempCelsius(double);
        void setTempFarenheit(double);
        void setTempKelvin(double);
        double getTempCelsius();
        double getTempFarenheit();
        double getTempKelvin();
    private :
        double tempCelsius;
};

int main(){
    Temperature T1,T2,T3;
    T1.setTempCelsius(37);
    T2.setTempFarenheit(98.6);
    T3.setTempKelvin(310.15);

    cout << "WHen set temperature to 37 degree Celsius." << endl
         << "It is " << T1.getTempCelsius() << " degree Celsius." << endl
         << "It is " << T1.getTempFarenheit() << " degree Farenheit." << endl
         << "It is " << T1.getTempKelvin() << " degree Kelvin." << endl
         << "WHen set temperature to 98.6 degree Farenheit." << endl
         << "It is " << T2.getTempCelsius() << " degree Celsius." << endl
         << "It is " << T2.getTempFarenheit() << " degree Farenheit." << endl
         << "It is " << T2.getTempKelvin() << " degree Kelvin." << endl
         << "WHen set temperature to 310.15 degree Kelvin." << endl
         << "It is " << T3.getTempCelsius() << " degree Celsius." << endl
         << "It is " << T3.getTempFarenheit() << " degree Farenheit." << endl
         << "It is " << T3.getTempKelvin() << " degree Kelvin." << endl;
}

void Temperature::setTempCelsius (double Celsius){
    tempCelsius = Celsius;
}

void Temperature::setTempFarenheit (double Farenheit){
    tempCelsius = (Farenheit-32)/1.8;
}

void Temperature::setTempKelvin (double Kelvin){
    tempCelsius = Kelvin - 273.15;
}

double Temperature::getTempCelsius(){
    return tempCelsius;
}

double Temperature::getTempFarenheit(){
    return tempCelsius * 1.8 + 32;
}

double Temperature::getTempKelvin(){
    return tempCelsius + 273.15;
}