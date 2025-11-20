#include <bits/stdc++.h>
using namespace std;

class HashTableLinear {
private:
    vector<int> table;
    int capacity;
    const int EMPTY = -1;
    const int DELETED = -2;

public:
    HashTableLinear(int cap = 10) {
        capacity = cap;
        table.assign(capacity, EMPTY);
    }

    int hashFunc(int key) {
        return key % capacity;
    }

    void insertKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        while (table[idx] != EMPTY && table[idx] != DELETED) {
            idx = (idx + 1) % capacity;
            if (idx == start) {
                cout << "Hash Table Full!\n";
                return;
            }
        }
        table[idx] = key;
    }

    bool searchKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        while (table[idx] != EMPTY) {
            if (table[idx] == key) return true;
            idx = (idx + 1) % capacity;
            if (idx == start) return false;
        }
        return false;
    }

    void deleteKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        while (table[idx] != EMPTY) {
            if (table[idx] == key) {
                table[idx] = DELETED;
                return;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) return;
        }
    }

    void printTable() {
        cout << "Linear Hash Table: ";
        for (int x : table) cout << x << " ";
        cout << "\n";
    }
};

class HashTableChaining {
private:
    vector<vector<int>> table;
    int capacity;

public:
    HashTableChaining(int cap = 10) {
        capacity = cap;
        table.assign(capacity, {});
    }

    int hashFunc(int key) {
        return key % capacity;
    }

    void insertKey(int key) {
        int idx = hashFunc(key);
        table[idx].push_back(key);
    }

    bool searchKey(int key) {
        int idx = hashFunc(key);
        for (int x : table[idx]) if (x == key) return true;
        return false;
    }

    void deleteKey(int key) {
        int idx = hashFunc(key);
        auto& bucket = table[idx];
        bucket.erase(remove(bucket.begin(), bucket.end(), key), bucket.end());
    }

    void printTable() {
        cout << "Chaining Hash Table:\n";
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "NULL\n";
        }
    }
};

int main() {
    cout << "===== Linear Probing =====\n";
    HashTableLinear h1(7);
    h1.insertKey(10);
    h1.insertKey(20);
    h1.insertKey(5);
    h1.insertKey(7);
    h1.insertKey(17);

    h1.printTable();

    cout << "Search 7: " << (h1.searchKey(7) ? "Found" : "Not Found") << "\n";
    h1.deleteKey(7);
    cout << "Search 7 after delete: " << (h1.searchKey(7) ? "Found" : "Not Found") << "\n";
    h1.printTable();


    cout << "\n===== Chaining =====\n";
    HashTableChaining h2(7);
    h2.insertKey(10);
    h2.insertKey(20);
    h2.insertKey(5);
    h2.insertKey(7);
    h2.insertKey(17);

    h2.printTable();

    cout << "Search 7: " << (h2.searchKey(7) ? "Found" : "Not Found") << "\n";
    h2.deleteKey(7);
    cout << "Search 7 after delete: " << (h2.searchKey(7) ? "Found" : "Not Found") << "\n";
    h2.printTable();

    return 0;
}
