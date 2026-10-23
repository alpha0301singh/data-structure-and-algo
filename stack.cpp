#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

// Push booking
void push(int bookingID)
{
    if (top == SIZE - 1)
        cout << "Stack is full!\n";
    else
    {
        top++;
        stack[top] = bookingID;
        cout << "Booking added.\n";
    }
}

// Pop booking
void pop()
{
    if (top == -1)
        cout << "No booking to cancel!\n";
    else
    {
        cout << "Booking cancelled: " << stack[top] << endl;
        top--;
    }
}

// Display bookings
void display()
{
    if (top == -1)
        cout << "No bookings available!\n";
    else
    {
        cout << "Bookings: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}

int main()
{
    int n, bookingID;

    cout << "Enter number of bookings: ";
    cin >> n;

    cout << "Enter booking IDs:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> bookingID;
        push(bookingID);
    }

    display();

    cout << "\nEnter number of bookings to cancel: ";
    cin >> n;

    for (int i = 0; i < n; i++)
        pop();

    cout << "\nAfter cancellation:\n";
    display();

    return 0;
}