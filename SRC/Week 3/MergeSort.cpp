#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;   
    int n2 = right - mid;   

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
    delete[] L;  
    delete[] R;
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);    
        mergeSort(a, mid + 1, right); 
        merge(a, left, mid, right);  
    }
}

int main() {
    int arr[] = { 38, 27, 43, 3, 9, 82, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

