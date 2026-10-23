#include <iostream>
using namespace std;

const int MAX = 3;   // Maximum 3 keys in one node

struct Node
{
    int key[MAX];
    Node* child[MAX + 1];
    int n;

    Node()
    {
        n = 0;

        for (int i = 0; i < MAX + 1; i++)
        {
            child[i] = nullptr;
        }
    }
};

Node* root = nullptr;


// --------------------------------------------------
// DISPLAY B-TREE
// --------------------------------------------------
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

    // If node is not a leaf
    if (node->child[0] != nullptr)
    {
        for (int i = 0; i <= node->n; i++)
        {
            display(node->child[i]);
        }
    }
}


// --------------------------------------------------
// SPLIT CHILD
// --------------------------------------------------
void split(Node* parent, int pos)
{
    Node* full = parent->child[pos];

    Node* newNode = new Node();

    // Middle key moves to parent
    int middle = full->key[1];

    // Right node gets key[2]
    newNode->key[0] = full->key[2];
    newNode->n = 1;

    // If full node has children
    if (full->child[0] != nullptr)
    {
        newNode->child[0] = full->child[2];
        newNode->child[1] = full->child[3];

        full->child[2] = nullptr;
        full->child[3] = nullptr;
    }

    // Left node keeps only key[0]
    full->n = 1;


    // Make space in parent for new key
    for (int i = parent->n; i > pos; i--)
    {
        parent->key[i] = parent->key[i - 1];
    }

    // Make space for new child
    for (int i = parent->n + 1; i > pos + 1; i--)
    {
        parent->child[i] = parent->child[i - 1];
    }


    // Insert middle key into parent
    parent->key[pos] = middle;

    // Insert new right child
    parent->child[pos + 1] = newNode;

    parent->n++;
}


// --------------------------------------------------
// INSERT INTO NON-FULL NODE
// --------------------------------------------------
void InsertNotFull(Node* node, int x)
{
    int i = node->n - 1;

    // ----------------------------------------------
    // CASE 1: Node is a leaf
    // ----------------------------------------------
    if (node->child[0] == nullptr)
    {
        // Shift larger keys to right
        while (i >= 0 && x < node->key[i])
        {
            node->key[i + 1] = node->key[i];
            i--;
        }

        // Insert x
        node->key[i + 1] = x;

        node->n++;
    }

    // ----------------------------------------------
    // CASE 2: Node is an internal node
    // ----------------------------------------------
    else
    {
        // Find correct child
        while (i >= 0 && x < node->key[i])
        {
            i--;
        }

        i++;


        // If child is full
        if (node->child[i]->n == MAX)
        {
            // Split the child
            split(node, i);

            // Decide whether x goes to left or right child
            if (x > node->key[i])
            {
                i++;
            }
        }

        // Insert into selected child
        InsertNotFull(node->child[i], x);
    }
}


// --------------------------------------------------
// INSERT
// --------------------------------------------------
void Insert(int x)
{
    // ----------------------------------------------
    // CASE 1: Tree is empty
    // ----------------------------------------------
    if (root == nullptr)
    {
        root = new Node();

        root->key[0] = x;
        root->n = 1;

        return;
    }


    // ----------------------------------------------
    // CASE 2: Root is full
    // ----------------------------------------------
    if (root->n == MAX)
    {
        Node* newRoot = new Node();

        // Old root becomes child of new root
        newRoot->child[0] = root;

        // Split old root
        split(newRoot, 0);

        // New root becomes actual root
        root = newRoot;
    }


    // Insert into non-full root
    InsertNotFull(root, x);
}


// --------------------------------------------------
// MAIN
// --------------------------------------------------
int main()
{
    Insert(10);
    Insert(20);
    Insert(5);
    Insert(6);
    Insert(12);
    Insert(30);
    Insert(7);
    Insert(17);

    cout << "Root keys: ";

    for (int i = 0; i < root->n; i++)
    {
        cout << root->key[i] << " ";
    }

    cout << endl;

    cout << "\nB-Tree:\n";

    display(root);

    return 0;
}