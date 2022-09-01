#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void f1(const string &);
const string f2();
void f3(string &);

int main()
{
    char cs1[40], cs2[] = "Tell me and I may forget.";
    string s1, s2("Teach me and I remember."), s3(cs2), s4(s2);
    cout << "cs1: " << cs1 << endl;
    cout << "cs2: " << cs2 << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    strcpy(cs1, "Involve me and I learn.");
    cout << "cs1: " << cs1 << endl;
    s1 = "Challenge me and I grow.";
    cout << "s1: " << s1 << endl;
    strcpy(cs2, s2.c_str());
    cout << "cs2: " << cs2 << endl;
    cout << "\n";
    strcpy(cs2, cs1);
    s1 = cs1;
    s2 = s1;
    cout << "cs2: " << cs2 << endl;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "\n";
    cout << "cs1 and cs2 are ";
    if(strcmp(cs1, cs2) == 0)
        cout << "match";
    else
        cout << "not match";
    cout << endl;
    cout << "s1 and s2 are ";
    if(s1 == s2)
        cout << "match";
    else
        cout << "not match";
    cout << endl;
    cout << "s1 and cs1 are ";
    if(s1 == cs1)
        cout << "match";
    else
        cout << "not match";
    cout << endl;
    cout << "cs1 and s1 are ";
    if(cs1 == s1)
        cout << "match";
    else
        cout << "not match";
    cout << endl;
    if(s3 > s4)
        cout << "s3 has more than s4";
    else
        cout << "s4 has more than s3 ";
    cout << endl;
    strcat(cs1, " --B. Franklin");
    cout << "cs1: " << cs1 << endl;
    s1 = s1 + " --B. Franklin";
    cout << "s1: " << s1 << endl;
    cout << "\n";
    f1(s1);
    //cout << "\n";
    cout << f2() << endl;
    f3(s1);
    cout << s1 << endl;
    int i, n;
    n = s2.length();
    for(i = n-1; i >= 0; i -= 2)
        cout << s2[i] << ' ';
    cout << endl;
    cout << "\n";
    /*cout << "Enter some words: ";
    getline(cin, s1);
    cout << s1 << endl;*/
    cout << "Enter some other words: ";
    cin.getline(cs1, 10);
    cout << cs1 << endl;


}

void f1(const string &s)
{
    cout << '\"' << s << "\" is cout by f1" << endl;
}

const string f2()
{
    string s("This is a new string from f2");
    return(s);
}

void f3(string &s)
{
    s = '\"' + s + "\" is changed in f3";
}
