#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    int jobID;
    int priority;
    int degree;

    Node *parent;
    Node *child;
    Node *left;
    Node *right;

    Node(int id, int p) {
        jobID = id;
        priority = p;
        degree = 0;

        parent = nullptr;
        child = nullptr;

        left = this;
        right = this;
    }
};

Node *minNode = nullptr;

int jobIDs[MAX];
int priorities[MAX];
int count = 0;


// ------------------------------------------------
// INSERT
// ------------------------------------------------

void insert(int id, int p) {

    // Store insertion order
    jobIDs[count] = id;
    priorities[count] = p;
    count++;

    Node *newNode = new Node(id, p);

    if (minNode == nullptr) {

        minNode = newNode;
    }
    else {

        newNode->right = minNode->right;
        newNode->left = minNode;

        minNode->right->left = newNode;
        minNode->right = newNode;

        if (newNode->priority < minNode->priority)
            minNode = newNode;
    }
}


// ------------------------------------------------
// DISPLAY
// ------------------------------------------------

void display() {

    if (minNode == nullptr) {
        cout << "Priority Queue is empty\n";
        return;
    }

    cout << "Insertion order:\n";

    for (int i = 0; i < count; i++) {

        cout << "Job " << jobIDs[i]
             << "  Priority = " << priorities[i] << endl;
    }

    cout << "Highest Priority Job = Job "
         << minNode->jobID
         << "  Priority = "
         << minNode->priority << endl;
}


// ------------------------------------------------
// GET MINIMUM
// ------------------------------------------------

void getMin() {

    if (minNode == nullptr) {
        cout << "Priority Queue is empty\n";
        return;
    }

    cout << "Next Job = Job "
         << minNode->jobID
         << "  Priority = "
         << minNode->priority << endl;
}


// ------------------------------------------------
// REMOVE NODE FROM LIST
// ------------------------------------------------

void removeNode(Node *x) {

    x->left->right = x->right;
    x->right->left = x->left;
}


// ------------------------------------------------
// ADD CHILD TO ROOT LIST
// ------------------------------------------------

void addToRoot(Node *x) {

    x->parent = nullptr;

    x->left = minNode;
    x->right = minNode->right;

    minNode->right->left = x;
    minNode->right = x;
}


// ------------------------------------------------
// EXTRACT MINIMUM
// ------------------------------------------------

void extractMin() {

    if (minNode == nullptr) {
        cout << "Priority Queue is empty\n";
        return;
    }

    Node *temp = minNode;

    cout << "Processing Job "
         << temp->jobID
         << " with Priority "
         << temp->priority << endl;


    // Add all children to root list

    if (temp->child != nullptr) {

        Node *child = temp->child;
        Node *start = child;

        do {

            Node *next = child->right;

            addToRoot(child);

            child = next;

        } while (child != start);
    }


    // Remove minimum node

    if (temp->right == temp) {

        minNode = nullptr;
    }
    else {

        minNode = temp->right;

        removeNode(temp);
    }


    // Remove job from insertion order

    for (int i = 0; i < count; i++) {

        if (jobIDs[i] == temp->jobID) {

            for (int j = i; j < count - 1; j++) {

                jobIDs[j] = jobIDs[j + 1];
                priorities[j] = priorities[j + 1];
            }

            count--;
            break;
        }
    }

    delete temp;
}


// ------------------------------------------------
// MAIN
// ------------------------------------------------

int main() {

    insert(101, 3);
    insert(102, 1);
    insert(103, 5);
    insert(104, 2);
    insert(105, 4);

    cout << "After insertion:\n";
    display();

    cout << "\n";

    cout << "Get Highest Priority Job:\n";
    getMin();

    cout << "\n";

    cout << "After Processing Highest Priority Job:\n";
    extractMin();
    display();

    cout << "\n";

    cout << "After Processing Highest Priority Job:\n";
    extractMin();
    display();

    return 0;
}