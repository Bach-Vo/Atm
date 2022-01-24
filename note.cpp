#include <iostream>
#include <ctime>
using namespace std;

int main(){
    char card[16] = "";
    srand(time(0));
    for (int i = 0; i < 16; i++)
    {
        card[i] = rand() %2 ;
        cout << card[i] + 0 << '\t' << i<<  endl;
    }
return 0;
}