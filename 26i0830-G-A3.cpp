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
void q3printsymbol(int distance)
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
void q3printrow(int n, int gap)
{
   
    for (int space = 0; space < gap; space++)
        cout << " ";

    for (int distance = n - 1; distance >= gap; distance--)
        q3printsymbol(distance);

    for (int distance = gap + 1; distance <= n - 1; distance++)
        q3printsymbol(distance);

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
        q3printrow(n, gap);

    for (int gap = 1; gap <= n - 1; gap++)
        q3printrow(n, gap);
}
// ques 4 k help wale functions
int jumpOf(int ring, int base)
{
    int last = 0;
    int beforeLast = 0;

    for (int step = 1; step <= ring; step++)
    {
        int next = (last + beforeLast + 1) % base;
        beforeLast = last;
        last = next;
    }
    return last;
}
// ques 4 ka asal function
void question4()
{
    int n, base, seed;

    cout << "N: ";
    cin >> n;
    while (n < 1)
    {
        cout << "N must be 1 or more." << endl;
        cout << "N: ";
        cin >> n;
    }

    cout << "Base: ";
    cin >> base;
    while (base < 2 || base > 16)
    {
        cout << "Base must be between 2 and 16." << endl;
        cout << "Base: ";
        cin >> base;
    }

    cout << "Seed: ";
    cin >> seed;
    cout << endl;

    seed = seed % base;
    if (seed < 0)
        seed = seed + base;

    int middle = n - 1;

    for (int row = 0; row <= 2 * middle; row++)
    {
        for (int col = 0; col <= 2 * middle; col++)
        {
            int rowGap = row - middle;
            if (row < middle)
                rowGap = middle - row;

            int colGap = col - middle;
            if (col < middle)
                colGap = middle - col;

            // ring number
            int ring = rowGap;
            if (colGap > ring)
                ring = colGap;

            int shift = jumpOf(ring, base);
            int value;

            if (col < middle && colGap == ring && rowGap != ring)
            {
                value = seed - shift;
                if (row < middle)
                    value = value + 2 * jumpOf(rowGap, base);
            }
            else
            {
                value = seed + shift;
                if (row > middle)
                    value = value - 2 * jumpOf(rowGap, base);
            }

            value = value % base;
            if (value < 0)
                value = value + base;

            if (value < 10)
                cout << value;
            else
                cout << char('A' + value - 10);

            if (col < 2 * middle)
                cout << " ";
        }
        cout << endl;
    }
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

// ques 7 ka function or sub functions yahan par hein
int board[6][7];

// scanBoard ye teeno barhata hai
bool fourforhuman = false;
bool fourforcomp = false;
int grouppoints = 0;

// columns ki tarteeb
int columnOrder[7] = {3, 2, 4, 1, 5, 0, 6};

// piece column mein girao, jis row mein gira wo wapis do, column full ho to -1
int dropPiece(int col, int piece)
{
    for (int row = 5; row >= 0; row--)
    {
        if (board[row][col] == 0)
        {
            board[row][col] = piece;
            return row;
        }
    }
    return -1;
}

// upar wali row mein koi khali na ho to board full hai
bool boardIsFull()
{
    for (int col = 0; col < 7; col++)
        if (board[0][col] == 0)
            return false;
    return true;
}

// 4 dabbon ka ek group dekho
void lookAtFour(int first, int second, int third, int fourth)
{
    int cells[4] = {first, second, third, fourth};
    int computerCells = 0, humanCells = 0, emptyCells = 0;

    for (int i = 0; i < 4; i++)
    {
        if (cells[i] == 2)
            computerCells++;
        else if (cells[i] == 1)
            humanCells++;
        else
            emptyCells++;
    }

    if (computerCells == 4)
        fourforcomp = true;
    if (humanCells == 4)
        fourforhuman = true;

    if (computerCells == 3 && emptyCells == 1)
        grouppoints = grouppoints + 5;
    else if (computerCells == 2 && emptyCells == 2)
        grouppoints = grouppoints + 2;
    else if (humanCells == 3 && emptyCells == 1)
        grouppoints = grouppoints - 4;
}

// poore board ke saare groups dekho
void knowboard()
{
    fourforhuman = false;
    fourforcomp = false;
    grouppoints = 0;

    // seedhe groups
    for (int row = 0; row < 6; row++)
        for (int col = 0; col <= 3; col++)
            lookAtFour(board[row][col], board[row][col + 1], board[row][col + 2], board[row][col + 3]);

    // neeche ki taraf groups
    for (int row = 0; row <= 2; row++)
        for (int col = 0; col < 7; col++)
            lookAtFour(board[row][col], board[row + 1][col], board[row + 2][col], board[row + 3][col]);

    // neeche-right tirchay groups
    for (int row = 0; row <= 2; row++)
        for (int col = 0; col <= 3; col++)
            lookAtFour(board[row][col], board[row + 1][col + 1], board[row + 2][col + 2], board[row + 3][col + 3]);

    // neeche-left tirchay groups
    for (int row = 0; row <= 2; row++)
        for (int col = 3; col < 7; col++)
            lookAtFour(board[row][col], board[row + 1][col - 1], board[row + 2][col - 2], board[row + 3][col - 3]);
}

// ply 3: computer ki dobara bari, yahan search ruk jati hai
int computerSecondMove(int low, int high)
{
    int best = -1000000;

    for (int i = 0; i < 7; i++)
    {
        int col = columnOrder[i];
        int row = dropPiece(col, 2);
        if (row == -1)
            continue;                       // column full hai

        knowboard();
        int score;
        if (fourforcomp)
            score = 100000;
        else if (boardIsFull())
            score = 0;
        else
        {
            score = grouppoints;
            for (int r = 0; r < 6; r++)
                if (board[r][3] == 2)
                    score = score + 3;      // column 3 ka bonus
        }

        board[row][col] = 0;                // baari wapis

        if (score > best)
            best = score;
        if (best > low)
            low = best;
        if (low >= high)
            break;
    }
    return best;
}

// ply 2: human ka jawab, wo computer ke liye sab se bura chunta hai
int humanReply(int low, int high)
{
    int worst = 1000000;

    for (int i = 0; i < 7; i++)
    {
        int col = columnOrder[i];
        int row = dropPiece(col, 1);
        if (row == -1)
            continue;

        knowboard();
        int score;
        if (fourforhuman)
            score = -100001;
        else if (boardIsFull())
            score = 0;
        else
            score = computerSecondMove(low, high);

        board[row][col] = 0;

        if (score < worst)
            worst = score;
        if (worst < high)
            high = worst;
        if (low >= high)
            break;
    }
    return worst;
}

int pickComputerColumn()
{
    int low = -1000000;
    int high = 1000000;
    int best = -1000000;
    int bestColumn = -1;

    for (int i = 0; i < 7; i++)
    {
        int col = columnOrder[i];
        int row = dropPiece(col, 2);
        if (row == -1)
            continue;

        knowboard();
        int score;
        if (fourforcomp)
            score = 100002;
        else if (boardIsFull())
            score = 0;
        else
            score = humanReply(low, high);

        board[row][col] = 0;

        if (score > best)                
        {
            best = score;
            bestColumn = col;
        }
        if (best > low)
            low = best;
        if (low >= high)
            break;
    }
    return bestColumn;
}

void showBoard()
{
    cout << endl << "  0 1 2 3 4 5 6" << endl;
    for (int row = 0; row < 6; row++)
    {
        cout << "| ";
        for (int col = 0; col < 7; col++)
        {
            if (board[row][col] == 1)
                cout << "X ";
            else if (board[row][col] == 2)
                cout << "O ";
            else
                cout << ". ";
        }
        cout << "|" << endl;
    }
    cout << "+---------------+" << endl << endl;
}

bool gameIsOver(int lastPlayer)
{
    knowboard();
    if (lastPlayer == 1 && fourforhuman)
        cout << "You win!" << endl;
    else if (lastPlayer == 2 && fourforcomp)
        cout << "Computer wins!" << endl;
    else if (boardIsFull())
        cout << "It's a draw!" << endl;
    else
        return false;
    return true;
}

void question7()
{
    for (int row = 0; row < 6; row++)
        for (int col = 0; col < 7; col++)
            board[row][col] = 0;
    showBoard();

    bool playing = true;
    while (playing)
    {
        int col;
        int row = -1;
        while (row == -1)
        {
            cout << "Your move (column 0-6): ";
            cin >> col;

            if (col < 0 || col > 6)
                cout << "Invalid column! Choose between 0 and 6." << endl;
            else
            {
                row = dropPiece(col, 1);
                if (row == -1)
                    cout << "Column " << col << " is full! Choose another column." << endl;
            }
        }
        showBoard();

        if (gameIsOver(1))
            playing = false;
        else
        {
            // computer ki bari
            int computerColumn = pickComputerColumn();
            dropPiece(computerColumn, 2);
            cout << "Computer plays column " << computerColumn << endl;
            showBoard();

            if (gameIsOver(2))
                playing = false;
        }
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

    case 2:
        question2();
        break;    

    case 3:
        question3();
        break;   

    case 4:
        question4();
        break;

    case 5:
        question5();
        break;    

    case 7:
        question7();
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