#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    unsigned short u = 65520;
    u = u + 20; // 65520 + 20 = 65540. unsigned short max = 65535. 65540 - 65536 = 4. u = 4.
    
    int a = 17, b = 5;
    double d = 4.8;
    char ch = 'P'; // ASCII 80
    
    int modRes = -17 % b; // -17 % 5 = -2 (sign of numerator). modRes = -2.
    bool flag = (a / b) > 3; // a/b = 17/5 = 3. 3 > 3 is false. flag = false.
    
    if (modRes < 0) { // -2 < 0 is true.
        int a = 10; // Shadows outer a. Inner a = 10.
        d = d + a / 3; // inner a / 3 = 10 / 3 = 3. d = 4.8 + 3 = 7.8.
        ch = ch + u; // 80 + 4 = 84. ASCII 84 is 'T'.
        cout << left << setfill('$') << setw(8) << d << " " << ch << endl;
        // d is 7.8. setw(8) left-aligned with '$': "7.8$$$$$". Space, then 'T'.
        // Output: "7.8$$$$$ T"
    }
    
    if (u < 5 || a > 15) { // u is 4. 4 < 5 is true. Short-circuit, enters block.
        u = u + b; // u = 4 + 5 = 9.
        cout << "Block2: " << u << " " << static_cast<int>(ch) << endl;
        // 'T' is 84. u is 9.
        // Output: "Block2: 9 84"
    }
    
    if (!flag) { // flag is false. !flag is true. Enters block.
        cout << right << setfill(' ') << fixed << setprecision(2) << setw(6) << d << " " << 
        a << " " << b << endl;
        // d is 7.8. fixed setprecision(2) -> 7.80. setw(6) right-aligned spaces -> "  7.80".
        // outer a is 17. b is 5.
        // Output: "  7.80 17 5"
    }
    
    return 0;
}