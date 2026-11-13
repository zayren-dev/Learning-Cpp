#include <iostream>
using namespace std;

int main()
{
    int array[20];
    int sabse_bara;
    int dusra_bara;
    bool secondbiggest = false;

    cout << "Enter 20 integers:" << endl;
    for (int i = 0; i < 20; i++)
    {
    cout << "Enter your " << i + 1 << " number: ";
    cin >> array[i];}

    // idher na array ka pehla number sabse bara suppose karlete hein
    sabse_bara = array[0];
    for (int i = 1; i < 20; i++)
    {
        if (array[i] > sabse_bara)
        sabse_bara = array[i];}

    // baki number ko compare kar kar check kro konsa bara h 
    for (int i = 0; i < 20; i++)
    {
        if (array[i] != sabse_bara)
        {
            if (secondbiggest == false || array[i] > dusra_bara)
            { dusra_bara = array[i];
              secondbiggest = true;}
        }
    }

    if (secondbiggest)
    cout << "Second Largest: " << dusra_bara << endl;
    else
    cout << "No second largest (all numbers are equal)" << endl;
    
    return 0;}
