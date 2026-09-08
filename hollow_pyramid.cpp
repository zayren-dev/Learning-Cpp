#include <iostream>
using namespace std;

int main() {
    int height;

    cout << "Enter the height of the pyramid: ";
    cin >> height;

    // Loop through each row
    for (int i = 1; i <= height; i++) {

        // Print spaces before the stars
        for (int j = 1; j <= height - i; j++) {
            cout << " ";
        }

        // Print stars and spaces inside the pyramid
        for (int j = 1; j <= (2 * i - 1); j++) {

            // Print stars on the left edge, right edge, and bottom
            if (j == 1 || j == (2 * i - 1) || i == height) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }

        // Move to the next row
        cout << endl;
    }

    return 0;
}
