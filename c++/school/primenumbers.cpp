/*
    Pranav Mandala
    Hands on 5 - Summing Prime numbers
    pranav.mandala07@gmail.com
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int begin;
    int end;
    int count = 0;
    int sum = 0;

    cout << "Enter the number you want to start at: ";
    cin >> begin;
    cout << "Enter the number you want to end at: ";
    cin >> end;

    for(int i = begin; i <= end; i++){
        if(i == 1){
            sum--;
        }
        for(int j = 1; j <= sqrt(i); j++){
            if((i % j) == 0){
                count++;
            }
        }
        if(count < 2){
            sum = sum + i;
        }
        count = 0;
    }

    cout << "The sum of prime numbers from " << begin << " and " << end << " is " << sum << ".\n";
}
/*
    Test Data: 50 to 100
    Enter the number you want to start at: 50
    Enter the number you want to end at: 100
    The sum of prime numbers from 50 and 100 is 732.
*/