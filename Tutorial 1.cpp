#include <iostream>
using namespace std;
   
  

void swapp(int *x, int *y);

int main(){
   /* int a = 14;
    int b = 13;
    int c = 15;

    int max = a;
    if (b > max) {
        max = b;
        cout << "b is the maximum" << endl;

    }
    else if (c > max) {
        max = c;
        cout << "c is the maximum" << endl;

    }
    else {
        cout << "a is the maximum" << endl;
    }*/

   /* int arr[5] = {1, 999, 7, 4, 5000};
    int max = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }cout << max << endl;*/
    
  /* int arr1[3][3] = {{1, 2, 3}, {10, 5, 6}, {7, 8, 9}};
    int max1 = arr1[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr1[i][j] > max1) {
                max1 = arr1[i][j];
            }
        }
    }
    cout << max1 << endl;*/
     int a = 10;
     int b = 3;
     swapp(&a,&b);
     /*a= a + b; 
     b = a - b; 
     a= a - b; */

    return 0;
}

/*void swapp(int &a, int &b) {
   int temp =a;
   a=b;
   b=temp;
   cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << &b << endl;
    
}*/

/*void swap1 (int *x, int *y) {
   
} */

void swapp(int *x, int *y)
{
    
    int temp =*x;
    *x = *y;
    *y = temp;
    cout << "a: " << *x << endl;
    cout << "b: " << *y << endl;
}
