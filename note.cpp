/* Write a function named genData that generates and returns a random float number with 2  digits after decimal point between 40 and 100 inclusively. Use the following function prototype: 


float genData(low, high); 


    //result = low + static_cast <float>(rand()) / ( static_cast <float> ((RAND_MAX + 1) * (high-low)));
Your program must be compatible with the following main function.  
 
 RAND_MAX
 */
 #include <iostream>
 #include <ctime>
 #include <cstdlib>
 #include <iomanip>
 using namespace std;

 float genData (int low, int high){
    //while ()
    float result;
    //cout << fixed << setprecision(2);
    //int from 40 - 100 
    srand( unsigned(time(NULL)));
    int integer = (rand()%(high - low + 1)) + low;  
    //decimal
    
    srand( unsigned(time(NULL)));
    float dec = (rand() % 100)/100;
    result = integer + dec;

    cout << endl;
    cout << "in: " << integer << endl;
    cout << "dec: " << dec;
    return result;
 }

 int main(){
    cout << "data: " << genData(40, 100);

 }