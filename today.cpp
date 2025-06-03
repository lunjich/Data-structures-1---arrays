#include <iostream>
using namespace std;

// Print array
void printArray(int arr[], int size, const string& msg) {
    cout << msg << ": ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Merge two halves (ascending)
void mergeAsc(int arr[], int left, int mid, int right) {
    int temp[100]; // temp array
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int m = 0; m < k; m++)
        arr[left + m] = temp[m];

    printArray(arr, right + 1, "Step (Asc)");
}

// Merge sort (ascending)
void mergeSortAsc(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSortAsc(arr, left, mid);
    mergeSortAsc(arr, mid + 1, right);
    mergeAsc(arr, left, mid, right);
}

// Merge two halves (descending)
void mergeDesc(int arr[], int left, int mid, int right) {
    int temp[100];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int m = 0; m < k; m++)
        arr[left + m] = temp[m];

    printArray(arr, right + 1, "Step (Desc)");
}

// Merge sort (descending)
void mergeSortDesc(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSortDesc(arr, left, mid);
    mergeSortDesc(arr, mid + 1, right);
    mergeDesc(arr, left, mid, right);
}

int main() {
    int arr1[] = {38, 27, 43, 3, 9, 82, 10};
    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    cout << "--- Ascending Order ---" << endl;
    printArray(arr1, size, "Original");
    mergeSortAsc(arr1, 0, size - 1);
    printArray(arr1, size, "Sorted Asc");

    cout << "\n--- Descending Order ---" << endl;
    printArray(arr2, size, "Original");
    mergeSortDesc(arr2, 0, size - 1);
    printArray(arr2, size, "Sorted Desc");

    return 0;
}