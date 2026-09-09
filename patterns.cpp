#include <iostream>
using namespace std;

int main()
{
    int rows;

    // Ask the user how many rows they want
    cout << "Enter the number of rows: ";
    cin >> rows;

    // Outer loop controls the rows
    for (int i = 1; i <= rows; i++)
    {
        // Inner loop prints the stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Move to the next line after printing one row
        cout << endl;
    }

    return 0;
}