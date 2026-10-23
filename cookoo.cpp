#include <iostream>
using namespace std;

const int SIZE = 10;

struct HashTable {
    int table1[SIZE];
    int table2[SIZE];

    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table1[i] = -1;
            table2[i] = -1;
        }
    }

    int hash1(int key) {
        return key % SIZE;
    }

    int hash2(int key) {
        return (key / SIZE) % SIZE;
    }

    void insert(int key) {
        int count = 0;

        while (count < SIZE) {

            // First hash table
            int pos1 = hash1(key);

            if (table1[pos1] == -1) {
                table1[pos1] = key;
                return;
            }

            // Move old value to second table
            int temp = table1[pos1];
            table1[pos1] = key;
            key = temp;

            // Second hash table
            int pos2 = hash2(key);

            if (table2[pos2] == -1) {
                table2[pos2] = key;
                return;
            }

            // Move old value back to first table
            temp = table2[pos2];
            table2[pos2] = key;
            key = temp;

            count++;
        }

        cout << "Cannot insert " << key << endl;
    }

    void display() {
        cout << "Table 1:" << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : " << table1[i] << endl;
        }

        cout << endl << "Table 2:" << endl;

        for (int i = 0; i < SIZE; i++) {
            cout << i << " : " << table2[i] << endl;
        }
    }
};

int main() {
    HashTable h;

    // Student roll numbers
    h.insert(23);
    h.insert(15);
    h.insert(35);
    h.insert(42);
    h.insert(12);

    h.display();

    return 0;
}