#include <iostream>
using namespace std;

int hello(){
    cout << "Hello World\n";
    return 0;
}

int enterNumber(){
    int num;
    cout << "Enter a number:";
    cin >> num;
    cout << "Entered number: " << num << "\n";
    return 0;
}

int asciiValue(){
    char c;
    cout << "Enter a char:";
    cin >> c;
    cout << "Ascii value of " << c << " is " << int(c) << "\n";
    return 0;
}

int swapValues(){
    int a;
    int b;
    int temp;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    cout << "The value of a is " << a << " and the value of b is " << b << "\n";
    temp = b;
    b = a;
    a = temp;
    cout << "The value of a is " << a << " and the value of b is " << b << "\n";
    return 0;
}

int evenOrOdd(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if(num % 2 == 0){
        cout << num << " is an even number \n";
    } else {
        cout << num << " is an odd number \n";
    }return 0;
}

int largest(){
    int a;
    int b;
    int c;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter another number: ";
    cin >> b;
    cout << "Enter another number: ";
    cin >> c;
    if((a > b) & (a > c)){
        cout << a << " is the largest number\n";
    } else if ((b > a) & (b > c)){
        cout << b << " is the largest number\n";
    } else if ((c > a) & (c > b)){
        cout << c << " is the largest number\n";
    } else {
        cout << a << ", " << b << ", and " << c << " are equal\n";
    }
    return 0;
}

int palindrome(){
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int copy = num;
    int reversed = 0;
    while(copy != 0){
        reversed = (reversed * 10) + (copy % 10);
        copy = copy / 10;
    }
    if(num == reversed){
        cout << num << " is a palindrome \n";
    } else {
        cout << num << " is not a palindrome \n";
    }
    return 0;

}

int checkArrays(){
    int arr[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4};
    if((sizeof(arr) / sizeof(arr[0])) != (sizeof(arr2) / sizeof(arr2[0]))){
        cout << "Arrays are not equal \n";
        return 0;
    } else {
        for(int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++){
            if(arr[i] != arr2[i]){
                cout << "Arrays are not equal \n";
                return 0;
            }
        }
        cout << "Arrays are equal \n";
        return 0;
    }
    return 0;
}



int main(){
    checkArrays();
    return 0;
}