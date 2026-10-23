#include <iostream>
using namespace std;

struct Node
{
    int bookId;
    Node *Left;
    Node *Right;
};

// Create a new node
Node* create(int ID)
{
    Node *newNode = new Node;

    newNode->bookId = ID;
    newNode->Left = nullptr;
    newNode->Right = nullptr;

    return newNode;
}

// Insert a book ID into BST
Node* insert(Node *root, int ID)
{
    if (root == nullptr)
    {
        return create(ID);
    }

    if (ID < root->bookId)
    {
        root->Left = insert(root->Left, ID);
    }
    else if (ID > root->bookId)
    {
        root->Right = insert(root->Right, ID);
    }

    return root;
}

// Find maximum node in a subtree
Node* Maximum(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    // Move to the right until the last node
    while (root->Right != nullptr)
    {
        root = root->Right;
    }

    return root;
}

// Delete a book ID from BST
Node* Delete(Node *root, int ID)
{
    if (root == nullptr)
    {
        return root;
    }

    // Search in left subtree
    if (ID < root->bookId)
    {
        root->Left = Delete(root->Left, ID);
    }

    // Search in right subtree
    else if (ID > root->bookId)
    {
        root->Right = Delete(root->Right, ID);
    }

    // Node found
    else
    {
        // Case 1: No left child
        if (root->Left == nullptr)
        {
            Node *temp = root->Right;
            delete root;
            return temp;
        }

        // Case 2: No right child
        else if (root->Right == nullptr)
        {
            Node *temp = root->Left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node *temp = Maximum(root->Left);

        // Copy predecessor value
        root->bookId = temp->bookId;

        // Delete predecessor
        root->Left = Delete(root->Left, temp->bookId);
    }

    return root;
}

// InOrder: Left -> Root -> Right
void InOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrder(root->Left);
    cout << root->bookId << " ";
    InOrder(root->Right);
}

// PreOrder: Root -> Left -> Right
void PreOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->bookId << " ";
    PreOrder(root->Left);
    PreOrder(root->Right);
}

// PostOrder: Left -> Right -> Root
void PostOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    PostOrder(root->Left);
    PostOrder(root->Right);
    cout << root->bookId << " ";
}

int main()
{
    Node *root = nullptr;

    // Number of books
    int n;

    cout << "Enter the number of books to insert: ";
    cin >> n;

    // Insert book IDs
    for (int i = 0; i < n; i++)
    {
        int bookId;

        cout << "Enter book ID " << i + 1 << ": ";
        cin >> bookId;

        root = insert(root, bookId);
    }

    // Display traversals
    cout << "\nInOrder Traversal: ";
    InOrder(root);
    cout << endl;

    cout << "PreOrder Traversal: ";
    PreOrder(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    PostOrder(root);
    cout << endl;

    // Delete a book
    int deleteID;

    cout << "\nEnter the book ID to delete: ";
    cin >> deleteID;

    root = Delete(root, deleteID);

    // Display tree after deletion
    cout << "InOrder Traversal after deletion: ";
    InOrder(root);
    cout << endl;

    cout << "PreOrder Traversal after deletion: ";
    PreOrder(root);
    cout << endl;

    cout << "PostOrder Traversal after deletion: ";
    PostOrder(root);
    cout << endl;

    return 0;
}