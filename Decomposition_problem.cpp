#include<iostream>
using namespace std;
int main () {
double a,b,c,result;
cout << " Enter the value of A "; 
cin >> a;
cout << " Enter the value of B"; 
cin >> b;
cout << " Enter the value of C"; 
cin >> c;
double num1 = (a+b)*(a+b)*(a+b)+((a-b)*(a-b)/c*a);
double den1 = (a+c)*(b+1);
double term1 = num1/den1;
double term2 = (a*a+b*c)/(c+2);
double term3 = (a*b)/(a+b+c);
double term4 = (int)a % (int)b;

result = (term1 - term2 + term3 + term4);
cout << "Result:" << result << endl;
return 0;
}





