#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = { 5, 2, 9, 1, 5, 6 };
    int arr2[] = { 5, 2, 9, 1, 5, 6 };
    int arr3[] = { 5, 2, 9, 1, 5, 6 };
    int n = 6;

    cout << "Bubble Sort: ";
    bubbleSort(arr1, n);
    printArray(arr1, n);

    cout << "Selection Sort: ";
    selectionSort(arr2, n);
    printArray(arr2, n);

    cout << "Insertion Sort: ";
    insertionSort(arr3, n);
    printArray(arr3, n);

    return 0;
}
