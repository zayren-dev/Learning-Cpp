#include <iostream>
using namespace std;

int main()
{
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    // Pattern 1:
    // 111
    // 222
    // 333
    cout << "\nPattern 1:\n";

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows; j++)
        {
            cout << i;
        }

        cout << endl;
    }


    // Pattern 2:
    // 1
    // 12
    // 123
    // 1234
    cout << "\nPattern 2:\n";

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        cout << endl;
    }


    // Pattern 3:
    // 1
    // 22
    // 333
    // 4444
    cout << "\nPattern 3:\n";

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }

        cout << endl;
    }

    return 0;
}