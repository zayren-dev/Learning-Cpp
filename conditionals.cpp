#include<iostream>
using namespace std;
int main () {

int x;
int y;
cout << "Enter the value of x";
cin >> x;
cout << "Enter the value of y";
cin >> y;
if  (x > y) {
cout << x << " is greater than" << y; }
else if ( y > x) {
cout<< y << " is greater than" << x; }
else {
cout << x << " and " << y << " are equal ";
 }   
   return 0;
}