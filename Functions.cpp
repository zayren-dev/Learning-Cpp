#include <iostream>
using namespace std;

// A function is a block of code that does a specific task
void greet()
{
    cout << "Hello! Welcome to C++." <<"\n";
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    // Calling the greet function
    greet();

    // Calling the add function and storing its result
    int result = add(5, 3);

    cout << "The sum is: " << result << "\n";

    return 0;
}