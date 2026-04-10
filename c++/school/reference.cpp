/*
    Pranav Mandala
    Hands on 6 - Need for Reference Variable
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
using namespace std;
#define DISC_RATE 0.1

//Function prototypes
void signature(void);
double calcDiscount(double &owe);

int main()
{
 // Declare variables
 double amtOwing, discount;

 //Input amount owed
 cout << "Enter amount owed: " ;
 cin >> amtOwing;
 
 //Calculate discount and update amount owing
 discount = calcDiscount(amtOwing);
 
 //Output discount and undated amount owed
 cout << setprecision(2) << fixed;
 cout << "Amount of Discount: " << discount << endl;
 cout << "Amount Owed: " << amtOwing << endl;
 
 signature();
 return 0;
}
///////////////////////////////////////////////////////////////
double calcDiscount(double &owe)
{
 /*Pre: owe - reference variable to amtOwing
 Post: Amount of discount
 Purpose: calculate discount and update amount owed to reflect discount*/
 
 double disc;
 disc = DISC_RATE * owe;
 //Update amount owed
 owe = owe - disc;
 
 return disc;
}//////////////////////////////////////////////////////////
void signature()
{
 cout << "Programmed by: Pranav Mandala \n";
}

/*
    Test Data: 100.00
    Enter amount owed: 100.00
    Amount of Discount: 10.00
    Amount Owed: 90.00
    Programmed by: Pranav Mandala 
*/