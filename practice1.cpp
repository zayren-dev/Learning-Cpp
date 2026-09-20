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
    int n = x - '4';
    cout<<n<<endl;

    cout<< "========================================"<< endl;
    cout<< "Dry Run 5 "<< endl;
    int f = 9;
    int k = 4;
    double s = f / k;
    double o = static_cast<double>(f) / k;
    char ch3 = 'M';
    cout << s << " " << o << " "<<endl;
    cout << ch3 + 4 << " "<<endl;
    cout << static_cast<char>(ch3 + 4)<<endl;

    cout<< "========================================"<< endl;
    cout<< "Dry Run 6 "<< endl;
    int e = 19;
    int r = 7;
    double h = e / r;
    double g = static_cast<double>(e / r);
    double j = static_cast<double>(e) / r;
    cout << h << " \n" << g << "\n" << j<<endl;

    cout<< "========================================"<< endl;
    cout<< "Dry Run 7 "<< endl;
    char c = 'N';
    cout << c + 4 << "\n";
    cout << static_cast<char>(c + 4) << " "<<endl;
    cout << c - 'A'<<endl;

    cout<< "========================================"<< endl;
    cout<< "Dry Run 7 "<< endl;
    char i = '8';
    int x1 = i - '0';
    double a3 = x1 / 3;
    double b8 = static_cast<double>(x1) / 3;
    cout << x1 << " " << a3 << " " << b8;



return 0;
}