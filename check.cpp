#include <iostream>

using namespace std;

void fun(int, int);

int main()
{ 
    fun(1, 2); 
}
void fun(int a = 10, int b = 7)
{ cout << a << " " << b << endl; }

