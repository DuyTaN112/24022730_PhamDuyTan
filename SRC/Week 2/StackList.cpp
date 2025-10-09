#include <iostream>
using namespace std;


struct List {
    int arr[1000];
    int size = 0;

    void insertLast(int x) {
        arr[size++] = x;
    }

    void deleteLast() {
        if (size == 0) return;
        size--;
    }

    int accessLast() {
    if (size == 0) {
            return -1;
        }
    return arr[size - 1];
    }

    bool isEmpty() {
        return size == 0;
    } 
};


struct Stack {
    List list;

    void push(int x) {
        list.insertLast(x);
    }

    int pop() {
        list.deleteLast();
    }

    int top() {
        return list.accessLast();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void print() {
        for (int i = 0; i < list.size; i++) {
            cout << list.arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.print();
    cout << s.top() << endl;

    s.pop();
    s.print(); 
    cout << s.top() << endl; 

    return 0;
}
