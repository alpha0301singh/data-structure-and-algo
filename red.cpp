#include <iostream>
using namespace std;

struct Node {
    int data;
    char color;       
    Node *Left, *Right, *parent;
};

Node* create(int data) {
    Node* newNode = new Node;

    newNode->data = data;
    newNode->color = 'R';   
    newNode->Left = NULL;
    newNode->Right = NULL;
    newNode->parent = NULL;

    return newNode;
} 


Node *insert(Node *root, int data) {

    Node *newNode = create(data);

    Node *parent = NULL;
    Node *current = root;
    
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->Left;
        } else {
            current = current->Right;
        }
    }

    newNode->parent = parent;

    if(parent == NULL) {
        root = newNode;
    } else if (data < parent->data) {
        parent->Left = newNode;
    } else {
        parent->Right = newNode;
    }

    Fixinsertion(root, newNode);

}








Node *RightRotate(Node* &root, Node* y)
{
    Node* x = y->Left;
    Node* T2 = x->Right;

    y->Left = T2;

    if (T2 != NULL)
        T2->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        root = x;
    else if (y == y->parent->Left)
        y->parent->Left = x;
    else
        y->parent->Right = x;

    x->Right = y;
    y->parent = x;
}

Node *LeftRotate(Node* &root, Node* x)
{
    Node* y = x->Right;
    Node* T2 = y->Left;

    y->Left = x;

    if (T2 != NULL)
        T2->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->Left)
        x->parent->Left = y;
    else
        x->parent->Right = y;

    x->Right = T2;
    x->parent = y;
}


Node * Fixinsertion(Node* root, Node* node) {
    
    Node *parent = NULL;
    Node *grandparent = NULL;

    while ((node != root) && (node->color == 'R') && (node->parent->color == 'R')) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->Left) {
            Node *uncle = grandparent->Right;

            if (uncle != NULL && uncle->color == 'R') {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                node = grandparent;
            } else {
                if (node == parent->Right) {
                    LeftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                RightRotate(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        } 
        else {
            Node *uncle = grandparent->Left;

            if ((uncle != NULL) && (uncle->color == 'R')) {
                grandparent->color = 'R';
                parent->color = 'B';
                uncle->color = 'B';
                node = grandparent;
            } 
            else {
                if (node == parent->Left) {
                    RightRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                parent->color = 'B';
                grandparent->color = 'R';
                LeftRotate(root, grandparent);   
            }
        }
    }
    root->color = 'B';
    return root;
}
