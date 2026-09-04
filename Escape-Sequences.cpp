#include <iostream>
using namespace std;

int main() {

    // \n moves the cursor to a new line
    cout << "Hello\nWorld";

    cout << "\n\n"; // Two new lines
    cout << "I am Zayn ";

    // \t adds a tab space
    cout << "Name:\tZayn\n";
    cout << "Age:\t20\n";

    // \" allows us to print double quotes
    cout << "He said, \"Hello!\"\n";

    // \' allows us to print a single quote
    cout << " \' It's a C++ program. \'\n";

    // \\ allows us to print a backslash
    cout << "This is a backslash: \\\n";

    // \b moves the cursor one position back
    cout << "Hello\b\n";

    // \r moves the cursor back to the beginning of the line
    // The text after \r can overwrite the text already printed
    cout << "12345\rAB\n";

    // endl also moves to a new line but it requires the stream insertion operator
    cout << "This is line one." << endl;
    cout << "This is line two." << endl;


    return 0;
}