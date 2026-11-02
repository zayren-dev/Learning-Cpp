#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    // UPAR WALA HISSA (beech wali line tak)
    for (int m = n; m >= 1; m--) {
        for (int s = 1; s <= n - m; s++) cout << "  ";
        for (int j = m; j >= 1; j--)     cout << j << " ";
        for (int j = 2; j <= m; j++)     cout << j << " ";
        cout << endl;
    }

    // NEECHAY WALA HISSA
    for (int m = 2; m <= n; m++) {
        for (int s = 1; s <= n - m; s++) cout << "  ";
        for (int j = m; j >= 1; j--)     cout << j << " ";
        for (int j = 2; j <= m; j++)     cout << j << " ";
        cout << endl;
    }
    return 0;
}