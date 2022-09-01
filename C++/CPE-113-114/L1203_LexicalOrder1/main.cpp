#include <iostream>
#include <string>


using namespace std;

int main()
{
    string word1, word2, word3, resultWord;
    cout << "Enter 3 words: ";
    cin >> word1 >> word2 >> word3;
    if(word1 < word2 && word1 < word3)
    {
        if(word2 < word3)
        {
            word1 += "/" + word2 + "/" + word3;
            resultWord = word1;
        }
        else
        {
            word1 += "/" + word3 + "/" + word2;
            resultWord = word1;
        }
    }
    else if(word2 < word1 && word2 < word3)
    {
        if(word1 < word3)
        {
            word2 += "/" + word1 + "/" + word3;
            resultWord = word2;
        }
        else
        {
            word2 += "/" + word3 + "/" + word1;
            resultWord = word2;
        }
    }
    else
    {
        if(word1 < word2)
        {
            word3 += "/" + word1 + "/" + word2;
            resultWord = word3;
        }
        else
        {
            word3 += "/" + word2 + "/" + word1;
            resultWord = word3;
        }
    }
    cout << endl;
    cout << "The result word is\n" << "    " << resultWord << endl;
}
