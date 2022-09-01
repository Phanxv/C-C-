#include <iostream>

using namespace std;

bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month,int year);

int main(){
    int day, month, year, weekDay;
    cout << "\nEnter the date\n"
         << "\tDay (1-31) : ";
    cin >> day;
    cout << "\tMonth (1-12) : ";
    cin >> month;
    cout << "\tYear (in AD) : ";
    cin >> year;
    weekDay = (day + getMonthValue(month,year) + getYearValue(year) + getCenturyValue(year)) % 7;
    cout << "\nThe day of the week of " << day << "-" << month << "-" << year << " is ";
    switch(weekDay){
        case 0 :
            cout << "Sunday";
            break;
        case 1 :
            cout << "Monday";
            break;
        case 2 :
            cout << "Tuesday";
            break;
        case 3 :
            cout << "Wednesday";
            break;
        case 4 :
            cout << "Thursday";
            break;
        case 5 :
            cout << "Friday";
            break;
        case 6 :
            cout << "Saturday";
            break;
    }
}

bool isLeapYear(int year){
    return (year%4 == 0||(year%4==0 && year%100 != 0));
}

int getCenturyValue(int year){
    return (3-((year/100)%4))*2;
}

int getYearValue(int year){
    return ((year%100)/4)+(year%100);
}

int getMonthValue(int month,int year){
    if(month==1&&isLeapYear(year)==false)
        return 0;
    if(month==1&&isLeapYear(year)==true) 
        return 6;
    if(month==2&&isLeapYear(year)==false)
        return 3;
    if(month==2&&isLeapYear(year)==true)
        return 2;
    if(month==3)
        return 3;
    if(month==4)
        return 6;
    if(month==5)
        return 1; 
    if(month==6)
        return 4; 
    if(month==7)
        return 6;
    if(month==8)
        return 2; 
    if(month==9)
        return 5;
    if(month==10)
        return 0;
    if(month==11)
        return 3;
    if(month==12)
        return 5;
}