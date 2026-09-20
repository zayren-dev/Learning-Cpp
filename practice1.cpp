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
    cout << static_cast<char>(ch1 + 4)<< endl;


    cout<< "========================================"<< endl;
    cout<< "Dry Run 3 "<< endl;
    char ch2 = 'd';
    cout << ch2 - 'a'<< endl;

    cout<< "========================================"<< endl;
    cout<< "Dry Run 4 "<< endl;
    int z = 68;
    cout << static_cast<char>(z)<<endl;
    char x = '5';
    cout << x + 1<<endl;
    int n = x - '5';
    cout<<n<<endl;

    return 0;
}