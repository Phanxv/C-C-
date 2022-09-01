#include <iostream>

using namespace std;

int main()
{
    cout << 18/5 << ' '
         << 18.0/5 << ' '
         << 18/5.0 << ' '
         << 18.0/5.0 << ' '
         << (15+3.0)/5 << endl;

    int a = 18, b = 5;
    float c = 10.5;
    cout << a/b << ' '
         << static_cast<float>(a)/b << ' '
         << static_cast<int>(c)/b << endl;

    if ( c/2 == 5 )
        cout << "Yes." << endl;
    else
        cout << "No." << endl;
    if ( static_cast<int>(c/2) == 5 )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
