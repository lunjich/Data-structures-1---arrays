#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int first, int mid, int last) {
    int first1 = first, last1 = mid;
    int first2 = mid + 1, last2 = last;

    int temp[last - first + 1];
    int index = 0;

    while (first1 <= last1 && first2 <= last2) {
        if (arr[first1] <= arr[first2])
            temp[index++] = arr[first1++];
        else
            temp[index++] = arr[first2++];
    }

    while (first1 <= last1)
        temp[index++] = arr[first1++];

    while (first2 <= last2)
        temp[index++] = arr[first2++];

    for (int i = 0; i < index; i++)
        arr[first + i] = temp[i];
}

void mergeSort(int arr[], int first, int last) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main() {
    int n = 8;
    int arr[n] = {2, 7, 5, 8, 3, 1, 6, 4};

    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}