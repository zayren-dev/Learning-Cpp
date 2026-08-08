// This is a simple C++ program that demonstrates input and output operations.
#include<iostream>
int main()
{
    int number; // here we declared a variable called number of type int
    std::cout << "Enter a number: "; // here we printed a message to the console asking the user to enter a number
    std::cin >> number; // here we took input from the user and stored it in the variable number
    std::cout << "You entered: " << number; // here we printed the value of number to the console
  return 0;

}