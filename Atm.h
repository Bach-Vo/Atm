#ifndef ATM_H
#define ATM_H
#include<iostream>
#include<string>

using namespace std;
class Atm {
private:
    //money
    double balance;
    double withdrawAmount, depositAmount;
    //other
    char *cardNum;
    string cardBrand;
    string exceptionMes;

public:
    //constructors
    Atm();                              //------
    //generators
    void cardNumGenerator(char *cardN);
    //validators
    bool cardValidator(const char *cardN);
    //printer
    void menu();
    void accMenu();
    //getter
    void withdraw();
    void deposit();
    //setter                 
    
};
#endif
