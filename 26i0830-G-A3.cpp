#include <iostream>
using namespace std;
// question 1 ka function
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

// ques 3 k chote functions jo use hute hein os mein
void q3PrintSymbol(int distance)
{
    int turn = distance % 4;
    if (turn == 0)
        cout << "*";
    else if (turn == 1)
        cout << "-";
    else if (turn == 2)
        cout << "o";
    else
        cout << ".";
}
void q3PrintRow(int n, int gap)
{
   
    for (int space = 0; space < gap; space++)
        cout << " ";

    for (int distance = n - 1; distance >= gap; distance--)
        q3PrintSymbol(distance);

    for (int distance = gap + 1; distance <= n - 1; distance++)
        q3PrintSymbol(distance);

    cout << endl;
}
// ques 3 ka asal  function jo neche direct call huga
void question3()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    for ( ; n <= 2 || n % 2 == 0; )
    {
        cout << "Invalid input! n must be an odd number greater than 2." << endl;
        cout << "Enter n: ";
        cin >> n;
    }

    for (int gap = n - 1; gap >= 0; gap--)
        q3PrintRow(n, gap);

    for (int gap = 1; gap <= n - 1; gap++)
        q3PrintRow(n, gap);
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

    case 3:
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