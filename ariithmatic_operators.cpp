// Arithmatic Operators
#include<iosstream>
using namespace std;
int main()
{
  int a;
  cout<< " Enter value od a:";
  cin >> a;
  int b;
  cout<< " Enter value of b:";
  cin >> b;
  int sum = a + b;
  cout<< " The sum is: " << sum;
  int difference = a - b;
  cout<< " The difference is: " << difference;
  int product = a * b;
  cout<< " The product is: " << product;
  int quotient = a / b;
  cout<< " The quotient is: " << quotient;
  int remainder = a % b;
  cout<< " The remainder is: " << remainder;
}
