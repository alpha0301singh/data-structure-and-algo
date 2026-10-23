#include <iostream>
#include <algorithm>
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
    return std::max(leftHeight, rightHeight) + 1;
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

    // Perform rotation
    x->Right = y;
    y->Left = T2;

    return x; // Return new root
}

Node* leftRotate(Node *x) {
    Node *y = x->Right;
    Node *T2 = y->Left;

    // Perform rotation
    y->Left = x;
    x->Right = T2;

    return y; // Return new root
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

    // Update the balance factor and perform rotations if necessary
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->Left->data) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && data > root->Right->data) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && data > root->Left->data) {
        root->Left = leftRotate(root->Left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && data < root->Right->data) {
        root->Right = rightRotate(root->Right);
        return leftRotate(root);
    }

    return root;
}


Node* Delete(Node *root, int data) {
    if (root == nullptr) {
        return root;
    }

    if (data < root->data) {
        root->Left = Delete(root->Left, data);
    } 
    else if (data > root->data) {
        root->Right = Delete(root->Right, data);
    } 
    else {
        // Node with only one child or no child
        if (root->Left == nullptr) {
            Node *temp = root->Right;
            delete root;
            return temp;
        } 
        else if (root->Right == nullptr) {
            Node *temp = root->Left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = root->Right;
        while (temp && temp->Left != nullptr) {
            temp = temp->Left;
        }

        // Copy the inorder successor's data to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->Right = Delete(root->Right, temp->data);
    }

    // Update the balance factor and perform rotations if necessary
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->Left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->Left) < 0) {
        root->Left = leftRotate(root->Left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->Right) <= 0) {
        return leftRotate(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->Right) > 0) {
        root->Right = rightRotate(root->Right);
        return leftRotate(root);
    }

    return root;
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
    cout << "Enter the number of Customer to insert: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int data;
        cout << "Enter Customer data " << (i + 1) << ": ";
        cin >> data;
        root = insert(root, data);
    }
    cout << "Enter the Customer to delete: ";
    int deleteID;
    cin >> deleteID;
    root = Delete(root, deleteID);


    cout << "InOrder Traversal: ";
    InOrder(root);
    cout << endl;
}

