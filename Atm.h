#ifndef ATM_H
#define ATM_H
#include<iostream>
#include<string>

using namespace std;
class Atm {
private:
    //money
    double balance;
    double withdrawAmount; double depositAmount;
    double transferAmount;
    //other
    char *cardNum;
    char *transferCardNum;
    char *transferMes;
    string cardBrand;
    string exceptionMes;

public:
    //constructors
    Atm();                              //------
    //generators
    void cardNumGenerator(char *cardN);
    //validators
    bool cardValidator(const char *cardN);
    //Display
    void menu();
    void accMenu();
    void transferMenu();
    //getter
    //features
    void withdraw();
    void deposit();
    bool transfer(char *transferCardNum, double &transferAmount);
    //setter                 
    
};
#endif
