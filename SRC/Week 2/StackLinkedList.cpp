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

    void insertFirst(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        n++;
    }

    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
        if (!head) tail = nullptr;
    }

    int accessFirst() {
        if (!head) {
            return -1; 
        }
        return head->data;
    }

    bool isEmpty() {
        return head == nullptr;
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

struct Stack {
    LinkedList list;
    void push(int val) {
        list.insertFirst(val);
    }

    void pop() {
        list.deleteFirst();
    }

    int top()  {
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
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    s.display(); 
    cout <<s.top() << endl; 

    s.pop();
    s.display();
    cout << s.top() << endl; 

    return 0;
}

