#include "Atm.h"
#include <iostream>
#include <ctime>
/*srand(time(0));
int some = rand() %3 */
using namespace std;

Atm::Atm(){
    balance = 100;
    cardNum = new char [16];
    cardNumGenerator(cardNum);
}
//generators
void Atm::cardNumGenerator(char *cardN){
    srand(time(0));
    for (int i = 0; i < 16; i++)
    {
        cardN[i] = (rand() %9) + '0' ;
    }
        cout << "cardN: " << cardN<< endl;
}
//setters
void Atm::withdraw(double withdrawAmount){
    if (withdrawAmount <= balance)
    {
        balance -= withdrawAmount;
        cout << "Current balance: $" << balance;
    }
    else
        cout << "You're broke";
}
void Atm::deposit(double depositAmount){
    balance += depositAmount;
    cout << "Current balance: $" << balance;
}

//Printers
void Atm::menu(){
    system("cls");
    cout << "\n************** WELCOME TO THE BANK ************** "<< '\n'<<'\n';
    cout << "1)     My Accounts" << '\n';
    cout << "2)     Transfer" << '\n';
    cout << "3)     Withdraw" << '\n';
    cout << "4)     Deposits" << '\n';
    cout << "5)     Sign out" << '\n';
    cout << "*************************************************" << endl;
    userMenuOption();       //should merge into 1 function or seperate between display & option functions
}
void Atm::accMenu(){
    system("cls");
    cout << "\n*********** My Accounts ***********"<< '\n'<<'\n';
    cout << "Card #" << cardNum << '\n';
    cout << "Balance: $" << balance << '\n';
    cout << "\tHistory: " << '\n';
    cout << endl;
    cout << "Manage Accounts" << '\n';
    cout << "1) <- BACK" << '\n';
    cout << "2) Sign out" << '\n';
    int option;
    cout << "Enter your option: ";
    cin >> option;
    switch (option){
        case 1:
            menu(); break;
        case 2:
            break;
    }
}
void Atm::userMenuOption(){
    int option;
//do{
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
        break;
    case 3:
        cout << "\tWithdraw" << '\n';
        cout << "Withdraw Amount: ";
        cin >> withdrawAmount;
        withdraw(withdrawAmount);
        break;
    case 4:
        cout << "\tDeposits" << '\n';
        cout << "Deposit Amount: ";
        cin >> depositAmount;
        deposit(depositAmount);
        break;
    case 5: 
        cout << "Sign out" << '\n';
        break;
    default:
        cout << "WRONGGGGG !!!!";
        break;
    }
    //}while(option != 0);
}//userOption



