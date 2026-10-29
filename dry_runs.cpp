#include <iostream>
using namespace std;

int f(int x, int y) {
    x++;
    y += x--;
    return x * y;
}

int main() {
    int a = 2, b = 3, k = 0;
    int arr[4] = {5, 1, 4, 2};
    int p = 0;
    for (int i = 0; i < 3; i++) {
        k += arr[p++] * (i + 1);
        if (arr[p] > 3 && ++a > 2)
            b += f(a++, k);
        else if (b-- > 3 || a++ < 0)
            k--;
        cout << a << b << k << p << " ";
    }
    cout << endl << a++ + b << ' ' << ++b - a;
    return 0;
}