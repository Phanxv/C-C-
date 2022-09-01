#include <iostream>

using namespace std;

int main()
{
    //EAT+EAT+EAT+EAT=BEET
    //EAT*4=BEET
    int E, A, T, B;
    cout << "Calculating...\n";
    for(E=1;E<10;E++){
        for(A=0;A<10;A++){
            for(T=0;T<10;T++){
                for(B=1;B<10;B++){
                    if(((E*100+A*10+T)+(E*100+A*10+T)+(E*100+A*10+T)) == B*1000+E*100+E*10+T
                        && E!=A && E!=T && E!=B && A!=T && A!=B && T!=B){
                        cout << "The solution is " 
                             << E << A << T << " + " << E << A << T << " + " << E << A << T << " = " << B << E << E << T << endl;
                        break;
                    }
                }
            }
        }
    }
    cout << "Complete...\n";
    return 0;
}