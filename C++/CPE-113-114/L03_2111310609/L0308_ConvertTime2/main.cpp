#include <iostream>

using namespace std;

void secondToHms(int &sec, int &min, int &hour);

int main()
{
    int sec, min, hour;
    cout << "Enter seconds : ";
    cin >> sec;

    cout << sec << " seconds is equal to the time ";
    secondToHms(sec, min, hour);

    cout << hour << " hours " << min << " minutes " << sec << " seconds ";
    return 0;
}

void secondToHms(int &sec, int &min, int &hour){
    hour = sec/3600;
    sec -= hour*3600;
    min = sec/60;
    sec -= min*60;
}