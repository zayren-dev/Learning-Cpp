#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// saari file ky functions yahan hi hunge 
// Question 2 ky functions
bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int daysInMonth(int month, int year)
{
    if (month == 2)
    {
        if (isLeapYear(year))
            return 29;
        else
            return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else
        return 31;
}
// question 4 ky functions
int ringJump(int ring, int base)
{
    int total = 0;
    int addNow = 1;
    int addNext = 1;

    for (int i = 1; i <= ring; i++)
    {
        total = (total + addNow) % base;
        int temp = (addNow + addNext) % base;
        addNow = addNext;
        addNext = temp;
    }
    return total;
}
// question 5 ky functions or global variables 
long long mineRow0 = 0, mineRow1 = 0, mineRow2 = 0, mineRow3 = 0, mineRow4 = 0;
long long mineRow5 = 0, mineRow6 = 0, mineRow7 = 0, mineRow8 = 0, mineRow9 = 0;
int mineSize;

long long minePowerOfTen(int times)
{
    long long answer = 1;
    for (int i = 0; i < times; i++)
    {
        answer = answer * 10;
    }
    return answer;
}
long long mineGetRow(int r)
{
    if (r == 0) return mineRow0;
    if (r == 1) return mineRow1;
    if (r == 2) return mineRow2;
    if (r == 3) return mineRow3;
    if (r == 4) return mineRow4;
    if (r == 5) return mineRow5;
    if (r == 6) return mineRow6;
    if (r == 7) return mineRow7;
    if (r == 8) return mineRow8;
    return mineRow9;
}
void mineSetRow(int r, long long value)
{
    if (r == 0) mineRow0 = value;
    if (r == 1) mineRow1 = value;
    if (r == 2) mineRow2 = value;
    if (r == 3) mineRow3 = value;
    if (r == 4) mineRow4 = value;
    if (r == 5) mineRow5 = value;
    if (r == 6) mineRow6 = value;
    if (r == 7) mineRow7 = value;
    if (r == 8) mineRow8 = value;
    if (r == 9) mineRow9 = value;
}
int mineGetCell(int r, int c)
{
    long long place = minePowerOfTen(mineSize - 1 - c);
    return (mineGetRow(r) / place) % 10;
}
int mineVisit(int r, int c)
{
    if (r < 0 || r >= mineSize || c < 0 || c >= mineSize)
    {
        return 0;
    }
    int cell = mineGetCell(r, c);
    if (cell == 1 || cell >= 5)
    {
        return 0;
    }
    mineSetRow(r, mineGetRow(r) + 5 * minePowerOfTen(mineSize - 1 - c));
    return 1;
}


int main(){
    int choice;
    cout << "Choose a question (1-8), or 0 to exit:" << endl;
    cout << "1. Question 1" << endl;
    cout << "2. Question 2" << endl;
    cout << "3. Question 3" << endl;
    cout << "4. Question 4" << endl;
    cout << "5. Question 5" << endl;
    cout << "6. Question 6" << endl;
    cout << "7. Question 7" << endl;
    cout << "8. Question 8" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
    {
        int n; 
        cout << "Enter n: ";
        cin >> n;
  
        while (n <= 2 || n % 2 == 0)
          {
           cout << "Invalid input! n must be an odd number greater than 2." << endl;
           cout << "Enter n: ";
           cin >> n; }
       
        for (int row = 0; row < n; row++){
            for (int col = 0; col < n; col++)
        {
                int fromTop = row;
                int fromBottom = n - 1 - row;
                int fromLeft = col;
                int fromRight = n - 1 - col;

                int distancefromedge = fromTop;
                if (fromBottom < distancefromedge)
                   distancefromedge = fromBottom;
                if (fromLeft < distancefromedge)
                   distancefromedge = fromLeft;
                if (fromRight < distancefromedge)
                   distancefromedge = fromRight;
  
                int numberToPrint = distancefromedge + 1;
                cout << numberToPrint % 10 << " ";}
            cout << endl;}
    break;}


    case 2: 
    {
        int year, month;
        cout << "Year::: ";
        cin >> year;
        while (year < 1 || year > 9999)
    {
              cout << "Year should be in between 1 to 9999." << endl;
              cout << "Year::: ";
              cin >> year;}

        cout << "Month::: ";
        cin >> month;
        while (month < 1 || month > 12)
    {
               cout << "Month should be in between 1 to 12 ." << endl;
               cout << "Month::: ";
               cin >> month;}

        int totalDays = 0;
        for (int y = 1; y < year; y++)
    {
            if (isLeapYear(y))
                totalDays = totalDays + 366;
            else
                totalDays = totalDays + 365;}

        for (int m = 1; m < month; m++){
            totalDays = totalDays + daysInMonth(m, year);}

        int startDay = (totalDays + 1) % 7;
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
        else nameLength = 8;

        int yearDigits;
        if (year < 10) 
           yearDigits = 1;
        else if (year < 100) 
           yearDigits = 2;
        else if (year < 1000) 
           yearDigits = 3;
        else yearDigits = 4;

        int spaces = (20 - (nameLength + 1 + yearDigits)) / 2;
        cout << endl;
        for (int i = 0; i < spaces; i++)
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
        else cout << "December";

        cout << " " << year << endl;
        cout << "Su Mo Tu We Th Fr Sa" << endl;

        int column = 0;
        for (int i = 0; i < startDay; i++){
            if (column > 0)
                cout << " ";
            cout << "  ";
            column++;}

        int lastDate = daysInMonth(month, year);
        for (int date = 1; date <= lastDate; date++){
            if (column > 0)
               cout << " ";
            cout << setw(2) << date;
            column++;
            if (column == 7){
               cout << endl;
               column = 0;}}

        if (column != 0)
        cout << endl;
    break;}


    case 3: 
    {
        int n;
        cout << "Enter n: ";
        cin >> n;
        for ( ; n <= 2 || n % 2 == 0; ){
            cout << "n must be greater than 2 and it can not be even." << endl;
            cout << "Enter n: ";
            cin >> n;}
        int middleRow = n - 1;        
        int totalRows = 2 * n - 1;    

        for (int row = 0; row < totalRows; row++){
             int rowGap = row - middleRow;
             if (rowGap < 0)
                rowGap = -rowGap;
             for (int space = 1; space <= rowGap; space++)
                 cout << " ";
             int reach = middleRow - rowGap;
             for (int col = -reach; col <= reach; col++){
                  int colGap = col;
                  if (colGap < 0)
                     colGap = -colGap;
                  int distance = rowGap + colGap;
                  int turn = distance % 4;
                  if (turn == 0)
                     cout << "*";
                  else if (turn == 1)
                     cout << "-";
                  else if (turn == 2)
                     cout << "o";
                  else
                     cout << ".";}
            cout << endl;}
    break;}



    case 4: 
    {
        int n, base, seed;
        cout << "N: "; cin >> n;
        while (n < 1){
              cout << "N must be 1 or more." << endl;
              cout << "N: "; cin >> n;}

        cout << "Base: ";
        cin >> base;
        while (base < 2 || base > 16){
              cout << "Base must be between 2 and 16." << endl;
              cout << "Base: ";
              cin >> base;}
        cout << "Seed: "; cin >> seed;
        cout << endl;
        int middle = n - 1;        
        int last = 2 * n - 2;     
        for (int row = 0; row <= last; row++){
            for (int col = 0; col <= last; col++){
                int edge = row;
                if (col < edge)
                   edge = col;
                if (last - row < edge)
                   edge = last - row;
                if (last - col < edge)
                   edge = last - col;
                int ring = middle - edge;
                int jump = ringJump(ring, base);
                int value;
                if (col == edge && row > edge && row < last - edge){
                   if (row < middle)
                       value = seed - jump + 2 * ringJump(middle - row, base);
                   else
                       value = seed - jump;}
                else{
                   if (row > middle)
                       value = seed + jump - 2 * ringJump(row - middle, base);
                   else
                       value = seed + jump;}
                value = ((value % base) + base) % base;
                if (value < 10)
                   cout << value;
                else
                   cout << char('A' + value - 10);
                if (col != last)
                   cout << " ";}
        cout << endl;}

    break;}


    case 5:
    {
         char symbol;
         int digit;
         long long rowValue;
         cin >> mineSize;
         for (int r = 0; r < mineSize; r++){
              rowValue = 0;
              for (int c = 0; c < mineSize; c++){
                  cin >> symbol;
                  if (symbol == '.') digit = 0;
                  if (symbol == '*') digit = 1;
                  if (symbol == 'G') digit = 2;
                  if (symbol == 'S') digit = 8;
                  if (symbol == 'E') digit = 4;
                  rowValue = rowValue * 10 + digit;}
             mineSetRow(r, rowValue);}

        int found = 1;
        while (found == 1){
              found = 0;
              for (int r = 0; r < mineSize; r++){
                  for (int c = 0; c < mineSize; c++){
                      if (mineGetCell(r, c) >= 5){
                         if (mineVisit(r - 1, c) == 1) found = 1;   
                         if (mineVisit(r + 1, c) == 1) found = 1;   
                         if (mineVisit(r, c - 1) == 1) found = 1; 
                         if (mineVisit(r, c + 1) == 1) found = 1;}}}}
        int goldCount = 0;
        int exitReached = 0;
        for (int r = 0; r < mineSize; r++){
            for (int c = 0; c < mineSize; c++){
                if (mineGetCell(r, c) == 7) goldCount++;
                if (mineGetCell(r, c) == 9) exitReached = 1;}}
        if (exitReached == 1) cout << "Solvable: YES" << endl;
        else cout << "Solvable: NO" << endl;
        cout << "Gold reachable: " << goldCount << endl;
    
    
    break;}

    
    case 0: {
        cout << "Exiting program..." << endl;}
    break;

    
    default: {
        cout << "Invalid choice. Please select a number from 0 to 8." << endl;}
    break;

}
}