#include "Atm.h"
#include <iostream>
using namespace std;
/*              ********* INSTRUCTION       !!!
*/
void menu();
//callees
void accMenu();
void withdraw();
void deposit();
void cardNumGenerator(char *cardNum);
bool cardValidator(const char *cardN);

int main(){
    Atm atm1;
    atm1.menu();
    


return 0;
}


//cd "c:\Codin\Git\ATM\" ; if ($?) { g++ run_Atm.cpp Atm.h -o run_Atm } ; if ($?) { .\run_Atm }

// cd "c:\Codin\Git\ATM\" ; if ($?) { g++ TestAtm.cpp Atm.cpp -o TestAtm } ; if ($?) { .\TestAtm }