#include <iostream>
using namespace std;

void countChange(int c){
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    quarters = c/25;
    c = c % 25;
    dimes = c/10;
    c = c % 10;
    nickels = c/5;
    c = c % 5;
    pennies = c;

    cout << "Your change is " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickles, and " << pennies << " pennies." << "\n";
}

int main(){
    countChange(54);
    return 0;
}