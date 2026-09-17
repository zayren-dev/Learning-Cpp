/* This is a simple C++ program that demonstrates how to perform if-else work without actually
using ifs , logical and relational operators. */
#include<iostream>
using namespace std;
int main()
{
  int fee = 1599839;
  int a = fee/(150001);

  int cond = (2*a)/(a+1);

  int tax = cond* (fee * 0.1) + (1 - cond) * (fee * 0.05);
  cout << "tax " << tax << endl;
  cout << "The condition is " << cond << endl;
  return 0;

}