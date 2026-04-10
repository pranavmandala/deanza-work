/*
    Pranav Mandala
    Hands On #4 Functions
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
using namespace std;
#define UNITCOST 31

double calcTuition(double units, double studentFees);
void output(double total);

int main(){
    int numOfUnits;
    double fees;
    double feeTotal;

    cout << "Enter the number of units: ";
    cin >> numOfUnits;
    cout << "Enter your student fees: ";
    cin >> fees;

    feeTotal = calcTuition(numOfUnits, fees);
    output(feeTotal);
    
    return 0;
}

double calcTuition(double units, double studentFees){
    return ((units * UNITCOST) + studentFees);
}

void output(double total){
    cout << fixed << setprecision(2) << "Your total fees are: $" << total << "\nPranav Mandala\n20503235\n";
}

/*
    Enter the number of units: 21
    Enter your student fees: 60.75
    Your total fees are: $711.75
    Pranav Mandala
    20503235
*/

