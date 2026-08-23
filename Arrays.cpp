// Leaning basic creation of arrays here is the syntax of how we create an array

// dataType arrayName[size] = {values};

#include <iostream>
using namespace std;

int main() {

    // An array stores multiple values of the same data type
    // Here, we are creating an array that can store 5 integers
    int marks[5] = {85, 72, 90, 68, 95};

    // We can access each value using its index
    // IMPORTANT: Array indexing starts from 0, not 1

    cout << "First mark: " << marks[0] << endl;
    cout << "Second mark: " << marks[1] << endl;
    cout << "Third mark: " << marks[2] << endl;
    cout << "Fourth mark: " << marks[3] << endl;
    cout << "Fifth mark: " << marks[4] << endl;

    return 0;
}