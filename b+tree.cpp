#include <iostream>
using namespace std;

const int MAX = 4;

struct Node {
    int key[MAX + 1];
    Node *child[MAX + 2];
    Node *next;
    int n;

    Node() {
        n = 0;
        next = nullptr;

        for (int i = 0; i < MAX + 2; i++)
            child[i] = nullptr;
    }
};

Node *root = nullptr;

// Insert in a node which is not full


void InsertNotFull(Node *node, int x) {

    int i = node->n - 1;

    // If node is leaf
    if (node->child[0] == nullptr) {

        while (i >= 0 && x < node->key[i]) {
            node->key[i + 1] = node->key[i];
            i--;
        }

        node->key[i + 1] = x;
        node->n++;
    }

    // If node is not leaf
    else {

        while (i >= 0 && x < node->key[i])
            i--;

        i++;

        // If child is full
        if (node->child[i]->n == MAX) {

            split(node, node->child[i]);

            if (x >= node->key[i])
                i++;
        }

        InsertNotFull(node->child[i], x);
    }
}


// Split a full child

void split(Node *parent, Node *full) {

    Node *newNode = new Node();

    // If full node is leaf
    if (full->child[0] == nullptr) {

        newNode->key[0] = full->key[2];
        newNode->key[1] = full->key[3];

        newNode->n = 2;
        full->n = 2;

        // Connect leaf nodes
        newNode->next = full->next;
        full->next = newNode;

        // Find where full node is
        int i = 0;

        while (parent->child[i] != full)
            i++;

        // Move keys
        for (int j = parent->n; j > i; j--)
            parent->key[j] = parent->key[j - 1];

        parent->key[i] = newNode->key[0];

        // Move children
        for (int j = parent->n + 1; j > i + 1; j--)
            parent->child[j] = parent->child[j - 1];

        parent->child[i + 1] = newNode;

        parent->n++;
    }

    // If full node is not leaf
    else {

        newNode->key[0] = full->key[3];
        newNode->n = 1;

        newNode->child[0] = full->child[3];
        newNode->child[1] = full->child[4];

        int middle = full->key[2];

        full->n = 2;

        // Find where full node is
        int i = 0;

        while (parent->child[i] != full)
            i++;

        // Move keys
        for (int j = parent->n; j > i; j--)
            parent->key[j] = parent->key[j - 1];

        parent->key[i] = middle;

        // Move children
        for (int j = parent->n + 1; j > i + 1; j--)
            parent->child[j] = parent->child[j - 1];

        parent->child[i + 1] = newNode;

        parent->n++;
    }
}



// Insert


void insert(int x) {

    // If tree is empty
    if (root == nullptr) {

        root = new Node();

        root->key[0] = x;
        root->n = 1;

        return;
    }

    // If root is full
    if (root->n == MAX) {

        Node *newRoot = new Node();

        newRoot->child[0] = root;

        root = newRoot;

        split(root, root->child[0]);
    }

    InsertNotFull(root, x);
}



// Display B+ Tree


void display(Node *node) {

    if (node == nullptr)
        return;

    for (int i = 0; i < node->n; i++)
        cout << node->key[i] << " ";

    cout << endl;

    if (node->child[0] != nullptr) {
        for (int i = 0; i <= node->n; i++)
            display(node->child[i]);
    }
}


// Range Search


void rangeSearch(int low, int high) {

    if (root == nullptr)
        return;

    Node *current = root;

    // Go to leaf node
    while (current->child[0] != nullptr) {

        int i = 0;

        while (i < current->n && low >= current->key[i])
            i++;

        current = current->child[i];
    }

    cout << "Range Search: ";

    // Search through leaf nodes
    while (current != nullptr) {

        for (int i = 0; i < current->n; i++) {

            if (current->key[i] >= low &&
                current->key[i] <= high)

                cout << current->key[i] << " ";

            if (current->key[i] > high) {
                cout << endl;
                return;
            }
        }

        current = current->next;
    }

    cout << endl;
}



// Main


int main() {

    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    insert(7);
    insert(17);

    cout << "B+ Tree:" << endl;

    display(root);

    cout << endl;

    rangeSearch(6, 20);

    return 0;
}