
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

int bitArray[SIZE] = {0};

int hash1(string word)
{
    int sum = 0;

    for (int i = 0; i < word.length(); i++)
    {
        sum = sum + word[i];
    }

    return sum % SIZE;
}

int hash2(string word)
{
    int sum = 0;

    for (int i = 0; i < word.length(); i++)
    {
        sum = sum + word[i];
    }

    return (sum / SIZE + sum % SIZE) % SIZE;
}

void insert(string word)
{
    bitArray[hash1(word)] = 1;
    bitArray[hash2(word)] = 1;
}

void search(string word)
{
    if (bitArray[hash1(word)] == 1 &&
        bitArray[hash2(word)] == 1)
    {
        cout << "Word may exist in dictionary";
    }
    else
    {
        cout << "Word definitely does not exist in dictionary";
    }
}

int main()
{
    
    insert("apple");
    insert("book");
    insert("cat");

    string word;

    cout << "Enter word to search: ";
    cin >> word;

    search(word);

    return 0;
}
