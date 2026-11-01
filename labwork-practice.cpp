#include<iostream>
using namespace std;
int main() {
int x = 5, y =15;
static_cast<int>(y>x?10:5.5)%10;
return 0;
}