#include <iostream>
using namespace std;

struct List {
    int arr[1000];
    int size = 0;

    void insertLast(int x) {
        arr[size] = x;
        size++;
    }

    void deleteFirst() {
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int accessFirst() {
        return arr[0];
    }

    bool isEmpty() {
        return size == 0;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

struct Queue {
    List list;

    void enqueue(int val) {
        list.insertLast(val);
    }

    void dequeue() {
        list.deleteFirst();
    }

    int peek() {
        return list.accessFirst();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void display() {
        list.print();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    cout<<q.peek();
}