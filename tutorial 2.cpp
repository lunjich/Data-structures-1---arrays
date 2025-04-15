#include <iostream>
using namespace std;

void mergeArray (int arr1[], int arr2[],int arr3[], int n){
    for (int i = 0; i < n; i++) {
        arr3[i] = arr1[i];
    }

    for (int i = 0; i < n; i++) {
        arr3[i + n] = arr2[i];
    }
    cout << "Merged Array: ";
    for (int i = 0; i < 2 * n; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
}

int main(){
   const int n=4;
   int arr1[n]={1, 2, 3, 4};
   int arr2[n]={5, 6, 7, 8};
   int arr3[n+n];

    mergeArray(arr1, arr2, arr3, n);
}