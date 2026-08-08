#include<iostream>
int main ()
{
 int x;
 int y;
 std::cout << "Enter the value of x";
 std::cin >> x;
 std::cout << "Enter the value of y";
 std::cin >> y;
 if  (x > y) {
std::cout << x << " is greater than" << y; }
else if ( y > x) {
    std::cout<< y << " is greater than" << x; }
 else {
    std::cout << x << " and " << y << " are equal ";
 }   
    return 0;
}