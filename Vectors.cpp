#include <iostream>
#include <vector>
using namespace std;

int main() {

    // A vector is like an array, but its size can change
    vector<int> numbers = {15, 25, 35, 50, 55};

    // Accessing an element using its index
    cout << "First number: " << numbers[0] << "\n" ; 
    cout << "Second number: " << numbers[1] << "\n";
    cout << "Last number: " << numbers[4] << "\n";
    // Adding a new number to the vector
    numbers.push_back(65);

    // Checking how many elements are in the vector
    cout << "Number of elements: " << numbers.size() << "\n";

    cout << "New last number:" << numbers[5] << "\n";

    // Removing the last number
    numbers.pop_back();

    // Printing all the elements
    cout << "Numbers: ";

    for (int number : numbers) {
        cout << number << " ";
    }

    cout << "\n";

    return 0;
}