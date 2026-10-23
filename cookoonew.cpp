
#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

int hash1(int roll)
{
    return roll % SIZE;
}

int hash2(int roll)
{
    return (roll / SIZE) % SIZE;
}

void insert(int roll)
{
    int pos = hash1(roll);

    if (hashTable[pos] == -1)
        hashTable[pos] = roll;
    else
    {
        int temp = hashTable[pos];
        hashTable[pos] = roll;

        int pos2 = hash2(temp);

        if (hashTable[pos2] == -1)
            hashTable[pos2] = temp;
        else
            cout << "Cannot insert " << temp << endl;
    }
}

void search(int roll)
{
    if (hashTable[hash1(roll)] == roll ||
        hashTable[hash2(roll)] == roll)
        cout << roll << " is FOUND" << endl;
    else
        cout << roll << " is NOT FOUND" << endl;
}

void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << " : ";
        if (hashTable[i] == -1)
            cout << "-" << endl;
        else
            cout << hashTable[i] << endl;
    }
}

int main()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    insert(12);
    insert(22);
    insert(32);

    display();

    search(12);
    search(16);

    return 0;
}
