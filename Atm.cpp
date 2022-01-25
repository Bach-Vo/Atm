#include "Atm.h"
#include <iostream>
#include <ctime>
using namespace std;

Atm::Atm(){
    balance = 100;
    cardNum = new char [16];
    cardNumGenerator(cardNum);
}
//generators
void Atm::cardNumGenerator(char *cardN){
    srand(time(0));

    //leading digit
    switch (rand()%3)
    {
    case 1:
        cardN[0] = 4 + '0';
        //cardType = "Visa";
        break;
    case 2:
        cardN[0] = 5 + '0';
        //cardType = "some";
        break;
    case 3:
        cardN[0] = 1 + '0';
        //cardType = "sum else";
        break;
    default:
        cardN[0] = 0 + '0';
        //cardType = "Unknown";
        break;
    }
    //the rest
    for (int i = 1; i < 15; i++)
    {
        cardN[i] = (rand() %9) + '0' ;
    }
        cout << "cardN: " << cardN<< endl;
}
//setters
void Atm::withdraw(){
    int option;
        cout << "Withdraw Amount: $";
        cin >> withdrawAmount;
    balance -= withdrawAmount;
        cout << "Current balance: $" << balance << endl;
    if (balance >0)
    {
            cout << "1) Continue withdraw\t2) Main menu\t3) Exit" << endl;
            cin >> option;
            if (option == 1)     {    withdraw();}
            else if (option == 2){    menu();}
            else if (option == 3){/*exit*/}
    }
    else
    {
        cout << "You're broke !!!" << endl;
            cout << "1) Main menu\t\t2) Exit" << endl;
            cin >> option;
            if (option == 1){   menu();}
            else if (option == 2){ /*exit*/ }
    }
}
void Atm::deposit(){
        cout << "Deposit Amount: $";
        cin >> depositAmount;
    balance += depositAmount;
    cout << "Current balance: $" << balance << endl;
    cout << "1) Continue deposit\t2) Main menu\t3) Exit" << endl;
    int option;
    cin >> option;
    if (option == 1)     {    deposit();    }
    else if (option == 2){    menu();    }
    else if (option == 3){/*exit*/}
    //room for exceptions   
}

//Printers
void Atm::menu(){
    system("cls");
    cout << "\n************** WELCOME TO ATM ************** "<< '\n'<<'\n';
    cout << "1)     My Accounts" << '\n';
    cout << "2)     Transfer" << '\n';
    cout << "3)     Withdraw" << '\n';
    cout << "4)     Deposits" << '\n';
    cout << "5)     Sign out" << '\n';
    //cout << "*************************************************" << endl;
    int option;

    cout << "\nEnter your option: ";
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
        withdraw();
        break;
    case 4:
        cout << "\tDeposits" << '\n';
        deposit();
        break;
    case 5: 
        cout << "Signning out..." << '\n';
        //system("pause>0");
        break;
    default:
        cout << "\tOUTTTTT !!!!";
        false;
        break;
    }//switch
       //should merge into 1 function or seperate between display & option functions
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



