#include "Atm.h"
#include <iostream>
#include <ctime>            //srand(time())
#include <cstring>
#include <string>
#include <stdexcept>
#include <windows.h>        //Sleep()
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
    switch (rand()%5 +1)
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
}
//Validators
bool Atm::cardValidator(const char *cardN){
    int sum =0, total = 0;

    int size = strlen(cardN);
    if (size > 16)
    {
        return false;// throw ex
    }
    //Copy original arr into a dummy arr
    char array[size];
    for (int i = 0; i < size; i++)
        array[i] = cardN[i];

    //Use Luhn algorithm to check
    for (int i = size-2; i >= 0 ; i-=2)
    {
        sum = (array[i] - '0') *2;
        if (sum >= 10){
            array[i] = ((sum/10)+(sum%10) +'0');
        }
        else
            array[i] = sum + '0';
    }
    for (int i = 0; i < size; i++)
    {
        total += array[i] - '0';
    }
    //if true: Valid | false: Invalid
    if (total %10 == 0)
        return true;
    return false;
}
//setters
void Atm::withdraw(){
    int option;
/***GOAL*** Before letting customers withdraw, check if they a have neg balance. 
    If yes, Notify them and exit. 
    If no, Let them withdraw
Then, check balance again to decide asking "Continue withdrawing"
    If (balance is in an acceptable threshold), Options to exist
    If else, Options to Continue withdraw and Exits. 
*/  
    //Check if neg balance
    if (balance <= 0){
            cout << "You're broke!\tCurrent balance: $"<< balance << endl;
        cout << "1) Main menu\t\t2) Exit" << endl;
        cin >> option;
            if (option == 1){   menu(); return;}
            else if (option == 2){ /*exit*/ }
        return;
    }
    //ask for withdrawAmount
cout << "Withdraw Amount: $";
cin >> withdrawAmount;

    //Positive balance
    if (withdrawAmount < balance)
    {
        balance -= withdrawAmount;  //for real  ;)
        cout << "Current balance: $" << balance << endl;//New balance amount
        cout << "1) Continue withdraw\t2) Main menu\t3) Exit\n>" << endl;
        cin >> option;
        if(option == 1){ withdraw(); return; }
        else if(option == 2){ menu(); return; }
        else return;
    }
    //Within an acceptable threshold
    else if(withdrawAmount < balance +10){
        cout << "Getting out of money, balance cannot reach over $-10" << endl <<
        "1) Continue to withdraw" << endl <<
        "2) Enter a smaller amount" << endl <<
        "Otherwise, press any other key to Exit..." << endl;
        cin >> option;
        if(option == 1){
            balance -= withdrawAmount;
            cout << "Current balance: $" << balance << endl;//New balance amount
            cout << "1) Main menu\t2)Exit";
            option = 0;     //reset "option"
            cin >> option;
            if(option == 1){ menu(); return; }
            else if(option == 2){ return; }
            //else     throw an exception
        }
        else if(option == 2){
            withdraw();     //is this bad, func within func within func ???
            return;
        }
        else    return;
    }
    //Neg balance
    else// if(withdrawAmount > (tempBalance +10))
    {
        //ask to pick different amount or exit 
        cout << "Not enough money!" << endl << 
        "Press (1) to enter a smaller amount" << endl << 
        "Otherwise, press any other key to Exit... " << endl;
        cin >> option;
        if (option == 1)
        {
            withdraw();
            return;
        }
        else    return;
    }
    //else {cout<<"Error";}
    return;
/*
        balance -= withdrawAmount;
    cout << "Current balance: $" << balance << '\n' << endl;
    //Not enough money but within a threshold (0 <-> -10)
    if((balance < 10 && balance > 0) && withdrawAmount < 10)
    {   
            cout << "Not enough money";
    }
    //Positive balance
    else
    {
        //
    }
    //Check if eliable to "Continue withraw"
        //balance is negative
    if (balance == 0 && balance > -10)
    {
        cout << "1) Main menu\t\t2) Exit" << endl;
        cin >> option;
        if (option == 1){   menu();}
        else if (option == 2){ /*exit }
    }
        //balance is positive
    else if(balance > 0)
    {
        cout << "1) Continue withdraw\t2) Main menu\t3) Exit" << endl;
        cin >> option;
        if (option == 1)     {    withdraw();}
        else if (option == 2){    menu();}
        else if (option == 3){/*exit}
    }*/
}
void Atm::deposit(){
        cout << "Deposit Amount: $";
        cin >> depositAmount;
    balance += depositAmount;
    cout << "Current balance: $" << balance <<'\n' << endl;
    cout << "1) Continue deposit\t2) Main menu\t3) Exit" << endl;
    int option;
    cin >> option;
    if (option == 1)     {    deposit();}
    else if (option == 2){    menu();}
    else if (option == 3){    return;}
    //room for exceptions 
    else{
        exceptionMes = "Invalid option";
        throw exceptionMes;
    }  
}

//Display menus
void Atm::menu(){
    //system("cls");
    cout << "\n************** WELCOME TO ATM ************** "<< '\n'<<'\n';
    cout << "1)     My Accounts" << '\n';//Delete [] cardNum
    cout << "2)     Transfer" << '\n';
    cout << "3)     Withdraw" << '\n';
    cout << "4)     Deposits" << '\n';
    cout << "5)     Sign out" << '\n';
    cout << "**********************************************" << endl;
    int option = 0;
    cout << "\nEnter your option: ";
    cin >> option;
    
    switch (option){
    case 1:
        cout << "My Accounts";
        accMenu();
        break;
    case 2:
        cout << "Transfer" << '\n';
        transferMenu();
        break;
    case 3:
        cout << "\tWithdraw" << '\n';
        withdraw();
        break;
    case 4:
        cout << "\tDeposits" << '\n';
        try{
            deposit();
        }catch(string &exceptionMes){   //return to Main menu if catch exc
            cout << option << " is not a valid option";
            menu();
        }
        break;
    case 5: 
        cout << "Signning out..." << '\n';
        Sleep(1200);
        cout << "Signed out successfully";
        break;
    default:
        cout << "Exit.";
        break;
    }//switch
       //should merge into 1 function or seperate between display & option functions
}
void Atm::accMenu(){
    //system("cls");
    cout << "\n*********** My Accounts ***********"<< '\n'<<'\n';
    cout << "Card #" << cardNum << "\tBrand: " << cardBrand << '\n';
    cout << "Balance: $" << balance << '\n';
    cout << "\tHistory: " << '\n';
    cout << endl;
    cout << "Manage Accounts" << '\n';
    cout << "1) <- BACK" << '\n';
    cout << "2) Sign out" << '\n';
    //User Options
    int option;
    cout << "Enter your option: ";  
    cin >> option;
    switch (option){
        case 1:
            menu(); break;
        case 2:
            break;
        default:
        cout << "Returning to Main Menu...";
        menu();
        break;
    }
}
void Atm::transferMenu()
{
    transferCardNum = new char [16];
    transferMes = new char [100];
    //  input
    cout << "Card #" ;
    cin >> transferCardNum;
    cout << "(optional)[100 char]\nMessage: ";
    cin.get(transferMes, 100, '\n');
    cout<< transferMes;
    //***** Not waiting for input
    double tempTransferAmount = 0;
    if(false/*transfer(transferCardNum, tempTransferAmount)*/)
    {
        cout << "\n\t\tCard #" << cardNum << endl;
        cout << "Has transfered successfully to card #"<<transferCardNum << endl;
        cout << "Amount: $" << tempTransferAmount << endl;
        cout << "Message: " << transferMes << endl;
    }
    else    
    {
        cout << "Request transfer denied";
        //Provide reason, throw ex
        //menu(); return;
    }
    delete [] transferCardNum;
    delete [] transferMes;
}
bool Atm::transfer(char *transferCardNum, double& transferAmount)
{
    if(!cardValidator(transferCardNum)){
        cout << "Card is not valid";
        transferMenu();
        return false;
    }
    //Card is valid
    cout << "Enter Amount: $";
    cin >> transferAmount;
    if (transferAmount < balance)
    {
        cout << "Not enough money to transfer";
        transfer(transferCardNum, transferAmount);//how to bypass cardValidator()
        return false;
    }
    //Enough money
    balance -= transferAmount;
return true;
}



