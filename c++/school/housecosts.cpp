/*
    Pranav Mandala
    Lab 5 - Monthly House Costs
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define TAX 0.0125
#define UTILITIES 500.00
#define INSURANCE 703.00

void input(double &price, int &years, double &interestRate);
double calcMonthlyCosts(double price, int years, double interestRate, double &propertyTaxes, double &mortgage, double &amt, double &down);
double calcMortgage(double price, int years, double interestRate, double &amt, double &down);
double calcCosts(double mortgage, double price, double &propertyTaxes);
void output(double amt, double down, double price, int years, double interestRate, double mortgage, double monthlyCosts, double propertyTaxes);


int main(){
    //Declaring variables for program data
    double amt;
    double down;
    double price;
    int years;
    double interestRate;
    double mortgage;
    double monthlyCosts;
    double propertyTaxes;

    //Function invocation to input function to receive inputted values
    input(price, years, interestRate);
    //Function invocation to calcMonthlyCosts to perform the calculations
    monthlyCosts = calcMonthlyCosts(price, years, interestRate, propertyTaxes, mortgage, amt, down);
    //Function invocation to output function to output data
    output(amt, down, price, years, interestRate, mortgage, monthlyCosts, propertyTaxes);
    
    //Program signature and what was learned
    cout << "\nPranav Mandala\nI learned a lot about when to use pass by reference vs pass by value depending on what is available to you\n";
    
    return 0;
}

void input(double &refPrice, int &refYears, double &refInterestRate){
    /*
        Pre:
        refPrice - reference to price
        refYears - reference to years
        refInterestRate - reference to interest rate
    */
    
    cout << "Enter the price of the house: ";
    cin >> refPrice;
    cout << "Enter the length of the loan in years: ";
    cin >> refYears;
    cout << "Enter the interest Rate of the loan: ";
    cin >> refInterestRate;
}

double calcMonthlyCosts(double price, int years, double interestRate, double &propertyTaxes, double &mortgage, double &amt, double &down){
    /*
        Pre:
        price - price of house
        years - amt of years loan will last
        interestRate - interest rate of the loan
        propertyTaxes - reference to property tax
        mortgage - reference to mortgage
        amt - reference to amt of loan
        down - reference to the down payment
    */

    mortgage = calcMortgage(price, years, interestRate, amt, down);
    return calcCosts(mortgage, price, propertyTaxes);
}

double calcMortgage(double price, int years, double interestRate, double &amt, double &down){
    /*
        Pre:
        price - price of house
        years - amt of years loan will last
        interestRate - interest rate of the loan
        amt - reference to amt of loan
        down - reference to downpayment

        Purpose:
        Calculates i and n needed for calculating mortgage, the down payment and amount of loan, and the mortgage payment per month

        Post:
        Returns mortgage value
    */
    
    double i = (interestRate / 100) / 12;
    double n = years * 12;
    double downAmount = 0.2;

    down = price * downAmount;
    amt = price - down;
    return ((amt * i * pow(1+i, n)) / (pow(1+i,n)-1));
}

double calcCosts(double mortgage, double price, double &propertyTaxes){
    /*
        Pre:
        mortgage - mortage payment
        price - price of the house
        propertyTaxes - reference to propertyTax

        Purpose:
        Calculates monthly payments including utilities, insurance, and property taxes

        Post:
        returns monthly payment with all costs
    */

    propertyTaxes = (price * TAX / 12);
    return (mortgage + UTILITIES + INSURANCE + propertyTaxes);
}

void output(double amt, double down, double price, int years, double interestRate, double mortgage, double monthlyCosts, double propertyTaxes){
    /*
        Pre:
        amt - amt of loan
        down - down payment on the house
        price - price of the house
        years - amt of years laon will last
        interestRate - interest rate of the loan
        mortgage - mortgage payment
        monthlyCosts - monthly payment with all costs
        propertyTaxes - monthly property tax

        Purpose: 
        Outputs properly formatted data

        Post:
        returns nothing
    */
    
    cout << fixed << setprecision(2) << setw(24) << left << "SELLING PRICE" << setw(16) << right << price << "\n";
    cout << fixed << setprecision(2) << setw(24) << left << "DOWN PAYMENT" << setw(16) << right << down << "\n";
    cout << fixed << setprecision(2) << setw(24) << left << "AMOUNT OF LOAN" << setw(16) << right << amt << "\n";
    cout << fixed << setprecision(2) << setw(24) << left << "INTEREST RATE" << setw(15) << right << interestRate << "%" << "\n";
    cout << fixed << setprecision(2) << setw(24) << left << "TAX RATE" << setw(15) << right << (TAX * 100) << "%" << "\n";
    cout << setw(24) << left << "DURATION OF LOAN (YEARS)" << setw(15) << right << years << "\n";
    cout << "\n\n\nMONTHLY PAYMENT\n\n";
    cout << fixed << setprecision(2) << setw(14) << left << "MORTGAGE" << setw(21) << right << mortgage << "\n";
    cout << fixed << setprecision(2) << setw(14) << left << "UTILITIES" << setw(21) << right << UTILITIES << "\n";
    cout << fixed << setprecision(2) << setw(14) << left << "PROPERTY TAXES" << setw(21) << right << propertyTaxes << "\n";
    cout << fixed << setprecision(2) << setw(14) << left << "INSURANCE" << setw(21) << right << INSURANCE << "\n";
    cout << "\n" << setw(36) << right << "__________\n";
    cout << fixed << setprecision(2) << setw(26) << right << "$" << setw(9) << right << monthlyCosts << "\n";

}

/*
    Test Data
    
    Set 1 - $600,000, 7.783%, 30
    
    Enter the price of the house: 600000
    Enter the length of the loan in years: 30
    Enter the interest Rate of the loan: 7.783
    SELLING PRICE                  600000.00
    DOWN PAYMENT                   120000.00
    AMOUNT OF LOAN                 480000.00
    INTEREST RATE                      7.78%
    TAX RATE                           1.25%
    DURATION OF LOAN (YEARS)             30



    MONTHLY PAYMENT

    MORTGAGE                    3449.73
    UTILITIES                    500.00
    PROPERTY TAXES               625.00
    INSURANCE                    703.00

                             __________
                              $ 5277.73

    Pranav Mandala
    I learned a lot about when to use pass by reference vs pass by value depending on what is available to you

    Set 2 - $600,000, 2.164%, 30

    Enter the price of the house: 600000
    Enter the length of the loan in years: 30
    Enter the interest Rate of the loan: 2.164
    SELLING PRICE                  600000.00
    DOWN PAYMENT                   120000.00
    AMOUNT OF LOAN                 480000.00
    INTEREST RATE                      2.16%
    TAX RATE                           1.25%
    DURATION OF LOAN (YEARS)             30



    MONTHLY PAYMENT

    MORTGAGE                    1813.80
    UTILITIES                    500.00
    PROPERTY TAXES               625.00
    INSURANCE                    703.00

                            __________
                            $  3641.80

    Pranav Mandala
    I learned a lot about when to use pass by reference vs pass by value depending on what is available to you
*/