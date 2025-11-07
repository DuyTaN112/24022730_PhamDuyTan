#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    int value;
    Node* next;
    Node(string k, int v, Node* n = nullptr)
        : key(k), value(v), next(n) {
    }
};

struct SymbolTableLinkedList {
    Node* head;
    int n;

    SymbolTableLinkedList() : head(nullptr), n(0) {}

    void put(string key, int value) {
        if (head == nullptr || key < head->key) {
            head = new Node(key, value, head);
            n++;
            return;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr && curr->key < key) {
            prev = curr;
            curr = curr->next;
        }
        if (curr && curr->key == key) {
            curr->value = value;
            return;
        }
        prev->next = new Node(key, value, curr);
        n++;
    }

    int get(string key) {
        Node* curr = head;
        while (curr) {
            if (curr->key == key)
                return curr->value;
            curr = curr->next;
        }
        return -1; 
    }

    string min() {
        if (!head) return "";
        return head->key;
    }

    string max() {
        if (!head) return "";
        Node* curr = head;
        while (curr->next) curr = curr->next;
        return curr->key;
    }

    string floor(string key) {
        string result = "";
        Node* curr = head;
        while (curr) {
            if (curr->key <= key)
                result = curr->key;
            else
                break;
            curr = curr->next;
        }
        return result;
    }

    string ceiling(string key) {
        Node* curr = head;
        while (curr) {
            if (curr->key >= key)
                return curr->key;
            curr = curr->next;
        }
        return "";
    }

    int rank(string key) {
        int count = 0;
        Node* curr = head;
        while (curr && curr->key < key) {
            count++;
            curr = curr->next;
        }
        return count;
    }

    string select(int k) {
        if (k < 0 || k >= n) return "";
        Node* curr = head;
        for (int i = 0; i < k; i++)
            curr = curr->next;
        return curr->key;
    }

    void deleteMin() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        n--;
    }

    void deleteMax() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            n--;
            return;
        }

        Node* curr = head;
        while (curr->next->next)
            curr = curr->next;

        delete curr->next;
        curr->next = nullptr;
        n--;
    }

    int size(string lo, string hi) {
        int count = 0;
        Node* curr = head;
        while (curr) {
            if (curr->key >= lo && curr->key <= hi)
                count++;
            curr = curr->next;
        }
        return count;
    }

    void keys() {
        Node* curr = head;
        while (curr) {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void keys(string lo, string hi) {
        Node* curr = head;
        while (curr) {
            if (curr->key > lo && curr->key < hi)
                cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void printKeys() {
        Node* curr = head;
        while (curr) {
            cout << "(" << curr->key << ", " << curr->value << ") ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    SymbolTableLinkedList s;
    s.put("E", 5);
    s.put("A", 1);
    s.put("S", 19);
    s.put("Y", 25);
    s.put("Q", 17);
    s.put("U", 21);
    s.put("T", 20);
    s.put("I", 9);
    s.put("O", 15);
    s.put("N", 14);

    cout << "All keys: ";
    s.printKeys();

    cout << "Min: " << s.min() << endl;
    cout << "Max: " << s.max() << endl;
    cout << "Floor('P'): " << s.floor("P") << endl;
    cout << "Ceiling('P'): " << s.ceiling("P") << endl;
    cout << "Rank('Q'): " << s.rank("Q") << endl;
    cout << "Select(3): " << s.select(3) << endl;
    cout << "Size(A, Q): " << s.size("A", "Q") << endl;

    cout << "\nDeleting Min and Max...\n";
    s.deleteMin();
    s.deleteMax();
    s.printKeys();

    cout << "Get('T') = " << s.get("T") << endl;

    return 0;
}
