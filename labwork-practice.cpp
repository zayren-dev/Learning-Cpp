#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {                       // ROW loop
        for (int s = 1; s <= n - i; s++) cout << " ";    // spaces wala loop
        for (int j = 1; j <= 2 * i - 1; j++) cout << i+j;  // number wala loop
        cout << endl;
    }
    return 0;
}