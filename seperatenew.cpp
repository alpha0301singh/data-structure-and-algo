#include <iostream>
#include <list>
using namespace std;


const int SIZE = 10; 
list<int> hashTable[SIZE]; 


void insert(int key) {
    
    int index = key % SIZE; 
    hashTable[index].push_back(key);

}

void display() {
    for (int i = 0; i < SIZE; i++) {
        cout << "Bucket " << i << ":";
        
        
        for (int item : hashTable[i]) {
            cout << " -> " << item;
        }
        cout << "\n"; 
    }
}

void search(int key) {
    int index = key % SIZE; 
    
    
    for (int item : hashTable[index]) {
        if (item == key) {
            cout << key << " is FOUND in Bucket " << index << ".\n";
            return; 
        }
    }
    
    
    cout << key << " is NOT found in the table.\n";
}

int main() {
    
    insert(12);
    insert(22);
    insert(32);
    
    display(); 
    return 0;
}


