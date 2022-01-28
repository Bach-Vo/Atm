#include <iostream>

using namespace std;
int main(){
    char *transferMes;
    transferMes = new char [100];
    cout << "(optional)[100 char]\nMessage: ";
    cin.get(transferMes, 100, '\n');
    cout << transferMes;
}