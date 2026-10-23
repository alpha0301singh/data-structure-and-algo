#include <iostream>
using namespace std;

const int SIZE = 4;

struct Node {
    int roll;
    Node *next;

    Node(int r) {
        roll = r;
        next = nullptr;
    }
};

Node *table[SIZE];



void insert(int roll) {

    int index = roll % SIZE;

    Node *newNode = new Node(roll);

    if (table[index] == nullptr) {

        table[index] = newNode;
    }
    else {

        newNode->next = table[index];
        table[index] = newNode;
    }
}




void search(int roll) {

    int index = roll % SIZE;

    Node *temp = table[index];

    while (temp != nullptr) {

        if (temp->roll == roll) {

            cout << "Roll number found\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Roll number not found\n";
}



void display() {

    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {

        cout << i << " : ";

        Node *temp = table[i];

        while (temp != nullptr) {

            cout << temp->roll << " -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }
}


// ------------------------------------------------
// MAIN
// ------------------------------------------------

int main() {

    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }

    insert(101);
    insert(102);
    insert(111);
    insert(121);
    insert(115);

    cout << "Student Roll Numbers:\n";

    display();

    cout << "\nSearching for 111:\n";
    search(111);

    cout << "\nSearching for 120:\n";
    search(120);

    return 0;
}