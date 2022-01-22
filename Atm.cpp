#include "Atm.h"
#include <iostream>
using namespace std;

Atm::Atm(){
    cout << "Gonna do sum bout it";
}

//Printers
void Atm::menu(){
    system("cls");
    cout << "\n******************** WELCOME TO THE BANK ******************** "<< '\n'<<'\n';
    cout << "1)     My Accounts" << '\n';
    cout << "2)     Transfer" << '\n';
    cout << "3)     Pay Bills" << '\n';
    cout << "4)     Deposits" << '\n';
    cout << "5)     Sign out" << '\n';
}
void Atm::accMenu(){
    system("cls");
    cout << "\n******************** My Accounts ******************** "<< '\n'<<'\n';
    cout << "Card #" << /*cardNum*/  '\n';
    cout << "Balance: " << '\n';
    cout << "History: " << '\n';
    cout << "Manage Accout" << '\n';
    cout << "<- BACK" << '\n';
    cout << "Sign out" << '\n';
}
void Atm::userOption(){
    int option;
    cout << "Enter your option: ";
    cin >> option;
    switch (option)
    {
    case 1:
        cout << "My Accounts";
        accMenu();
        break;
    case 2:
        cout << "Transfer" << '\n';
    case 3:
        cout << "Pay Bills" << '\n';
    case 4:
        cout << "Deposits" << '\n';
    case 5: 
        cout << "Sign out" << '\n';
    default:
        break;
    }
}



