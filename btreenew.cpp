#include <iostream>
using namespace std;

const int MAX = 4;

struct Node{
    int key[MAX + 1];
    Node *child[MAX + 2];
    int n;

    Node() {
        n = 0;
        for (int i = 0; i < MAX + 2; i++)
            child[i] = nullptr;
    }
};

Node *root = nullptr;




Node* split(Node *full, int &middle)
{
    Node *newNode = new Node();

    

    middle = full->key[2];

    // Right node gets 12 and 20
    newNode->key[0] = full->key[3];
    newNode->key[1] = full->key[4];

    newNode->n = 2;

    // If full node has children
    if (full->child[0] != nullptr) {

        newNode->child[0] = full->child[3];
        newNode->child[1] = full->child[4];
        newNode->child[2] = full->child[5];

        full->child[3] = nullptr;
        full->child[4] = nullptr;
        full->child[5] = nullptr;
    }

    // Left node keeps first two keys
    full->n = 2;

    return newNode;
}


Node* InsertNotFull(Node* node, int x, int &middle)
{
    int i = node->n - 1;

    // Leaf node
  
    if (node->child[0] == nullptr) {

        while (i >= 0 && x < node->key[i]) {
            node->key[i + 1] = node->key[i];
            i--;
        }

        node->key[i + 1] = x;
        node->n++;
    }
    // Internal node
    

    else {

        while (i >= 0 && x < node->key[i])
            i--;

        i++;

        int childMiddle;

        // Insert into child
        Node *newNode =
            InsertNotFull(node->child[i], x, childMiddle);

        // If child was split
        if (newNode != nullptr) {

            // Shift keys in parent
            for (int j = node->n; j > i; j--) {
                node->key[j] = node->key[j - 1];
            }

            // Shift children in parent
            for (int j = node->n + 1; j > i + 1; j--) {
                node->child[j] = node->child[j - 1];
            }

            // Put middle key into parent
            node->key[i] = childMiddle;

            // Put new right node into parent
            node->child[i + 1] = newNode;

            node->n++;
        }
    }

    if (node->n > MAX) {
        return split(node, middle);
    }

    return nullptr;
}



Node* Insert(int x){

    if (root == NULL)
    {
        root = new Node();

        root->key[0] = x;
        root->n = 1;

        return root;
    }

    int middle;

    Node *newNode = InsertNotFull(root, x, middle);

    // Root was split
    if (newNode != nullptr)
    {
        Node *newRoot = new Node();

        newRoot->key[0] = middle;
        newRoot->n = 1;

        newRoot->child[0] = root;
        newRoot->child[1] = newNode;

        root = newRoot;
    }

    return root;
}


void display(Node* node)
{
    if (node == nullptr)
        return;

    cout << "[ ";

    for (int i = 0; i < node->n; i++)
    {
        cout << node->key[i] << " ";
    }

    cout << "]" << endl;

    if (node->child[0] != nullptr)
    {
        for (int i = 0; i <= node->n; i++)
        {
            display(node->child[i]);
        }
    }
}



int main() {

    Insert(10);
    Insert(20);
    Insert(5);
    Insert(6);
    Insert(12);
    Insert(30);
    Insert(7);
    Insert(17);
    Insert(23);

    cout << "Root keys: ";

    for (int i = 0; i < root->n; i++) {
        cout << root->key[i] << " ";
    }

    cout << endl;

    cout << "B-Tree:\n";

    display(root);

    return 0;
}