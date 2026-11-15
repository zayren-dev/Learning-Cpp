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

    int daystart = 1;

    for (int y = 1; y < year; y++)
    {
        daystart++;
        if (q2isleap(y))
            daystart++;
    }

    for (int m = 1; m < month; m++)
        daystart = daystart + q2daysinmonth(m, year);
 
    daystart = daystart % 7;  

    
    int weekscount;
    if (month == 1)
        weekscount = 7;
    else if (month == 2)
        weekscount = 8;
    else if (month == 3)
        weekscount = 5;
    else if (month == 4)
        weekscount = 5;
    else if (month == 5)
        weekscount = 3;
    else if (month == 6)
        weekscount = 4;
    else if (month == 7)
        weekscount = 4;
    else if (month == 8)
        weekscount = 6;
    else if (month == 9)
        weekscount = 9;
    else if (month == 10)
        weekscount = 7;
    else if (month == 11)
        weekscount = 8;
    else
        weekscount = 8;

    int h7length = weekscount + 1;
    for (int rest = year; rest > 0; rest = rest / 10)
        h7length++;

    cout << endl << endl;
    for (int i = 0; i < (20 - h7length) / 2; i++)
        cout << " ";

    if (month == 1) cout << "January";
    else if (month == 2) cout << "February";
    else if (month == 3) cout << "March";
    else if (month == 4) cout << "April";
    else if (month == 5) cout << "May";
    else if (month == 6) cout << "June";
    else if (month == 7) cout << "July";
    else if (month == 8) cout << "August";
    else if (month == 9) cout << "September";
    else if (month == 10) cout << "October";
    else if (month == 11)  cout << "November";
    else cout << "December";

    cout << " " << year << endl;
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    int totalBoxes = daystart + q2daysinmonth(month, year);
    for (int box = 0; box < totalBoxes; box++)
    {
        int column = box % 7;         
        if (column != 0)
            cout << " ";

        if (box < daystart)
            cout << "  ";             
        else
        {
            int date = box - daystart + 1;
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
// ques 5 ky liye global variables or oske functions jo wo use kry ga
long long mazeNumber0 = 0, mazeNumber1 = 0, mazeNumber2 = 0, mazeNumber3 = 0, 
mazeNumber4 = 0, mazeNumber5 = 0;

long long q5TenPower(int times)
{
    long long answer = 1;
    for (int i = 1; i <= times; i++)
        answer = answer * 10;
    return answer;
}

int q5ReadBox(int boxNumber)
{
    int whichNumber = boxNumber / 18;     
    int position = boxNumber % 18;     

    long long mazeNumber;
    if (whichNumber == 0)
        mazeNumber = mazeNumber0;
    else if (whichNumber == 1)
        mazeNumber = mazeNumber1;
    else if (whichNumber == 2)
        mazeNumber = mazeNumber2;
    else if (whichNumber == 3)
        mazeNumber = mazeNumber3;
    else if (whichNumber == 4)
        mazeNumber = mazeNumber4;
    else
        mazeNumber = mazeNumber5;

    return (mazeNumber / q5TenPower(position)) % 10;
}
void q5WriteBox(int boxNumber, int newValue)
{
    int whichNumber = boxNumber / 18;
    int position = boxNumber % 18;
    long long difference = (newValue - q5ReadBox(boxNumber)) * q5TenPower(position);

    if (whichNumber == 0)
        mazeNumber0 = mazeNumber0 + difference;
    else if (whichNumber == 1)
        mazeNumber1 = mazeNumber1 + difference;
    else if (whichNumber == 2)
        mazeNumber2 = mazeNumber2 + difference;
    else if (whichNumber == 3)
        mazeNumber3 = mazeNumber3 + difference;
    else if (whichNumber == 4)
        mazeNumber4 = mazeNumber4 + difference;
    else
        mazeNumber5 = mazeNumber5 + difference;
}

int q5TryToReach(int boxNumber)
{
    int boxValue = q5ReadBox(boxNumber);
    if (boxValue == 1 || boxValue >= 5)
        return 0;                          
    q5WriteBox(boxNumber, boxValue + 5);
    return 1;
}
// ques 5 ka asal code
void question5()
{
    mazeNumber0 = mazeNumber1 = mazeNumber2 = mazeNumber3 = mazeNumber4 = mazeNumber5 = 0; 

    int n;
    cin >> n;
    int totalBoxes = n * n;

    for (int boxNumber = 0; boxNumber < totalBoxes; boxNumber++)
    {
        char symbol;
        cin >> symbol;
        if (symbol == '*')
            q5WriteBox(boxNumber, 1);
        else if (symbol == 'G')
            q5WriteBox(boxNumber, 2);
        else if (symbol == 'E')
            q5WriteBox(boxNumber, 3);
        else if (symbol == 'S')
            q5WriteBox(boxNumber, 5);      
        
    }

   
    int foundNewBox = 1;
    while (foundNewBox == 1)
    {
        foundNewBox = 0;
        for (int boxNumber = 0; boxNumber < totalBoxes; boxNumber++)
        {
            if (q5ReadBox(boxNumber) >= 5)  
            {
                int row = boxNumber / n;
                int column = boxNumber % n;
                if (row > 0 && q5TryToReach(boxNumber - n) == 1)
                    foundNewBox = 1;         // upar wala dabba
                if (row < n - 1 && q5TryToReach(boxNumber + n) == 1)
                    foundNewBox = 1;         // neeche wala dabba
                if (column > 0 && q5TryToReach(boxNumber - 1) == 1)
                    foundNewBox = 1;         // left wala dabba
                if (column < n - 1 && q5TryToReach(boxNumber + 1) == 1)
                    foundNewBox = 1;         // right wala dabba
            }
        }
    }

    int goldCount = 0;
    int exitReached = 0;
    for (int boxNumber = 0; boxNumber < totalBoxes; boxNumber++)
    {
        int boxValue = q5ReadBox(boxNumber);
        if (boxValue == 7)
            goldCount++;
        if (boxValue == 8)
            exitReached = 1;
    }

    if (exitReached == 1)
        cout << "Solvable: YES" << endl;
    else
        cout << "Solvable: NO" << endl;
    cout << "Gold reachable: " << goldCount << endl;
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

    case 2:
        question2();
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