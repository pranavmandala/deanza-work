#include <iostream>
#include <iomanip>
using namespace std;

int main() {
 //Utility-type expenses
 double pge = 247.5, xfinity = 186.5, garbage = 83, att = 177.40, water = 141.78;
 
 double total;
 
 //Calculate total
 total = pge + xfinity + garbage + att + water;
 
 //Output expenses
 cout << "PG&E" << fixed << setprecision(2) << setw(28) << pge << endl;
 cout << "TV and Internet" << fixed << setprecision(2) << setw(17) << xfinity << endl;
 cout << "Waste Management" << fixed << setprecision(2) << setw(16) << garbage << endl;
 cout << "Cell devices" << fixed << setprecision(2) << setw(20) << att << endl;
 cout << "Water" << fixed << setprecision(2) << setw(27) << water << "\n";
 cout << setw(32) << "_____________" <<endl;
 cout << "Total" << fixed << setprecision(2) << setw(27) << total << endl;
 
 return 0;

}