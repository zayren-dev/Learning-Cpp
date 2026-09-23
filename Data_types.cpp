#include <iostream>
using namespace std;

int main()
{
    int age = 18;
    float height = 5.11;
    double price = 96.94;
    char grade = 'A';
    bool passed = true;

    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Price: " << price << endl;
    cout << "Grade: " << grade << endl;
    cout << "Passed: " << passed << endl;

    // IMPLICIT CASTING
    int number = 10;
    double result = number;

    cout << "\nImplicit casting:" << endl;
    cout << "Integer: " << number << endl;
    cout << "Double: " << result << endl;

    int a = 8;
    double b = 4.5;

    // a is automatically converted into double
    double sum = a + b;

    cout << "Sum: " << sum << endl;

    // In EXPLICIT CASTING we tell C++ to convert the value ourselves
    double marks = 95.75;
    int wholeMarks = (int)marks;

    cout << "\nExplicit casting:" << endl;
    cout << "Original value: " << marks << endl;
    cout << "After converting to int: " << wholeMarks << endl;

   
    double value = 13.75;

    int newValue = static_cast<int>(value);

    cout << "\nStatic cast:" << endl;
    cout << "Original value becomes: " << value << endl;
    cout << "After static_cast: " << newValue << endl;


    // static_cast can also convert int into double
    int x = 10;

    double converted = static_cast<double>(x);

    cout << "Integer: " << x << endl;
    cout << "Converted to double: " << converted << endl;

    // C-STYLE CASTING
   // C-style casting uses (datatype)value
    double number2 = 25.75;

    int number3 = (int)number2;

    cout << "\nC-style casting:" << endl;
    cout << "Original value: " << number2 << endl;
    cout << "After C-style cast: " << number3 << endl;

    // INTEGER DIVISION

    int num1 = 5;
    int num2 = 2;
   // Both are integers, so the answer will be 2
    int division = num1 / num2;

    cout << "\nInteger division:" << endl;
    cout << "5 / 2 = " << division << endl;


    // Convert one number to double
    // so we can get the decimal answer
    double decimalDivision = static_cast<double>(num1) / num2;
    cout << "5 / 2 = " << decimalDivision << endl;


    return 0;
}