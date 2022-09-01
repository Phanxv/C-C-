#include <iostream>

using namespace std;

int main()
{
    int S, E, N, D, M, O, R, Y;
    cout << "Calculating" << endl << endl;
    for(S=1;S<10;S++){
        for(E=0;E<10;E++){
            for(N=0;N<10;N++){
                for(D=0;D<10;D++){
                    for(M=1;M<10;M++){
                        for(O=0;O<10;O++){
                            for(R=0;R<10;R++){
                                for(Y=0;Y<10;Y++){
                                    if ((((S*1000)+(E*100)+(N*10)+D) + ((M*1000)+(O*100)+(R*10)+E)) == ((M*10000)+(O*1000)+(N*100)+(E*10)+Y)
                                            && S!=E && S!=N && S!=D && S!=M && S!=O && S!=R && S!=Y && E!=N && E!=D && E!=M && E!=O && E!=R && E!=Y
                                            && N!=D && N!=M && N!=O && N!=R && N!=Y && D!=M && D!=O && D!=R && D!=Y
                                            && M!=O && M!=R && M!=Y && O!=R && O!=Y && R!=Y){
                                        cout << S << E << N << D << " + " << M << O << R << E << " = " << M << O << N << E << Y << endl << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Complete";
}
