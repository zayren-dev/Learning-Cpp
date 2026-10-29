#include <iostream>

using namespace std;
int main(){
int A[3] = {1, 2, 3};
int B[3] = {4, 5, 6};
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (i != j)
{
A[i] = A[i] + B[j];
B[j] = B[j] - 1;
}
}
}
cout << "Array A: ";
for (int i = 0; i < 3; i++)
cout << A[i] << " ";
cout << "\nArray B: ";
for (int i = 0; i < 3; i++)
cout << B[i] << " ";
    return 0;
}



