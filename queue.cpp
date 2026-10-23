#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int queue[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Add customer to queue
    void enqueue(int customer) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1)
                front = 0;

            rear++;
            queue[rear] = customer;
            cout << "Customer " << customer << " joined the queue." << endl;
        }
    }

    // Serve customer
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "No customers in the queue." << endl;
        } else {
            cout << "Customer " << queue[front]
                 << " is being served." << endl;
            front++;
        }
    }

    // Display customers
    void display() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Customers waiting: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, customer;

    do {
        cout << "\n--- Bank Customer Service ---\n";
        cout << "1. Add Customer\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter customer number: ";
            cin >> customer;
            q.enqueue(customer);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Thank you!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}