#include <iostream>
using namespace std;


int noms[10];
int pore_digits[10]; 

int extractsumdigits(int number)
{
    int sum = 0;
    for (int i = number ; i > 0 ; i--)
    {
        sum = sum + number % 10;
        number = number / 10;
    }
    return sum;
}

void backsladhes()
{
    for (int i = 0; i < 56; i++)
    cout << '\\';
    cout << endl;
}

void numbers()
{
    cout << "Enter 10 non-negative integers:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter your " << i + 1 << " number: ";
        cin >> noms[i];
        pore_digits[i] = extractsumdigits(noms[i]); 
    }
}

void sequence()
{
    cout << "The Input Sequence is: ";
    
    for (int i = 0; i < 10; i++)
    cout << noms[i] << ", ";
    
    cout << endl;
}

int copairs()
{
    int pair = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (pore_digits[i] == pore_digits[j])
            {
                cout << "(" << noms[i] << ", " << noms[j] << ")" << endl;
                pair++;}
        }
    }
    return pair;
}

int main()
{
    backsladhes();
    cout << "        Welcome to Alice Secret Scroll Decipher" << endl;
    backsladhes();
    cout << endl;

    numbers();
    sequence();
    int totalPairs = copairs();
    cout << "Number of Special Pairs: " << totalPairs << endl;

    return 0;
}