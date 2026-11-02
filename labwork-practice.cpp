#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;

    for (int i = 2*n-1; i >= 1; i--) {
        for (int s = 1; s <= (2*n-1)-i; s++) {
            if (s ==1) {
                cout << "| ";
            }else {
                cout << "  ";
            }
        }
        for (int j = 1; j <= 2*i-1; j++)     cout << "*" << " ";
        cout << endl; }

    for (int i = 2; i <= 2*n-1; i++) {
        for (int s = 1; s <= (2*n-1)-i; s++){
            if (s ==1) {
                cout << "| ";
            }else {
                cout << "  ";
            }
        };
        for (int j = 1; j <= 2*i-1; j++)     cout << "*" << " ";
        
       
        cout << endl;
    }
    

   
   
    
    return 0;}
