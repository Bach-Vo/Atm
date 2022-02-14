#include <iostream>
#include <ctime>
using namespace std;


int main(){
    char *cardN = new char [16];
    string cardBrand;
    srand(time(0));
    //leading digit
    switch (cardN[0] = rand()%5 +1)
    {
    case 1:
        cardN[0] = 4 + '0';
        cardBrand = "Visa";
        break;
    case 2:
        cardN[0] = 5 + '0';
        cardBrand = "Mastercard";
        break;
    case 3:
        cardN[0] = 6 + '0';
        cardBrand = "Discover";
        break;
    case 4:
        cardN[0] = 3 + '0';
        cardBrand = "American Express";
        break;
    case 5:
        cardN[0] = 8 + '0';
        cardBrand = "Voyager";
        break;
    }
    //the rest
    for (int i = 1; i < 15; i++)
    {
        cardN[i] = (rand() %9) + '0' ;
    }

    for (int i = 0; i < count   ; i++)
    {
        /* code */
    }
    
return 0;
}