#include <iostream>
using namespace std;
int main()
{
    
    cout << "========================================"<< endl;
    cout << "Dry Run 1 "<< endl;
    unsigned short x = 65500;
    x = x + 100;
    cout << x<<endl;
    cout<<"========================================"<<endl;
    cout<<"Dry Run 2 "<<endl;
    int z = -5;
    unsigned int y = z;
    cout << y<<endl;
    cout<<"========================================"<<endl;
    cout<<"Dry Run 3 "<<endl;
    bool a = 8 , b = -6 , c = 0;
    cout << a << "\n" << b << "\n" << c <<endl;
    if (-1)
       cout << "YES";
    else
       cout << "NO"<<endl;
    cout<<"========================================"<<endl;
    cout<<"Dry Run 4 "<<endl;
    int x1 = 0;
    if (false && ++x1)
       cout << "YES";
    cout << x1<<endl;
    
    cout<<"========================================"<<endl;
    cout<<"Dry Run 5 "<<endl;
    int x2 = 10;
   if (true) {
       int y3 = 20;
       cout << y3<<endl;
    }
   // cout << y3 <<endl; this would not work and would give an error 

   // shadowing of variables 
  
   int x4 = 10;
   if (true) {
    int x4 = 20;
    cout << x4<<endl;
    }
   cout << x4<<endl;

   cout<<"========================================"<<endl;
   cout<<"Dry Run 6 "<<endl;
   int m;
   cin >> m;
   int hour = m/100;
   int min = m%100;
   int hr=hour%12;
   char c1 = 'A';
   if(hr==0)
        hr=12;
   if (hour>=12)
      c1 ='P';
   cout<<hr<< ":" << min/10 << min%10 << " " << c1 << "M" << endl;
    return 0;
}