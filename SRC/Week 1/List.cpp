#include <iostream>
using namespace std;

struct List {
    int arr[1000];
    int size = 0;

    // Truy cập phần tử
    int accessAt(int pos) {
        return arr[pos];
    }

    // Chèn vào đầu
    void insertFirst(int x) {
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = x;
        size++;
    }

    // Chèn vào cuối
    void insertLast(int x) {
        arr[size] = x;
        size++;
    }

    // Chèn vào vị trí pos
    void insertAt(int pos, int x) {
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = x;
        size++;
    }

    // Xoá đầu
    void deleteFirst() {
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Xoá cuối
    void deleteLast() {
        if (size == 0) return;
        size--;
    }

    // Xoá tại vị trí pos
    void deleteAt(int pos) {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Duyệt xuôi
    void printForward() {
        cout << "Duyet xuoi: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Duyệt ngược
    void printBackward() {
        cout << "Duyet nguoc: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    List lst;
    lst.insertLast(10);
    lst.insertLast(20);
    lst.insertFirst(5);
    lst.insertAt(1, 15);

    lst.printForward();
    lst.printBackward();

    lst.deleteAt(1);
    lst.deleteFirst();
    lst.deleteLast();

    lst.printForward();
}
