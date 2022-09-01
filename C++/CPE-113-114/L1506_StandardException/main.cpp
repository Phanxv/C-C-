#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    string full_string("A quick brown fox"), sub_string;
    int pos = 0;
    int length = full_string.length();
    cout << "Test string: \"" << full_string << '\"'
         << endl << "Length of characters: "
         << full_string.length() << endl << endl;

    cin.exceptions(cin.failbit);
    while (pos != -1){
        try{
        cout << "Enter start position (-1 for exit): ";
        cin >> pos;


        if (pos != -1){
            sub_string = full_string.substr(pos, 5);
            cout << '\"' << sub_string << '\"' << endl << endl;
           }
        }
        catch (runtime_error &e){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: \"" << e.what()
                 << "\", try again" << endl << endl;
        }
        catch (const exception &e){
            cout << "Error: \"" << e.what()
                 << "\", try again" << endl << endl;
        }
    }
    cout << endl << "Program end normally" << endl;

    return 0;
}
