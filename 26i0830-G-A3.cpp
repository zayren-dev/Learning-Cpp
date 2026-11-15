#include <iostream>
using namespace std;

void question1()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    while (n <= 2 || n % 2 == 0)
    {
        cout << "Invalid input! n must be an odd number greater than 2." << endl;
        cout << "Enter n: ";
        cin >> n;
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
        
            int layer = 0;
            while (row != layer && row != n - 1 - layer && col != layer && col != n - 1 - layer)
                  layer++;
            
            cout << (layer + 1) % 10;

            if (col < n - 1) cout << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    cout << "Enter question number (0 to exit): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        question1();
        break;
    case 0:
        cout << "Exiting program..." << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
    return 0;
}