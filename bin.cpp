#include<iostream>
using namespace std;
 
struct Node {
    int bookId;
    Node *Left;
    Node *Right;
};
Node* create(int ID){
    Node *newNode = new Node;
    newNode->bookId = ID;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    return newNode;
}

Node*insert(Node *root, int ID) {
    if (root == nullptr) {
        return create(ID);
    }

    if (ID < root->bookId) {
        root->Left = insert(root->Left, ID);
    } 
    else if (ID > root->bookId) {
        root->Right = insert(root->Right, ID);
    }

    return root;
}

Node* search(Node *root, int ID) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->bookId == ID) {
        return root;
    }

    if (ID < root->bookId) {
        return search(root->Left, ID);
    }

    return search(root->Right, ID);
}

Node* InOrder(Node *root) {
    if (root == nullptr) {
        return root;
    }

    InOrder(root->Left);
    cout << root->bookId << " ";
    InOrder(root->Right);

    return root;
}
int main() {
    Node *root = nullptr;
    cout << "Enter the number of books to insert: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int bookId;
        cout << "Enter book ID " << (i + 1) << ": ";
        cin >> bookId;
        root = insert(root, bookId);
    }
    cout << "InOrder Traversal:";
    InOrder(root);
    cout <<endl;
    
    cout << "Enter the book ID to search for: ";
    int searchID;
    cin >> searchID;

    Node *result = search(root, searchID);
    if (result != nullptr) {
        cout << "Book ID " << searchID << " found in the BST." << endl;
    } else {
        cout << "Book ID " << searchID << " not found in the BST." << endl;
    }

    return 0;
}







