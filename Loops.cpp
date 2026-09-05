#include <iostream>
using namespace std;

/*
    ============================
             C++ LOOPS
    ============================
 
    Loops are used to repeat code.

    Main types of loops:

    1. for loop
    2. while loop
    3. do-while loop
*/

void ForLoop(){
   int n;
   cout << "\n Enter the number of which you want to print the table\n";
   cin>>n;
   for(int i=1;i<=11;i++)
   {
       cout << n << " x " << i << " = " << n*i << endl;

}
}


void whileLoop()
{
    cout << "\n--- WHILE LOOP ---" << endl;

    int i = 1;

    while (i <= 5)
    {
        cout << i << endl;

        // Increase i so the loop can eventually stop
        i++;
    }
}


void doWhileLoop()
{
    cout << "\n--- DO-WHILE LOOP ---" << endl;

    int i = 1;

    do
    {
        cout << i << endl;
        i++;
    }
    while (i <= 5);
}


void breakExample()
{
    cout << "\n--- BREAK ---" << endl;

    for (int i = 1; i <= 5; i++)
    {
        if (i == 3)
        {
            break;
        }

        cout << i << endl;
    }
}



void continueExample()
{
    cout << "\n--- CONTINUE ---" << endl;

    for (int i = 1; i <= 5; i++)
    {
        if (i == 3)
        {
            continue;
        }

        cout << i << endl;
    }
}


void nestedLoop()
{
    cout << "\n--- NESTED LOOP ---" << endl;

    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}


int main()
{
    // Calling each loop example
    ForLoop();

    whileLoop();

    doWhileLoop();

    breakExample();

    continueExample();

    nestedLoop();

    return 0;
}