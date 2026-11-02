#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // UPAR WALA HISSA
    for (int i = n; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++) cout << " ";          // spaces
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";      // stars
        cout << endl;
    }

    // NEECHAY WALA HISSA
    for (int i = 2; i <= n; i++) {
        for (int s = 1; s <= n - i; s++) cout << " ";
        for (int j = 1; j <= 2 * i - 1; j++) cout << "*";
        cout << endl;
    }
    return 0;
}