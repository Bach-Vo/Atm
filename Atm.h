#ifndef ATM_H
#define ATM_H
#include<iostream>
using namespace std;
class Atm {
private:
    //money
    double balance;
    double withdrawAmount, depositAmount;
    //other
    char *cardNum;
    
public:
    //constructors
    Atm();                              //------
    //generators
    void cardNumGenerator(char *cardN);
    //printer
    void menu();
    void accMenu();
    //getter
    void withdraw(double);
    void deposit(double);


    //setter
    void userMenuOption();                 
    
};
#endif
