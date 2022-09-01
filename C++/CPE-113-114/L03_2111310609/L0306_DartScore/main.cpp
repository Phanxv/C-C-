#include <iostream>

using namespace std;

float calScore(int score1, int score2, int score3);

int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    int score1, score2, score3;
    cout << "Enter raw score :" << endl;
    cout << "\tRound 1 : ";
    cin >> score1;
    cout << "\tRound 2 : ";
    cin >> score2;
    cout << "\tRound 3 : ";
    cin >> score3;

    cout << "\nThe net score is " << calScore(score1,score2,score3);

    return 0;
}

float calScore(int score1, int score2, int score3){
    if(score1 < score2 && score1 < score3)
        return (score2+score3)/2.0;
    else if(score2 < score3)
        return (score1+score3)/2.0;
    else
        return (score1+score2)/2.0;

}