#include<iostream>
using namespace std;
int main()
{
    cout << "========================================"<< endl;
    cout << "Dry Run 1 "<< endl;
    int myvar = 5;
    if(-1){
        cout<< myvar<<endl;
        int myvar;
        myvar +=1;
        cout<< myvar-10<<endl;

    }
    else{
        cout<< myvar<<endl;
        int myvar;
        myvar -=1;
        cout<< myvar--<<endl;
    }
    cout<< myvar<<endl;



    cout<< "========================================"<< endl;
    cout<< "Dry Run 2 "<< endl;
    char ch1 = 'M';
    cout<< ch1 + 4 <<endl;
    cout << static_cast<char>(ch1 + 4);


    cout<< "========================================"<< endl;
    cout<< "Dry Run 3 "<< endl;
    char ch2 = 'd';
    cout << ch2 - 'a';

    cout<< "========================================"<< endl;
    cout<< "Dry Run 4 "<< endl;
    int x = 68;
    cout << static_cast<char>(x);
    char x = '5';
    cout << x+1;

    return 0;
}