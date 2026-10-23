#include <stdio.h>
#include <string.h>


# define MAX 100

char queue[MAX][50];
int front = -1;
int rear = -1;
void enqueue ()
{
    char customer[40];
     if (rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    printf("Enter customer name: ");
    scanf("%s", customer);
    strcpy(queue[rear], customer);
}

void dequeue ()
{
    if (front == -1 )
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Customer has been served and removed from the queue\n", queue[front]);
    front++;
}

