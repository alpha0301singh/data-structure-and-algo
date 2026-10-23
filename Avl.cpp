#include <iostream>
using namespace std;

struct Node {
    int data;
    
    Node *Left;
    Node *Right;
};

Node* create(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    return newNode;
} 


int height(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = height(node->Left);
    int rightHeight = height(node->Right);
    return max(leftHeight, rightHeight) + 1;
 }

int getBalance(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return height(node->Left) - height(node->Right);
}

Node* rightRotate(Node *y) {
    Node *x = y->Left;
    Node *T2 = x->Right;

    x->Right = y;
    y->Left = T2;

    return x; 
}

Node* leftRotate(Node *x) {
    Node *y = x->Right;
    Node *T2 = y->Left;

    y->Left = x;
    x->Right = T2;

    return y; 
}

Node* insert(Node *root, int data) {
    if (root == nullptr) {
        return create(data);
    }

    if (data < root->data) {
        root->Left = insert(root->Left, data);
    } 
    else if (data > root->data) {
        root->Right = insert(root->Right, data);
    }

    int balance = getBalance(root);

   
    if (balance > 1 && data < root->Left->data) {
        return rightRotate(root);
    }

    
    if (balance < -1 && data > root->Right->data) {
        return leftRotate(root);
    }


    if (balance > 1 && data > root->Left->data) {
        root->Left = leftRotate(root->Left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->Right->data) {
        root->Right = rightRotate(root->Right);
        return leftRotate(root);
    }

    return root;
}

Node* search(Node *root, int data) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->Left, data);
    }

    return search(root->Right, data);
}


Node*InOrder(Node *root) {
    if (root == nullptr) {
        return root;
    }

    InOrder(root->Left);
    cout << root->data << " ";
    InOrder(root->Right);

    return root;
}


int main() {
    Node *root = nullptr;
    cout << "Enter the number of students to insert: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        cout << "Enter student data " << (i + 1) << ": ";
        cin >> data;
        root = insert(root, data);
    }
     cout << "Enter the student data to search for: ";
    int searchData;
    cin >> searchData;

    Node *result = search(root, searchData);
    if (result != nullptr) {
        cout << "Book ID " << searchData << " found in the AVL." << endl;
    } 
    else {
        cout << "Book ID " << searchData << " not found in the AVL." << endl;
    }
 

    cout << "InOrder Traversal: ";
    InOrder(root);
    cout << endl;
}

