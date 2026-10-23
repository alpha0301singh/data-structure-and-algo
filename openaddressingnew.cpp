#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE]; 

void insert(int key) {
    int index = key % SIZE;
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        if (hashTable[i] == -1) {
            cout << "-\n"; 
        } else {
            cout << hashTable[i] << "\n";
        }
    }
}
void search(int key) {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == key) {
            cout << key << " is FOUND at index " << i << ".\n";
            return; // Found it, stop searching and exit
        }
    }
    cout << key << " is NOT found.\n";
}

int main() {
    
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    insert(12);
    insert(22);
    insert(32);

    display();


    search(22);
    search(33);
    return 0;
}
