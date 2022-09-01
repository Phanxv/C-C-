#include <iostream>
#include <cstring>

using namespace std;

struct Shoes{
    char brand[50];
    char size;
    float price;
};

Shoes input();
void output(Shoes);
void copy(Shoes &, Shoes &);
void markup(Shoes &);
void calDifferent(Shoes, Shoes);

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    Shoes myShoes, yourShoes, hisShoes;

    myShoes = input();
    yourShoes = input();
    copy(myShoes,hisShoes);

    markup(hisShoes);

    output(myShoes);
    output(yourShoes);
    output(hisShoes);

    calDifferent(hisShoes, yourShoes);
}

Shoes input(){
    Shoes inputShoes;
    cout << "Enter data of the shoes\n"
         << "Brand : ";
    cin >> inputShoes.brand;
    cout << "Size : ";
    cin >> inputShoes.size;
    cout << "Price : ";
    cin >> inputShoes.price;
    return inputShoes;
}

void output(Shoes outputShoes){
    cout << "\nThe shoes is " << outputShoes.brand 
         << ", size is " << outputShoes.size 
         << " and it's cost " << outputShoes.price << " baht" << endl;
}

void markup(Shoes &markUpShoes){
    float markUp;
    cout << "\nEnter input of markup : ";
    cin >> markUp;
    markUpShoes.price = markUpShoes.price + markUpShoes.price * markUp / 100;  
}

void calDifferent(Shoes shoes1, Shoes shoes2){
    cout << "\nYour shoes is " << shoes2.price - shoes1.price << " baht more expensive than his shoes";
}

void copy(Shoes &shoes1, Shoes &shoes2){
    shoes2 = shoes1;
}