#include <iostream>
#include <iomanip>
using namespace std;

//Set tax rate
#define TAX_RATE 0.0913

int main()
{
 // Declare variables and constants
 const double unitPens = 65.50;
 const double unitPenants = 362.50;
 const double unitTotebags = 159.00;
 int packagePens;
 int packagePenants;
 int packageTotebags;
 double totalPens;
 double totalPenants;
 double totalTotebags;
 string date;
 int rsvps;

 //Input the date and number of rsvps
 cout << "Enter Month and Year: ";
 getline(cin, date);
 cout << "Enter Number of RSVPs received: ";
 cin >> rsvps;

 //Calculate the number and cost of packages needed
 packagePens = (rsvps + 50 - 1) / 50;
 packagePenants = (rsvps + 250 - 1) / 250;
 packageTotebags = 6* ((rsvps + 100 - 1) / 100);
 totalPens = packagePens * unitPens;
 totalPenants = packagePenants * unitPenants;
 totalTotebags = packageTotebags * unitTotebags;
 double totalCost = totalPens + totalPenants + totalTotebags;

 //Compute tax and total
 double tax = TAX_RATE * totalCost;
 double billTotal = totalCost + tax;

 //Output the datw
 cout << endl;
 cout << "Month: " << date << endl;
 cout << endl;

 //Output table heading
 cout << "Item" << setw(27) << "#PACKAGES" << setw(15) << "UNIT COST" <<
 setw(15) << "SUBTOTAL" << endl;

 //Output item description, number of packages, and total cost for each item.
 cout << fixed << setprecision(2);
 cout << left << setw(20) << "Pens" << right << setw(10) << packagePens << setw(15)  
      << unitPens << setw(15) << totalPens << endl;
 cout << left << setw(20) << "Pennants" << right << setw(10) << packagePenants << setw(15) 
      << unitPenants << setw(15) <<totalPenants << endl;
 cout << left << setw(20) << "Totebags" << right << setw(10) << packageTotebags << setw(15) 
      << unitTotebags << setw(15) << totalTotebags << endl;
 cout << endl;

 // Output subtotal, taxt, and total cost
 cout << right << setw(8) << "Subtotal" << right << setw(22) << totalCost << endl;
 cout << right << setw(8) << "Tax" << right << setw(22) << tax << endl;
 cout << right << setw(8) << "Total" << right << setw(22) << billTotal << endl;
 cout << endl;

return 0;
}