#include <iostream>
using namespace std;

int main()
{
    char comp_sen[20];
    int countA = 0, countE = 0, countI = 0, countO = 0, countU = 0;
    int uppertotal = 0;
    int lowertotal = 0;

    cout << "Enter a sentence: ";
    cin.getline(comp_sen, 20); 

    for (int i = 0; comp_sen[i] != '\0'; i++)
    {
        if (comp_sen[i] >= 65 && comp_sen[i] <= 90)
           uppertotal++;
        else if (comp_sen[i] >= 97 && comp_sen[i] <= 122)
           lowertotal++;
        
    }

    cout << endl;
    cout << "Uppercase Letters: " << uppertotal << endl;
    cout << "Lowercase Letters: " << lowertotal << endl;
    for (int i = 0; comp_sen[i] != '\0'; i++)
    {
        switch (comp_sen[i])
        { case 'a': case 'A': countA++; break;
          case 'e': case 'E': countE++; break;
          case 'i': case 'I': countI++; break;
          case 'o': case 'O': countO++; break;
          case 'u': case 'U': countU++; break;
        }
    }

    cout << endl;
    cout << "Vowel Frequencies:" << endl;
    cout << "a: " << countA << endl;
    cout << "e: " << countE << endl;
    cout << "i: " << countI << endl;
    cout << "o: " << countO << endl;
    cout << "u: " << countU << endl;

    for (int i = 0; comp_sen[i] != '\0'; i++)
    {
        bool firstletter = (i == 0 || comp_sen[i - 1] == ' ');
        if (firstletter && comp_sen[i] >= 97 && comp_sen[i] <= 122)
        comp_sen[i] = comp_sen[i] - 97 + 65;
        
    }

    cout << endl;
    cout << "Capitalized Sentence: " << comp_sen << endl;

    return 0;
}
