#include <iostream>
using namespace std;

int step(int v, char c) {
    switch (c) {
        case 'a': v += 2;
        case 'b': v *= 2; break;
        default:  v -= 1;
        case 'c': v += 3;
    }
    return v;
}

int main() {
    int t = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i; j++) {
            switch ((i + j) % 3) {
                case 0: t = step(t, 'a');
                case 1: t = step(t, 'b'); continue;
                case 2: t = step(t, 'x');
            }
            t++;
        }
        cout << t << " ";
    }
    cout << endl << t << '\t' << char('A' + t % 5);
    return 0;
}