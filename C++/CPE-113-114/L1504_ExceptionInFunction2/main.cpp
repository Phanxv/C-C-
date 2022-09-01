#include <iostream>
#include <string>
using namespace std;

int getId(string name[], int id[], int num, string target);

int main()
{
    string productName[] = { "computer", "flash drive",
                            "mouse", "printer", "camera" };
    int productId[] = {0, 5, 8, 10, 13};
    try{
       cout << getId(productName, productId, 5, "mouse") << endl;
       cout << getId(productName, productId, 5, "camera") << endl;
       cout << getId(productName, productId, 5, "laptop") << endl;
    }
    catch(...){
        cout << "Product not found";
    }
   return 0;
}

int getId(string names[], int id[], int num, string target)
{
   for (int i=0; i < num; i++)
   {
      if (names[i] == target)
         return id[i];		// return the product id
   }

   throw 0;	// 0 is the exception, means product not found
}
