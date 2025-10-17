#include <iostream>
using namespace std;

class MaxBinaryHeap {
private:
    int arr[101];  
    int N;         

    void swap(int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

public:
    MaxBinaryHeap() {
        N = 0;
    }
    bool isEmpty() {
        return N == 0;
    }
    int size() {
        return N;
    }
    int max() {
        if (isEmpty()) {
            cout << "Heap rong";
            return -1;
        }
        return arr[1];
    }

    void swim(int k) {
        while (k > 1 && arr[k / 2] < arr[k]) {
            swap(k, k / 2);
            k = k / 2; 
        }
    }

    void sink(int k) {
        while (2 * k <= N) {
            int j = 2 * k; 
            if (j < N && arr[j] < arr[j + 1]) j++; 
            if (arr[k] >= arr[j]) break;           
            swap(k, j);
            k = j; 
        }
    }

    void insert(int data) {
        if (N >= 100) {
            cout << "Heap day";
            return;
        }
        arr[++N] = data; 
        swim(N);        
    }

    int delMax() {
        if (isEmpty()) {
            cout << "Heap rong";
            return -1;
        }
        int maxVal = arr[1];
        swap(1, N--); 
        sink(1);     
        return maxVal;
    }

    void printHeap() {
        cout << "Heap: ";
        for (int i = 1; i <= N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MaxBinaryHeap heap;

    heap.insert(10);
    heap.insert(40);
    heap.insert(30);
    heap.insert(50);
    heap.insert(5);

    heap.printHeap();  
    cout << "Max: " << heap.max() << endl; 

    cout << "Delete max: " << heap.delMax() << endl; 
    heap.printHeap();  
    cout << "New max: " << heap.max() << endl;

    cout << "Heap size: " << heap.size() << endl;
}

