/*
    Pranav Mandala
    Lab 7 - Predict Heights
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

int getData(ifstream &inFS, int familyNum[100], double fatherHeight[100], double motherHeight[100], int famNumOfChildren, int childNum[100], string gender[100], double childHeight[100], double parentMidpointHeight[100], double difference[100]);
void output(ofstream &outFS, int familyNum[100], int childNum[100], string gender[100], double parentMidpointHeight[100], double childHeight[100], double difference[100], int numOfChildren);
double genderAvg(string whatGender, string gender[100], double childHeight[100], int numOfChildren);
int findCombo(int specFamily, int specChild, int familyNum[100], int childNum[100], int numOfChildren);
void findChildHeight(ofstream &outFS, int familyNum[100], int childNum[100], double parentMidpointHeight[100], double childHeight[100], int numOfChildren);
double calculateStddev(double difference[100], int numOfChildren);
void sortArrays(int familyNum[100], double fatherHeight[100], double motherHeight[100], int childNum[100], string gender[100], double childHeight[100], double parentMidpointHeight[100], double difference [100], int numOfChildren);

int main(){
    
    //Declaring variables for checking if file was openened and number of children
    int open;
    int numOfChildren;
    
    //Declaring input and output file stream and opening output file stream
    ifstream inFS;
    ofstream outFS;
    outFS.open("output.txt");

    //Declaring arrays for file data
    int familyNum[100];
    double fatherHeight[100];
    double motherHeight[100];
    int famNumOfChildren;
    int childNum[100];
    string gender[100];
    double childHeight[100];
    double parentMidpointHeight[100];
    double difference[100];

    //Declaring variables for what gender to be checked and its average
    string whatGender;
    double avgOfGender;

    //Declaring variables for what family and child wants to be found and where the child was found
    int specFamily;
    int specChild;
    int childFound;

    //Declaring a variable for the calculated standard deviation
    double calculatedStddev;

    //Function invocation to getData
    open = getData(inFS, familyNum, fatherHeight, motherHeight, famNumOfChildren, childNum, gender, childHeight, parentMidpointHeight, difference);

    //Based on getData's output, this will either end the program if the file was not opened or set the returned value to numOfChildren
    if(open == -1){
        cout << "Could not open Lab6DataW26.txt" << endl;
        return 1;
    } else {
        numOfChildren = open;
    }

    //Outputting data to file
    output(outFS, familyNum, childNum, gender, parentMidpointHeight, childHeight, difference, numOfChildren);
    //Outputting new line for readabillity in file
    outFS << "\n";
    
    //Prompting user for what gender average they want
    cout << "Enter male, female or All: ";
    cin >> whatGender;
    
    //Function invocation to genderAvg and taking the returned value and outputting it
    avgOfGender = genderAvg(whatGender, gender, childHeight, numOfChildren);
    cout << "Average of " << whatGender << " genders is " << fixed << setprecision(2) << avgOfGender << endl;

    //Prompting user to input what family and child number they want
    cout << "Enter a family number: ";
    cin >> specFamily;
    cout << "Enter a child number: ";
    cin >> specChild;
    
    //Function invocation to findCombo and taking the returned value and outputting the child or no such child if child is not found
    childFound = findCombo(specFamily, specChild, familyNum, childNum, numOfChildren);
    if(childFound == -1){
        cout << "No such child!" << endl;
    } else {
        cout << "The " << specChild << " child of family " << specFamily << " has a height of " << childHeight[childFound] << endl;
    }

    //Function invation to findChildHeight
    findChildHeight(outFS, familyNum, childNum, parentMidpointHeight, childHeight, numOfChildren);

    //Funcation invocation to calculateStddev and taking its value
    calculatedStddev = calculateStddev(difference, numOfChildren);

    //Function invocation to sortArrays
    sortArrays(familyNum, fatherHeight, motherHeight, childNum, gender, childHeight, parentMidpointHeight, difference, numOfChildren);
    
    //Function invocation to output
    output(outFS, familyNum, childNum, gender, parentMidpointHeight, childHeight, difference, numOfChildren);
    
    //Program Signature
    cout << "\nProgrammed by Pranav Mandala\n";

}

int getData(ifstream &inFS, int familyNum[100], double fatherHeight[100], double motherHeight[100], int famNumOfChildren, int childNum[100], string gender[100], double childHeight[100], double parentMidpointHeight[100], double difference[100]){

    /*
        Pre:
        inFS - input file stream
        familyNum - array to hold family numbers
        fatherHeight - array to hold father heights
        motherHeight - array to hold mother heights
        famNumOfChildren - variable to read family's number of children
        childNum - array to child number
        gender - array to hold child genders
        childHeight - array to hold child heights
        parentMidpointHeight - array to hold parent midpoint heights
        difference - array to hold difference in parent midpoint heights and child heights
        
        Purpose:
        Checks if the file was successfully opened, takes data from file and puts it into arrays, calculates the midpoint of parent heights and difference between midpoint and child's height
       
        Post:
        Returns -1 if file was not successfully opened, or returns number of children
    */
    
    int i = 0;
    string test;
    
    inFS.open("Lab6DataW26.txt");

    if(inFS.is_open()){
        for(int j = 0; j < 7; j++){
            inFS >> test;
        }
    } else {
        return -1;
    }

    while(!inFS.eof()){
        inFS >> familyNum[i];
        inFS >> fatherHeight[i];
        inFS >> motherHeight[i];
        inFS >> famNumOfChildren;
        inFS >> childNum[i];
        inFS >> gender[i];
        inFS >> childHeight[i];
        
        if(!inFS.fail()){
            parentMidpointHeight[i] = ((fatherHeight[i] + motherHeight[i]) / 2);
            difference[i] = parentMidpointHeight[i] - childHeight[i];
            i++;
        }
    }

    return i;
    
}

void output(ofstream &outFS, int familyNum[100], int childNum[100], string gender[100], double parentMidpointHeight[100], double childHeight[100], double difference[100], int numOfChildren){
    
    /*
        Pre:
        outFS - output file stream
        familyNum - array holding family number
        childNum - array holding child numbers
        gender - array holding child genders
        parentMidpointHeight - array holding parent midpoint height
        childHeight - array holding child heights
        difference - array holding difference between child and parent midpoint heights
        numOfChildren - number of children

        Purpose:
        Outputs properly formatted data

        Post:
        returns nothing
    */
    
    outFS << setw(13) << left << "family";
    outFS << setw(13) << left << "ParentHtMid";
    outFS << setw(13) << left << "childNum";
    outFS << setw(13) << left << "gender";
    outFS << setw(13) << left << "childHeight";
    outFS << setw(13) << left << "difference" << endl;

    for(int i = 0; i < numOfChildren; i++){
        outFS << setw(6) << right << familyNum[i];
        outFS << setw(18) << right << fixed << setprecision(2) << parentMidpointHeight[i];
        outFS << setw(10) << right << childNum[i] << "     ";
        outFS << setw(6) << left << gender[i];
        outFS << setw(18) << right << fixed << setprecision(1) << childHeight[i];
        outFS << setw(12) << right << fixed << setprecision(1) << difference[i] << endl;
    }

}

double genderAvg(string whatGender, string gender[100], double childHeight[100], int numOfChildren){
    /*
        Pre:
        whatGender - what gender was asked to find the average of
        gender - array holding child genders
        childHeight - array holding child heights
        numOfChildren - number of children

        Purpose:
        Calculates the average of children heights for the specified gender

        Post:
        Returns the average of children heights for the specified gender
    */
    
    int count = 0;
    double heights = 0;
    if(whatGender == "male"){
        for(int i = 0; i < numOfChildren; i++){
            if(gender[i] == "male"){
                count++;
                heights = heights + childHeight[i];
            }
        }
        return (heights / count);
    } else if(whatGender == "female") {
        for(int i = 0; i < numOfChildren; i++){
            if(gender[i] == "female"){
                count++;
                heights = heights + childHeight[i];
            }
        }
        return (heights / count);
    } else {
        for(int i = 0; i < numOfChildren; i++){
                heights = heights + childHeight[i];
        }
        return (heights / numOfChildren);
    }
}

int findCombo(int specFamily, int specChild, int familyNum[100], int childNum[100], int numOfChildren){
    
    /*
        Pre:
        specFamily - specific family that was wanted
        specChild - specific child that was wanted
        familyNum - array holding family numbers
        childNum - array holding child numbers
        numOfChildren - number of children

        Purpose:
        Finds the family and child that was requested

        Post:
        If found, returns the index of the child, otherwise returns -1
    */

    for(int i = 0; i < numOfChildren; i++){
        if((familyNum[i] == specFamily) && (childNum[i] == specChild)){
            return i;
        }
    }
    return -1;
}

void findChildHeight(ofstream &outFS, int familyNum[100], int childNum[100], double parentMidpointHeight[100], double childHeight[100], int numOfChildren){
    /*
        Pre:
        outFS - output file stream
        familyNum - array holding family numbers
        childNum - array holding child numbers
        parentMidpointHeight - array holding parent midpoint heights
        childHeight - array holding child heights
        numOfChildren - number of children

        Purpose:
        Outputs any children and their characteristics whose height is above the specified height to the file

        Post:
        returns nothing
    */
    
    double wantedHeight;
    bool one = false;
    cout << "Enter a child's height: ";
    cin >> wantedHeight;

    for(int i = 0; i < numOfChildren; i++){
        if(childHeight[i] > wantedHeight){
            one = true;
            outFS << setw(6) << right << familyNum[i];
            outFS << setw(18) << right << fixed << setprecision(2) << parentMidpointHeight[i];
            outFS << setw(10) << right << childNum[i];
            outFS << setw(29) << right << fixed << setprecision(1) << childHeight[i] << endl;
        }
    }
    
    if(!one){
        outFS << "No Children with height greater than " << wantedHeight << endl;
    }
}

double calculateStddev(double difference[100], int numOfChildren){

    /*
        Pre:
        difference - array holding diference of child height and parent midpoint heights
        numOfChildren - number of children

        Purpose:
        Calculates the standard deviation of the differences

        Post:
        returns the standard deviation of the differences
    */

    double value = 0;
    double deviations[100];
    for(int i = 0; i < numOfChildren; i++){
        value = value + difference[i];
    }
    value = value / numOfChildren;
    for(int i = 0; i < numOfChildren; i++){
        deviations[i] = difference[i] - value;
    }
    value = 0;
    for(int i = 0; i < numOfChildren; i++){
        deviations[i] = pow(deviations[i], 2);
        value = value + deviations[i];
    }
    value = value / numOfChildren;
    value = sqrt(value);
    return value;  
}

void sortArrays(int familyNum[100], double fatherHeight[100], double motherHeight[100], int childNum[100], string gender[100], double childHeight[100], double parentMidpointHeight[100], double difference [100], int numOfChildren){

    /*
        Pre:
        familyNum - array holding family numbers
        fatherHeight - array holding father heights
        motherHeight - array holding mother heights
        childNum - array holding child numbers
        gender - array holding genders
        childHeight - array holding childHeights
        parentMidpointHeights - array holding parent midpoint heights
        difference - array holding difference of child height and parent midpoint heights
        numOfChildren - number of children

        Purpose:
        Sorts child heights and all other arrays accordingly

        Post:
        returns nothing
    */

    int temp1;
    double temp2;
    string temp3;
    int tallest;

    
    for(int i = 0; i < (numOfChildren - 1); i++){
        tallest = i;
        for(int j = i + 1; j < numOfChildren; j++){
            if(childHeight[j] > childHeight[tallest]){
                tallest = j;
            }
        }
        if(tallest != i){
            temp1 = familyNum[i];
            familyNum[i] = familyNum[tallest];
            familyNum[tallest] = temp1;

            temp2 = fatherHeight[i];
            fatherHeight[i] = fatherHeight[tallest];
            fatherHeight[tallest] = temp2;

            temp2 = motherHeight[i];
            motherHeight[i] = motherHeight[tallest];
            motherHeight[tallest] = temp2;

            temp1 = childNum[i];
            childNum[i] = childNum[tallest];
            childNum[tallest] = temp1;

            temp3 = gender[i];
            gender[i] = gender[tallest];
            gender[tallest] = temp3;

            temp2 = childHeight[i];
            childHeight[i] = childHeight[tallest];
            childHeight[tallest] = temp2;

            temp2 = parentMidpointHeight[i];
            parentMidpointHeight[i] = parentMidpointHeight[tallest];
            parentMidpointHeight[tallest] = temp2;

            temp2 = difference[i];
            difference[i] = difference[tallest];
            difference[tallest] = temp2;
        }
    }

}
