/*
    Pranav Mandala
    Lab 4 Lyft
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
using namespace std;

double calcRideCost(double time, double distance, char rideType, double surgeMultiplier);
void output(string name, double total);


int main() {
    
    //Declaring variables for details of the trip
    string name;
    double time;
    double distance;
    char rideType;
    char surge;
    double surgeMultiplier;
    double total;
    
    //Prompting user to enter the details of their trip
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter time in minutes: ";
    cin >> time;
    cout << "Enter distance: ";
    cin >> distance;
    cout << "Enter 'X' for LyftX, 'S' for Suv, or 'L' for Luxury: ";
    cin >> rideType;
    //Converting any lower case character to upper case
    rideType = toupper(rideType);
    //Checking if ridetype was given a proper value
    if((rideType != 'X') && (rideType != 'S') && (rideType != 'L')){
        cout << EXIT_FAILURE << endl;
        exit(1);
    }
    cout << "Enter 'Y'if surge and 'N' if not: ";
    cin >> surge;
    //Converting any lower case character to uppercase
    surge = toupper(surge);
    //Checking surge was given a proper value
    if((surge != 'Y') && (surge != 'N')){
        cout << EXIT_FAILURE << endl;
        exit(1);
    }

    //Setting surge multiplier to default to 1 if there is no surge, reduces extra calculations
    if(surge == 'Y'){
        cout << "Enter Surge Multiplier: ";
        cin >> surgeMultiplier;
    } else {
        surgeMultiplier = 1;
    }

    //Function invocation to calculate and output the cost of the ride
    total = calcRideCost(time, distance, rideType, surgeMultiplier);
    output(name, total);
    
    //Signature
    cout << "Mastered the concept of functions\n";
    cout << "Programmed by Pranav Mandala\n";

    return 0;

}

double calcRideCost(double time, double distance, char rideType, double surgeMultiplier){
    /*
        Pre:
        time - how long the ride will take in minutes
        distance - how far the trip is in miles
        rideType - what vehicle was chosen for the ride
        surgeMultiplier - multiplier to be multiplited by the total, 1 by default if no multiplier
        
        Post: total cost of the ride
        
        Purpose: Calculate and return the total cost of the ride
        
    */
    
    double cost;
    if(rideType == 'X'){
        cost = (4.20 * surgeMultiplier) + (0.28 * time) + (2.06 * distance);
        if(cost < 7.50){
            cost = 7.50;
        }
        return cost;
    } else if(rideType == 'S'){
        cost = (15.00 * surgeMultiplier) + (0.90 * time) + (3.75 * distance);
        if(cost < 25.00){
            cost = 25.00;
        }
        return cost;
    } else {
        cost = (5.00 * surgeMultiplier) + (0.50 * time) + (2.75 * distance);
        if(cost < 10.55){
            cost = 10.55;
        }
        return cost;
    }
    
}

void output(string name, double total){
    /*
        Pre:
        name - name of the rider
        total - calculated total for the trip
        
        Post: Does not return anything
        
        Purpose: ouput the riders name and the total cost of their trip formatted and rounded to 2 decimal points
    */
    cout << "Rider's name: " << name << "\n";
    cout << "Total: $ " << fixed << setprecision(2) << total << "\n";
}

/*
    Test Data 1: Mary Pape,34.6,25.5,X,Y. 1.9
    Enter name: Mary Pape
    Enter time in minutes: 34.6
    Enter distance: 25.5
    Enter 'X' for LyftX, 'S' for Suv, or 'L' for Luxury: X
    Enter 'Y'if surge and 'N' if not: Y
    Enter Surge Multiplier: 1.9
    Rider's name: Mary Pape
    Total: $ 70.20
    Mastered the concept of functions
    Programmed by Pranav Mandala

    Enter name: Taylor Swift
    Enter time in minutes: 15
    Enter distance: 16.8
    Enter 'X' for LyftX, 'S' for Suv, or 'L' for Luxury: L
    Enter 'Y'if surge and 'N' if not: N
    Rider's name: Taylor Swift
    Total: $ 58.70
    Mastered the concept of functions
    Programmed by Pranav Mandala

    Test Data 3: Jason Rider, 45, 13.8, C, N
    Enter name: Jason Rider
    Enter time in minutes: 45
    Enter distance: 13.8
    Enter 'X' for LyftX, 'S' for Suv, or 'L' for Luxury: C
    1

*/