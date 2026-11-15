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

// ques 2 ky chote mote functions jo use hute ho
bool q2isleap(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
int q2daysinmonth(int month, int year)
{
    if (month == 2)
    {
        if (q2isleap(year))
            return 29;
        return 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    return 31;
}
// question 2 ka asal func jo call huna h neche main mein
void question2()
{
    int year, month;

    cout << "Year::: ";
    cin >> year;
    while (year < 1 || year > 9999)
    {
        cout << "Year should be between 1 and 9999." << endl;
        cout << "Year::: ";
        cin >> year;
    }

    cout << "Month::: ";
    cin >> month;
    while (month < 1 || month > 12)
    {
        cout << "Month should be between 1 and 12." << endl;
        cout << "Month::: ";
        cin >> month;
    }

    int startDay = 1;

    for (int y = 1; y < year; y++)
    {
        startDay++;
        if (q2isleap(y))
            startDay++;
    }

    for (int m = 1; m < month; m++)
        startDay = startDay + q2daysinmonth(m, year);

    startDay = startDay % 7;  

    
    int nameLength;
    if (month == 1)
        nameLength = 7;
    else if (month == 2)
        nameLength = 8;
    else if (month == 3)
        nameLength = 5;
    else if (month == 4)
        nameLength = 5;
    else if (month == 5)
        nameLength = 3;
    else if (month == 6)
        nameLength = 4;
    else if (month == 7)
        nameLength = 4;
    else if (month == 8)
        nameLength = 6;
    else if (month == 9)
        nameLength = 9;
    else if (month == 10)
        nameLength = 7;
    else if (month == 11)
        nameLength = 8;
    else
        nameLength = 8;

    int titleLength = nameLength + 1;
    for (int rest = year; rest > 0; rest = rest / 10)
        titleLength++;

    cout << endl << endl;
    for (int i = 0; i < (20 - titleLength) / 2; i++)
        cout << " ";

    if (month == 1)
        cout << "January";
    else if (month == 2)
        cout << "February";
    else if (month == 3)
        cout << "March";
    else if (month == 4)
        cout << "April";
    else if (month == 5)
        cout << "May";
    else if (month == 6)
        cout << "June";
    else if (month == 7)
        cout << "July";
    else if (month == 8)
        cout << "August";
    else if (month == 9)
        cout << "September";
    else if (month == 10)
        cout << "October";
    else if (month == 11)
        cout << "November";
    else
        cout << "December";

    cout << " " << year << endl;
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    int totalBoxes = startDay + q2daysinmonth(month, year);
    for (int box = 0; box < totalBoxes; box++)
    {
        int column = box % 7;         
        if (column != 0)
            cout << " ";

        if (box < startDay)
            cout << "  ";             
        else
        {
            int date = box - startDay + 1;
            if (date < 10)
                cout << " ";         
            cout << date;
        }

        if (column == 6)
            cout << endl;             
    }
    if (totalBoxes % 7 != 0)
        cout << endl;                 
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
        question3();
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