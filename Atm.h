#ifndef ATM_H
#define ATM_H

using namespace std;
class Atm {
private:
    int amount;
    int cardNum;
public:
    //constructors
    Atm();                              //------
    //printer
    void menu();
    void accMenu();
    //getter


    //setter
    void userOption();                 
    
};
#endif
