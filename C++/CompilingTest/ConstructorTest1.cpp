#include <iostream>
#include <cstdlib>

using namespace std;

class DayOfYear{
    public :
        DayOfYear(int inputDay, int inputMonth, int inputYear);
        int getDay();
        int getMonth();
        int getYear();
    private :
        int day;
        int month;
        int year;
};

int main(){
    DayOfYear BirthDay(26,6,2003);
    cout << "My birthday is " << BirthDay.getDay() << "/" << BirthDay.getMonth() << "/" << BirthDay.getYear() << endl;
}

DayOfYear::DayOfYear(int inputDay, int inputMonth, int inputYear){
    day = inputDay;
    month = inputMonth;
    year = inputYear;
}

int DayOfYear::getDay(){
    return day;
}

int DayOfYear::getMonth(){
    return month;
}

int DayOfYear::getYear(){
    return year;
}