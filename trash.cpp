#include <iostream>
#include <ctime>
using namespace std;



void otho(){
    int i = 0;
    if (i == 0)
    {
        throw i;
    }
    
}
int main(){

    try
    {
        otho();
    }
    catch(int& e)
    {
        cout << "s" << endl;
    }
    
}