#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int>& arr, const string& msg) {
    cout << msg << ": ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Merge function for ascending order
void mergeAscending(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] <= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < leftPart.size())
        arr[k++] = leftPart[i++];
    while (j < rightPart.size())
        arr[k++] = rightPart[j++];

    printArray(arr, "After merging (asc)");
}

// Merge function for descending order
void mergeDescending(vector<int>& arr, int left, int mid, int right) {
    vector<int> leftPart(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightPart(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i] >= rightPart[j]) {
            arr[k++] = leftPart[i++];
        } else {
            arr[k++] = rightPart[j++];
        }
    }
    while (i < leftPart.size())
        arr[k++] = leftPart[i++];
    while (j < rightPart.size())
        arr[k++] = rightPart[j++];

    printArray(arr, "After merging (desc)");
}

// Merge sort recursive function for ascending
void mergeSortAscending(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        cout << "Dividing (asc): ";
        for (int i = left; i <= right; i++) cout << arr[i] << " ";
        cout << endl;

        mergeSortAscending(arr, left, mid);
        mergeSortAscending(arr, mid + 1, right);
        mergeAscending(arr, left, mid, right);
    }
}

// Merge sort recursive function for descending
void mergeSortDescending(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        cout << "Dividing (desc): ";
        for (int i = left; i <= right; i++) cout << arr[i] << " ";
        cout << endl;

        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);
        mergeDescending(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};
    vector<int> arr2 = arr1; // Copy for descending

    cout << "Original Array: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n--- Ascending Sort ---\n";
    mergeSortAscending(arr1, 0, arr1.size() - 1);

    cout << "\nSorted in Ascending: ";
    for (int x : arr1) cout << x << " ";
    cout << "\n\n--- Descending Sort ---\n";
    mergeSortDescending(arr2, 0, arr2.size() - 1);

    cout << "\nSorted in Descending: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}