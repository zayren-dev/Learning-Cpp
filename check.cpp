#include <iostream>

using namespace std;
int main(){
int A[5] = {1, 2, 3, 4, 5};
int B[5] = {5, 4, 3, 2, 1};
for (int i = 1; i < 5; i++)
{
A[i] = A[i] + A[i - 1];
B[i] = B[i] + B[i - 1];
}
cout << "Array A: ";
for (int i = 0; i < 5; i++)
cout << A[i] << " ";
cout << "\nArray B: ";
for (int i = 0; i < 5; i++)
cout << B[i] << " ";
    return 0;
}



