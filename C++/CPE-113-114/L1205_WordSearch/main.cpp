#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string sentense = "A quick brown fox jump over a red fox and its child, a baby fox.",
           word = "fox";
    cout << "\"fox\" first appears at index " << sentense.find(word) << endl
         << "After index 20, \"fox\" appears in index " << sentense.find(word,20) << endl
         << "Any character in \"fox\" first appears at index " << sentense.find_first_of(word) << endl
         << "Any character in \"fox\" do not first appears at index  " << sentense.find_first_not_of(word) << endl;
}
