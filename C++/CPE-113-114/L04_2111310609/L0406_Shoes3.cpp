#include <iostream>
#include <cstring>

using namespace std;

class Shoes{
    public : 
        char brand[50];
        char size;
        float price;
        void input();
        void output();
        void copy(Shoes &);
        void markup();
        void calDifferent(Shoes);
};

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    Shoes myShoes, yourShoes, hisShoes;

    myShoes.input();
    yourShoes.input();
    hisShoes.copy(myShoes);

    hisShoes.markup();

    myShoes.output();
    yourShoes.output();
    hisShoes.output();

    hisShoes.calDifferent(yourShoes);
}

void Shoes::input(){
    cout << "Enter data of the shoes\n"
         << "Brand : ";
    cin >> brand;
    cout << "Size : ";
    cin >> size;
    cout << "Price : ";
    cin >> price;
}

void Shoes::output(){
    cout << "\nThe shoes is " << brand 
         << ", size is " << size 
         << " and it's cost " << price << " baht" << endl;
}

void Shoes::markup(){
    float markUp;
    cout << "\nEnter input of markup : ";
    cin >> markUp;
    price = price + price * markUp / 100;  
}

void Shoes::calDifferent(Shoes shoes2){
    cout << "\nYour shoes is " << shoes2.price - price << " baht more expensive than his shoes";
}

void Shoes::copy(Shoes &shoes){
    strcpy(brand,shoes.brand);
    price = shoes.price;
    size = shoes.size;
}