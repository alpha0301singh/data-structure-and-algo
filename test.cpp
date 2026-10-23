# include<iostream>
using namespace std;

#define MAX 5 
int stack [MAX];
int top = -1;

void push(int booking) {
    if (top == MAX - 1) {
        cout << "Stack Overflow" ;
        return;
    }
    top++;
    stack[top] = booking;
}
void pop()
{
    if (top == -1)
        cout << "No booking to cancel";
    else
    {
        cout << "Booking cancelled: " << stack[top] ;
        top--;
    }
}

void display()
{
    if (top == -1)
        cout << "No bookings available!";
    else
    {
        cout << "Bookings: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] ;
        cout << endl;
    }
}

int main()
{

    cout<<  "enter the number of booking you want to make :";
    int n ;
    cin>> n;
    for (int i = 0; i < n; i++) {
        int booking;
        cout << "Enter booking number: ";
        cin >> booking;
        push(booking);
    }

    cout<< " the booking you want to cancel :";
    int cancel;
    cin >> cancel;
    pop();


    display();
}




