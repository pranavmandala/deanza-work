/*
    Pranav Mandala
    Lab 3 - ETS CIS Mobile Lab
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
using namespace std;
//Declaring tax constant
#define TAX 0.0913

int main() {

    //Declaring constants for item prices
    const double LAPTOPPRICE = 1649.00;
    const double CARTPRICE = 949.00;
    const double EARBUDPRICE = 1.29;
    const double MICROPHONEPRICE = 35.99;
    const double MOUSEPRICE = 7.19;
    
    //Declaring variables for item count
    int numOfLaptops;
    int numOfCarts;
    int numOfEarbuds;
    int numOfMicrophones;
    int numOfMice;
    double laptopTotal;
    double cartTotal;
    double earbudTotal;
    double microphoneTotal;
    double miceTotal;

    //Prompting user to input the number of items needed for each item
    cout << "How many carts for charging and storing computers? ";
    cin >> numOfCarts;
    cout << "How many Dell XPS 15 Laptops? ";
    cin >> numOfLaptops;
    cout << "How many earbuds ordered? ";
    cin >> numOfEarbuds;
    cout << "How many microphones ordered? ";
    cin >> numOfMicrophones;
    cout << "How many wired usb mice ordered? ";
    cin >> numOfMice;

    //Calculating total prices
    laptopTotal = numOfLaptops * LAPTOPPRICE;
    cartTotal = numOfCarts * CARTPRICE;
    earbudTotal = numOfEarbuds * EARBUDPRICE;
    microphoneTotal = numOfMicrophones * MICROPHONEPRICE;
    miceTotal = numOfMice * MOUSEPRICE;

    //Formatting and outputting data
    cout << right << setw(3) << "QTY" << left << setw(29) << "  Description" << right << setw(10) << "Unit Price" << setw(17) << "Total Price" << "\n";
    cout << right << setw(3) << numOfCarts << left << setw(29) << "  CHARGE & STORAGE CARTS" << right << setw(10) << fixed << setprecision(2) << CARTPRICE << setw(17) << cartTotal << "\n";
    cout << right << setw(3) << numOfLaptops << left << setw(29) << "  DELL XPS 15 LAPTOPS" << right << setw(10) << LAPTOPPRICE << fixed << setprecision(2) << setw(17) << laptopTotal << "\n";
    cout << right << setw(3) << numOfEarbuds << left << setw(29) << "  DISPOSABLE EARBUDS" << right << setw(10) << EARBUDPRICE << fixed << setprecision(2) << setw(17) << earbudTotal << "\n";
    cout << right << setw(3) << numOfMicrophones << left << setw(29) << "  MICROPHONE" << right << setw(10) << MICROPHONEPRICE << fixed << setprecision(2) << setw(17) << microphoneTotal << "\n";
    cout << right << setw(3) << numOfMice << left << setw(29) << "  WIRED USB MOUSE" << right << setw(10) << MOUSEPRICE << fixed << setprecision(2) << setw(17) << miceTotal << "\n";
    
    //Calculating subtotal by adding up all the item totals
    cout << right << setw(28) << "SUBTOTAL" << setw(14) << fixed << setprecision(2) << (laptopTotal + cartTotal + earbudTotal + microphoneTotal + miceTotal) << "\n";
   
    //Calculating tax of the purchase by taking 9.13% of the subtotal   
    cout << right << setw(28) << "TAX" << setw(14) << fixed << setprecision(2) << (laptopTotal + cartTotal + earbudTotal + microphoneTotal + miceTotal) * (TAX) << "\n";
    
    //Calculating total by adding subtaotal and tax of the purchase
    cout << right << setw(28) << "TOTAL" << setw(14) << fixed << setprecision(2) << (laptopTotal + cartTotal + earbudTotal + microphoneTotal + miceTotal) + (laptopTotal + cartTotal + earbudTotal + microphoneTotal + miceTotal) * (TAX) << "\n"; 
    
    //Signature
    cout << "\nProgrammed by Pranav Mandala\n\n";
    
    return 0; 
}
/*
    Test Data 1: 1, 25, 120, 3, 50
    QTY  Description                Unit Price      Total Price
    1    CHARGE & STORAGE CARTS         949.00           949.00
    25   DELL XPS 15 LAPTOPS           1649.00         41225.00
    120  DISPOSABLE EARBUDS               1.29           154.80
    3    MICROPHONE                      35.99           107.97
    50   WIRED USB MOUSE                  7.19           359.50
                        SUBTOTAL      42796.27
                             TAX       3907.30
                           TOTAL      46703.57
    
    Programmed by Pranav Mandala

*/