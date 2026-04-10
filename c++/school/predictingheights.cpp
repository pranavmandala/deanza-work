/*
    Pranav Mandala
    Lab 6 Predicting Heights
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void output(ofstream &outFS, int family, double father, double mother, int childNum, string gender, double childHeight);

int main(){
    //Declaring file streams
    ifstream inFS;
    ofstream outFS;
    
    //Declaring variables that will hold the values of each line of input
    int family;
    double father;
    double mother;
    int children;
    int childNum;
    string gender;
    double childHeight;

    //Intializing counters to check whether a family's parents heights have already been counted
    int prevFamily = 0;
    int familyCount = 0;

    //Intiallizing variables for the calculations
    int numOfChildren = 0;
    double avgParentMidpointHeights = 0;
    double avgChildHeights = 0;
    
    //Declaring values for the tallest child and its attributes
    int tallestChildFamily;
    int tallestChildNum;
    double tallestChildHeight;
    string test;

    //Opening the file
    inFS.open("Lab6DataW26.txt");
    outFS.open("output.txt");

    //If the file is successfully opened, read the headers first to get to the data
    if(inFS.is_open()){
        for(int i = 0; i < 7; i++){
            inFS >> test;
        }
    } else {
        cout << "Could not open Lab6DataW26.txt" << endl;
        return 1;
    }

    //Outputting the headers directly to the output file
    outFS << setw(13) << left << "family";
    outFS << setw(13) << left << "childNum";
    outFS << setw(13) << left << "gender";
    outFS << setw(13) << left << "parentMid";
    outFS << setw(13) << left << "childHeight";
    outFS << setw(13) << left << "difference" << endl;
    
    //Looping until the file stream is at the end of the file
    while(!inFS.eof()){
        inFS >> family;
        inFS >> father;
        inFS >> mother;
        inFS >> children;
        inFS >> childNum;
        inFS >> gender;
        inFS >> childHeight;
        numOfChildren++;
        if(numOfChildren == 1){
            tallestChildHeight = childHeight;
            tallestChildNum = childNum;
            tallestChildFamily = family;
        } else {
            if(childHeight >= tallestChildHeight){
                tallestChildHeight = childHeight;
                tallestChildNum = childNum;
                tallestChildFamily = family;
            }
        }        
        //Checking if a family has already been counted
        if(family > prevFamily){
            avgParentMidpointHeights = avgParentMidpointHeights + ((father + mother) / 2);
            prevFamily = family;
            familyCount++;
        }
        
        avgChildHeights = avgChildHeights + childHeight;
        output(outFS, family, father, mother, childNum, gender, childHeight);
        
    }

    //Taking the average of the parent midpoint heights by dividing by number of families
    avgParentMidpointHeights = (avgParentMidpointHeights / familyCount);

    //Taking the average of the child heights by dividing by number of children
    avgChildHeights = (avgChildHeights / numOfChildren);

    cout << "Number of children: " << numOfChildren << endl;
    cout << "Average of Parent Midpoint Heights: " << fixed << setprecision(1) << avgParentMidpointHeights << endl;
    cout << "Average Child Heights: " << fixed << setprecision(1) << avgChildHeights << endl;
    cout << "Tallest Child: Family " << tallestChildFamily << " Child: " << tallestChildNum << " Height: " << tallestChildHeight << endl;
    cout << "\nProgrammed by Pranav Mandala\n";
    inFS.close();
    outFS.close();
    return 0;
}

void output(ofstream &outFS, int family, double father, double mother, int childNum, string gender, double childHeight){
    /*
        Pre:
        outFS - reference to the output file stream
        family - what family number it is
        father - height of the father
        mother - height of the mother
        childNum - what number child it is
        childHeight - height of the child
        
        Purpose:
        Calculates the midpoint of the fathers and mothers heights and the difference between the midpoint and child height, Outputs info from each interation to the output file
        
        Post:
        Doesn't return anything
    */
    
    double parentMid = (father + mother) / 2;
    double difference = parentMid - childHeight;
    
    outFS << setw(6) << right << family;
    outFS << setw(15) << right << childNum;
    outFS << "     " << setw(6) << left << gender;
    outFS << setw(16) << right << fixed << setprecision(2) << parentMid;
    outFS << setw(15) << right << fixed << setprecision(1) << childHeight;
    outFS << setw(12) << right << fixed << setprecision(1) << difference << endl;
}