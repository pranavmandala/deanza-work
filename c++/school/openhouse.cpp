/*
    Pranav Mandala
    Lab 2 - Swag for De Anza's 2025 Open House
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
//Defining tax as a global preprocessor
#define TAX 0.0913
using namespace std;

int main() {
    
    //Declaring price constants
    const double penPackagePrice = 65.50;
    const double pendantPackagePrice = 362.50;
    const double totebagPackagePrice = 159.00;
    
    //Declaring variables for date, people, and items
    string date;
    int numOfPeople;
    int penPackages;
    int pendantPackages;
    int totebagPackages;
    double penTotal;
    double pendantTotal;
    double totebagTotal;

    //Prompting user for input for date and people
    cout << "Enter Month and Year: ";
    getline(cin, date);
    cout << "Enter Number of RSVPS received: ";
    cin >> numOfPeople;

    //Calculating number of packages for items
    penPackages = (numOfPeople + 50 - 1) / 50;
    pendantPackages = (numOfPeople + 250 - 1) / 250;
    totebagPackages = 6 * ((numOfPeople + 100 - 1) / 100);

    //Calculating totals
    penTotal = penPackages * penPackagePrice;
    pendantTotal = pendantPackages * pendantPackagePrice;
    totebagTotal = totebagPackages * totebagPackagePrice;

    //Outputting and formatting data
    cout << "Month: " << date << "\n\n";
    cout << left << setw(23) << "ITEM" << "#PACKAGES   UNIT COST   SUBTOTAL\n";
    cout << left << setw(23) << "Pens" << right << setw(4) << penPackages << right << setw(17) << fixed << setprecision(2) << penPackagePrice << right << setw(11) << fixed << setprecision(2) << penTotal << "\n";
    cout << left << setw(23) << "Pendants" << right << setw(4) << pendantPackages << right << setw(17) << fixed << setprecision(2) << pendantPackagePrice << right << setw(11) << fixed << setprecision(2) << pendantTotal << "\n";
    cout << left << setw(23) << "Totebags" << right << setw(4) << totebagPackages << right << setw(17) << fixed << setprecision(2) << totebagPackagePrice << right << setw(11) << fixed << setprecision(2) << totebagTotal << "\n\n";
    cout << right << setw(8) << "Subtotal" << right << setw(19) << fixed << setprecision(2) << (penTotal + pendantTotal + totebagTotal) << "\n";
    cout << right << setw(8) << "Tax" << right << setw(19) << fixed << setprecision(2) << ((penTotal + pendantTotal + totebagTotal) * TAX) << "\n";
    cout << right << setw(8) << "Total" << right << setw(19) << fixed << setprecision(2) << (((penTotal + pendantTotal + totebagTotal) * TAX) + (penTotal + pendantTotal + totebagTotal)) << "\n";
    cout << "Programmed by Pranav Mandala\n";
    
    return 0;
}
/*
    Test Data

    Month: December 2025

    ITEM                   #PACKAGES   UNIT COST   SUBTOTAL
    Pens                      9            65.50     589.50
    Pendants                  2           362.50     725.00
    Totebags                 30           159.00    4770.00

    Subtotal            6084.50
        Tax             555.51
    Total            6640.01
    Programmed by Pranav Mandala
*/