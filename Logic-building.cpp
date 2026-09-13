#include <iostream>
using namespace std;

int main()
{
 
    int age;
    int marks;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

   if (age >= 18)
    {
        cout << "You are an adult." << endl;

        if (marks >= 50)
        {
            cout << "You passed." << endl;
        }
        else
        {
            cout << "You failed." << endl;
        }
    }
    else
    {
        cout << "You are under 18." << endl;
    }

    int number;

    cout << endl;
    cout << "Enter a number: ";
    cin >> number;

    if (number > 0)
    {
        cout << "Number is positive." << endl;

        if (number % 2 == 0)
        {
            cout << "Number is even." << endl;
        }
        else
        {
            cout << "Number is odd." << endl;
        }
    }
    else
    {
        cout << "Number is not positive." << endl;
    }


    cout << endl;
    cout << "Pattern:" << endl;

    for (int row = 1; row <= 3; row++)
    {
        for (int column = 1; column <= 3; column++)
        {
            cout << column << " ";
        }

        cout << endl;
    }


    

    cout << endl;
    cout << "Star Pattern:" << endl;

    for (int row = 1; row <= 4; row++)
    {
        for (int star = 1; star <= row; star++)
        {
            cout << "*";
        }

        cout << endl;
    }


    

    cout << endl;
    cout << "Numbers and their type:" << endl;

    for (int i = 1; i <= 10; i++)
    {
        cout << i << " ";

        if (i % 2 == 0)
        {
            cout << "Even";
        }
        else
        {
            cout << "Odd";
        }

        cout << endl;
    }


    

    cout << endl;
    cout << "Nested loop with if:" << endl;

    int value = 1;

    for (int row = 1; row <= 3; row++)
    {
        for (int column = 1; column <= 3; column++)
        {
            if (value % 2 == 0)
            {
                cout << value << " ";
            }
            else
            {
                cout << value << "* ";
            }

            value++;
        }

        cout << endl;
    }



    return 0;
}
