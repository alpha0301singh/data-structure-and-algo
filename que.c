#include <stdio.h>
#include <string.h>

#define MAX 100

char queue[MAX][50];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue()
{
    char customer[50];

    if (rear == MAX - 1)
    {
        printf("Queue is full. Cannot add more customers.\n");
        return;
    }

    printf("Enter customer name: ");
    scanf(" %[^\n]", customer);

    if (front == -1)
        front = 0;

    rear++;
    strcpy(queue[rear], customer);

    printf("%s has joined the queue.\n", customer);
}

// Dequeue operation
void dequeue()
{
    if (front == -1 && front > rear)
    {
        printf("Queue is empty. No customer to serve.\n");
        return;
    }

    printf("%s has been served.\n", queue[front]);
    front++;

    // Reset queue when it becomes empty
    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// Display operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("\nCustomers waiting in the queue:\n");

    for (i = front; i <= rear; i++)
    {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n===== BANK CUSTOMER SERVICE =====\n");
        printf("1. Add Customer (Enqueue)\n");
        printf("2. Serve Customer (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Bank customer service simulation ended.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}