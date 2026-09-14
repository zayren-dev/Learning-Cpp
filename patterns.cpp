#include <iostream>
using namespace std;

int main()
{
    int rows;

    
    cout << "Enter the total number of rows: ";
    cin >> rows;

    // Outer loop controls the rows
    for (int i = 1; i <= rows; i++)
    {
        // Inner loop prints the stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        
        cout << endl;
    }

    return 0;
}