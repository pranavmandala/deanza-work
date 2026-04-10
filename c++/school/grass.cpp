/*
    Pranav Mandala
    Lab 1B - Grass
    pranav.mandala07@gmail.com
*/

#include <iostream>
using namespace std;

int main() {
    
    // Declaring variables house and yard dimensions
    int yardLength;
    int yardWidth;
    int houseLength;
    int houseWidth;

    // Prompt user to enter dimensions of yard and house
    cout << "Enter the length of the yard in feet: ";
    cin >> yardLength;
    cout << "Enter the width of the yard in feet: ";
    cin >> yardWidth;
    cout << "Enter the length of the house in feet: ";
    cin >> houseLength;
    cout << "Enter the width of the house in feet: ";
    cin >> houseWidth;

    //Calculating areas for grass and house
    int yardArea = yardLength * yardWidth;
    int houseArea = houseLength * houseWidth;

    //Calculating area needed to mow
    int mowArea = yardArea - houseArea;
    cout << "The area needed to be mowed in square feet is " << mowArea << "\n";

    //Calculating time needed to mow
    int time = mowArea / 90;
    cout << "The time needed to mow the grass is " << time << " minutes or " << time / 60 << " hour(s) and " << time % 60 << " minute(s)\n";

    cout << "Programmed by: Pranav Mandala\n";

    return 0;

}

/*
    Enter the length of the yard in feet: 120
    Enter the width of the yard in feet: 100
    Enter the length of the house in feet: 65
    Enter the width of the house in feet: 50
    The area needed to be mowed in square feet is 8750
    The time needed to mow the grass is 97 minutes or 1 hour(s) and 37 minute(s)
    Programmed by: Pranav Mandala
*/