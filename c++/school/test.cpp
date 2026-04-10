#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void sound(){
            cout << "Sound an animal makes";
        }
};

class Dog : public Animal{
    public:
        void sound(){
            cout << "Bark";
        }
};

int main(){

    Dog doggo;
    Animal* dptr = &doggo;
    dptr -> sound();
    cout << endl;

}