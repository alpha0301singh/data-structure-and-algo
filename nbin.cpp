#include<iostream>
using namespace std;
 
struct Node {
    int bookId;
    Node *Left;
    Node *Right;
};
Node* create(int value){
    Node *newNode = new Node;
    newNode->bookId = value;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    return newNode;
}

Node*insert(Node *root, int value) {
    if (root == nullptr) {
        return create(value);
    }

    if (value < root->bookId) {
        root->Left = insert(root->Left, value);
    } 
    else if (value > root->bookId) {
        root->Right = insert(root->Right, value);
    }

    return root;
}

Node* search(Node *root, int value) {
    if (root == nullptr || root->bookId == value) {
        return root;
    }

    if (value < root->bookId) {
        return search(root->Left, value);
    }

    return search(root->Right, value);
}
int main() {
    Node *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);

    int searchValue = 5;
    Node *result = search(root, searchValue);
    if (result != nullptr) {
        cout << "Book ID " << searchValue << " found in the BST." << endl;
    } else {
        cout << "Book ID " << searchValue << " not found in the BST." << endl;
    }

    return 0;
}







