#include <iostream>

using namespace std;

int main()
{
    int celsius = 100, fahrenheit;
    while(celsius != fahrenheit){
        celsius--;
        fahrenheit = ((9.0/5.0)*celsius)+32;
    }
    cout << "The temperature that is the same in Celsius and Fahrenheit is "
         << celsius;
}
