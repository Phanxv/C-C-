#include <iostream>
#include <cstring>

using namespace std;

struct Shoes{
    char brand[50];
    char size;
    float price;
};

int main(){
    Shoes myShoes, yourShoes, hisShoes;
    float markUp;

    cout << "Enter data of the shoes\n"
         << "Brand : ";
    cin >> myShoes.brand;
    cout << "Size : ";
    cin >> myShoes.size;
    cout << "Price : ";
    cin >> myShoes.price;
    cout << "Enter data of the shoes\n"
         << "Brand : ";
    cin >> yourShoes.brand;
    cout << "Size : ";
    cin >> yourShoes.size;
    cout << "Price : ";
    cin >> yourShoes.price;
    cout << "\nEnter amput of markup : ";
    cin >> markUp;

    hisShoes = myShoes;
    hisShoes.price = myShoes.price + myShoes.price * markUp / 100;
    cout << "\nThe shoes is " << myShoes.brand << ", size is " << myShoes.size << " and it's cost " << myShoes.price << " baht" << endl
         << "The shoes is " << yourShoes.brand << ", size is " << yourShoes.size << " and it's cost " << yourShoes.price << " baht" << endl
         << "The shoes is " << hisShoes.brand << ", size is " << hisShoes.size << " and it's cost " << hisShoes.price << " baht" << endl;

    cout << "Your shoes is " << yourShoes.price - hisShoes.price << " baht more expensive than his shoes";
}