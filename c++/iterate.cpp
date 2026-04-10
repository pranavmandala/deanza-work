#include <iostream>
using namespace std;

void result(){
    int nums[] = {1,2,3,4};
    for(int i = 0; i < sizeof(nums); i++){
        cout << nums[i];
    }
}

int main(){
    result();
    return 0;
}