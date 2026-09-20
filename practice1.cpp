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
    char ch = 'M';
    cout<< ch + 4 <<endl;
    return 0;
}