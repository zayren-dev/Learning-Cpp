#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 3;

   
    cout << "Bitwise AND: " << (a & b) << endl;

   
    cout << "Bitwise OR: " << (a | b) << endl;

    
    cout << "Bitwise XOR: " << (a ^ b) << endl;

    
    cout << "Bitwise NOT of a: " << (~a) << endl;

    
    cout << "Left Shift: " << (a << 1) << endl;

    
    cout << "Right Shift: " << (a >> 1) << endl;

    return 0;
}