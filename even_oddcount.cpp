#include <iostream>
using namespace std;

// idher yeh function khod array banaye ga phir even odd mein ginay ga
void countevenodd(int choice)
{
    int number[10];
    int totaleven_num = 0;
    int totalodd_num = 0;
    cout << "Enter 10 integers:" << endl;

    // pehly array mein daal do
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter your " << i + 1 << " number: ";
        cin >> number[i];}

    // ab array ko dobara parh kr even odd check krte hein 
    for (int i = 0; i < 10; i++)
    {
        if (number[i] % 2 == 0)
        totaleven_num++;
        else
        totalodd_num++;}

    switch (choice)
    {
    case 1:
        cout << "Even Numbers: " << totaleven_num << endl;
        break;
    case 2:
        cout << "Odd Numbers: " << totalodd_num << endl;
        break;
    }}

int main()
{
    int choice;

    cout << "What would you like to count?" << endl;
    cout << "1. Even Numbers" << endl;
    cout << "2. Odd Numbers" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    countevenodd(choice);

    return 0;}





