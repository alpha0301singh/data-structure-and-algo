#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int roll;

    Node() {
        roll = -1;
    }
};

Node table[SIZE];

void insert(int roll) {

    int index = roll % SIZE;

    while (table[index].roll != -1) {

        index = (index + 1) % SIZE;
    }

    table[index].roll = roll;
}

void search(int roll) {

    int index = roll % SIZE;
    int start = index;

    while (table[index].roll != -1) {

        if (table[index].roll == roll) {

            cout << "Roll number found\n";
            return;
        }

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    cout << "Roll number not found\n";
}

void display() {

    cout << "\nHash Table:\n";

    for (int i = 0; i < SIZE; i++) {

        cout << i << " : ";

        if (table[i].roll == -1)
            cout << "EMPTY";
        else
            cout << table[i].roll;

        cout << endl;
    }
}

int main() {

    insert(12);
    insert(22);
    insert(32);
    

    cout << "Student Roll Numbers:\n";

    display();

    cout << "\nSearching for 111:\n";
    search(32);

    cout << "\nSearching for 120:\n";
    search(22);

    return 0;
}