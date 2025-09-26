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

    // Truy cập phần tử tại vị trí pos
    int accessAt(int pos) {
        if (pos < 0 || pos >= n) {
            cout << "Vi tri khong hop le!\n";
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < pos; i++) temp = temp->next;
        return temp->data;
    }

    // Chèn vào đầu
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

    // Chèn vào cuối
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

    // Chèn tại vị trí pos
    void insertAt(int pos, int x) {
        if (pos < 0 || pos > n) return;
        if (pos == 0) return insertFirst(x);
        if (pos == n) return insertLast(x);

        Node* newNode = new Node(x);
        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
        n++;
    }

    // Xoá đầu
    void deleteFirst() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
        if (!head) tail = nullptr; 
    }

    // Xoá cuối
    void deleteLast() {
        if (!head) return;
        if (head == tail) { 
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) temp = temp->next;
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        n--;
    }

    // Xoá tại vị trí pos
    void deleteAt(int pos) {
        if (pos < 0 || pos >= n) return;
        if (pos == 0) return deleteFirst();
        if (pos == n - 1) return deleteLast();

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) temp = temp->next;
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        n--;
    }

    // Duyệt xuôi
    void printForward() {
        cout << "Duyet xuoi: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Duyệt ngược 
    void printBackwardHelper(Node* node) {
        if (!node) return;
        printBackwardHelper(node->next);
        cout << node->data << " ";
    }
    void printBackward() {
        cout << "Duyet nguoc: ";
        printBackwardHelper(head);
        cout << endl;
    }
};

int main() {
    LinkedList lst;

    lst.insertLast(1);
    lst.insertLast(2);
    lst.insertFirst(3);
    lst.insertAt(1, 15);

    lst.printForward();
    lst.printBackward();

    lst.deleteAt(1);
    lst.deleteFirst();
    lst.deleteLast();

    lst.printForward();
}
