#include<iostream>
using namespace std;
int main () {
const int rows = 5, cols = 3;
int arr[rows][cols];     
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        cout << arr[i][j] << " ";
   return 0;
}