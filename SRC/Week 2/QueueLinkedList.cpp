#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

struct LinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n = 0;

    void insertLast(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        n++;
    }

    void deleteFirst() {
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
        if (!head) tail = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int accessFirst() {
        return head->data;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

struct Queue {
    LinkedList list;
    void enqueue(int val) {
        list.insertLast(val);
    }

    void dequeue() {
        if (list.isEmpty()) {
            cout << "Queue rong, khong the dequeue!\n";
            return;
        }
        list.deleteFirst();
    }

    int peek() {
        return list.accessFirst();
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    void display() {
        cout << "Queue: ";
        list.print();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display(); // Queue: 10 20 30

    q.dequeue();
    q.display(); // Queue: 20 30

    cout << "Phan tu dau: " << q.peek() << endl;
}
