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


// ============================================================
// VOID FUNCTIONS
// ============================================================

/*
    Before learning loops, we need to understand 'void'.

    A function is a block of code that performs a task.

    'void' means the function does NOT return a value.

    Example:

        void sayHello()
        {
            cout << "Hello!" << endl;
        }

    This function simply performs an action.
    It does not give any value back to main().

    We use void here to keep each loop example separate
    and easy to understand.
*/


// ============================================================
// 1. FOR LOOP
// ============================================================

/*
    BASIC SYNTAX:

        for (starting_point; condition; update)
        {
            // code
        }

    Example:

        for (int i = 1; i <= 5; i++)
        {
            cout << i << endl;
        }
*/

void forLoop()
{
    cout << "\n--- FOR LOOP ---" << endl;

    for (int i = 1; i <= 5; i++)
    {
        cout << i << endl;
    }
}


// ============================================================
// 2. WHILE LOOP
// ============================================================

/*
    BASIC SYNTAX:

        while (condition)
        {
            // code
        }

    The condition is checked before the loop runs.
*/

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


// ============================================================
// 3. DO-WHILE LOOP
// ============================================================

/*
    BASIC SYNTAX:

        do
        {
            // code
        }
        while (condition);

    The code runs first and the condition is checked afterwards.

    A do-while loop always runs at least once.
*/

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


// ============================================================
// 4. BREAK
// ============================================================

/*
    'break' completely stops the loop.
*/

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


// ============================================================
// 5. CONTINUE
// ============================================================

/*
    'continue' skips the current iteration
    and moves to the next one.
*/

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


// ============================================================
// 6. NESTED LOOP
// ============================================================

/*
    A loop inside another loop is called a nested loop.

    BASIC STRUCTURE:

        for (...)
        {
            for (...)
            {
                // code
            }
        }
*/

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


// ============================================================
// MAIN FUNCTION
// ============================================================

int main()
{
    // Calling each loop example
    forLoop();

    whileLoop();

    doWhileLoop();

    breakExample();

    continueExample();

    nestedLoop();

    return 0;
}