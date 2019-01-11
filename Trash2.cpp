#include <iostream>
using namespace std;

int main(){
    
    int arr[30];

    arr[8] = 67;
    cout << arr[8];

    delete(arr);
    cout << arr[8];

    return 0;
} 