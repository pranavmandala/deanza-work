#include <iostream>
using namespace std;
#define PI 3.141592;

int main()
{
    //Declare variables
    int radius;
    double area;

    //Prompt the user for the radius
    cout << "Enter the radius: ";
    cin >> radius;

    //Compute the area
    area = radius * radius * PI;

    //Output the area
    cout << "Area of Circle: " << area << endl;
    cout << "\n\nPranav Mandala\n\n";
    return 0;
}

/*
    Test Data using radius 10
    Enter the radius: 10
    Area of Circle: 314.159


    Pranav Mandala
*/