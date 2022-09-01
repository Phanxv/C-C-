#include <iostream>

using namespace std;

class DayOfYear{
    public : 
        void input();
        void output();
    private :
        int month;
        int day;      
};

int main(){
    DayOfYear today;
    today.input();
    today.output();
}

void DayOfYear::input(){
    cout << "Input Day : ";
    cin >> day;
    cout << "Input month : ";
    cin >> month;
}

void DayOfYear::output(){
    cout << day << "/" << month;
}