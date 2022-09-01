#include <iostream>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
    int N, i, score = 0, totalScore = 0, input;
    cout << "How many exercises to input? ";
    cin >> N;
    cout << endl;
    for(i=1;i<=N;i++){
        cout << "Score received for exercise "
             << i << " : ";
        cin >> input;
        score += input;
        cout << "Total points possible for exercise "
             << i << " : ";
        cin >> input;
        cout << endl;
        totalScore += input;
    }
    cout << "Your total is " << score
         << " out of " << totalScore << ", or "
         << (float)score/totalScore*100 << "%"
         << endl;
}
