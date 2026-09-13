#include<iostream>
using namespace std;
int main () {

int z;
int y;
cout << "Enter the value of z";
cin >> z;
cout << "Enter the value of y";
cin >> y;
if  (z > y) {
cout << z << " is greater than" << y; }
else if ( y > z) {
cout<< y << " is greater than" << z; }
else {
cout << z << " and " << y << " are equal ";
 }   
   return 0;
}