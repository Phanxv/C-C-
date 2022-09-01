#include <iostream>

using namespace std;

int main()
{
    char grade = 'C';
    cout << "I got a " << grade
         << " from CPE-111." << endl;
    cout << "I hope I will not get a "
         << static_cast<char>(grade+1)
         << " from CPE-113." << endl;
    return 0;
}
