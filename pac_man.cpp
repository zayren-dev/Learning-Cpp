#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    int px = rand() % 20;
    int py = rand() % 10;
    
    int bx = rand() % 20;
    int by = 3;
    int bdir = 1;
    int btrack = 0;
    
    int pinkx = rand() % 20;
    int pinky = rand() % 10;
    
    int inkyx = rand() % 20;
    int inkyy = rand() % 10;
    
    int clydex = rand() % 20;
    int clydey = rand() % 10;
    
    char moveInput;
    int gameOn = 1;
    
    while (gameOn == 1) {
        int row = 0;
        while (row < 10) {
            int col = 0;
            while (col < 20) {
                char symbol = '*';
                symbol = (col == px && row == py) ? '@' : symbol;
                symbol = (col == bx && row == by) ? 'B' : symbol;
                symbol = (col == pinkx && row == pinky) ? 'P' : symbol;
                symbol = (col == inkyx && row == inkyy) ? 'I' : symbol;
                symbol = (col == clydex && row == clydey) ? 'C' : symbol;
                cout << symbol;
                col++;
            }
            cout << "\n";
            row++;
        }
        
        int touchClyde = (px == clydex && py == clydey) ? 1 : 0;
        int touchBlinky = (px == bx && py == by) ? 1 : 0;
        int touchPinky = (px == pinkx && py == pinky) ? 1 : 0;
        int touchInky = (px == inkyx && py == inkyy) ? 1 : 0;
        int anyTouch = touchClyde + touchBlinky + touchPinky + touchInky;
        gameOn = (anyTouch > 0) ? 0 : 1;
        
        cout << ((touchClyde == 1) ? "Clyde reached! You Win!\n" : 
                 ((touchBlinky == 1 || touchPinky == 1 || touchInky == 1) ? "Caught by ghost! Game Over.\n" : ""));
        
        char dummy = (gameOn == 1) ? (cout << "Enter control (W/A/S/D or Q): ", cin >> moveInput, '0') : '0';
        
        int oldPx = px;
        int oldPy = py;
        
        switch (moveInput) {
            case 'w':
            case 'W':
                py = (gameOn == 1 && py > 0) ? py - 1 : py;
                break;
            case 's':
            case 'S':
                py = (gameOn == 1 && py < 9) ? py + 1 : py;
                break;
            case 'a':
            case 'A':
                px = (gameOn == 1 && px > 0) ? px - 1 : px;
                break;
            case 'd':
            case 'D':
                px = (gameOn == 1 && px < 19) ? px + 1 : px;
                break;
            case 'q':
            case 'Q':
                gameOn = 0;
                break;
            default:
                break;
        }
        
        int moveX = (gameOn == 1) ? (px - oldPx) : 0;
        int moveY = (gameOn == 1) ? (py - oldPy) : 0;
        int tempClydeX = clydex + moveX;
        int tempClydeY = clydey + moveY;
        clydex = (gameOn == 1 && tempClydeX >= 0 && tempClydeX < 20) ? tempClydeX : clydex;
        clydey = (gameOn == 1 && tempClydeY >= 0 && tempClydeY < 10) ? tempClydeY : clydey;
        
        double distB = pow(px - bx, 2) + pow(py - by, 2);
        double distP = pow(px - pinkx, 2) + pow(py - pinky, 2);
        double distC = pow(px - clydex, 2) + pow(py - clydey, 2);
        double distI = pow(px - inkyx, 2) + pow(py - inkyy, 2);
        
        int inkyClosest = (gameOn == 1 && distI <= distB && distI <= distP && distI <= distC) ? 1 : 0;
        inkyx = (inkyClosest == 1) ? px : inkyx;
        inkyy = (inkyClosest == 1 && py > 0) ? py - 1 : inkyy;
        
        int stepX = (gameOn == 1 && px > pinkx) ? 1 : ((gameOn == 1 && px < pinkx) ? -1 : 0);
        int stepY = (gameOn == 1 && py > pinky) ? 1 : ((gameOn == 1 && py < pinky) ? -1 : 0);
        int nextPinkX = pinkx + stepX;
        int nextPinkY = pinky + stepY;
        pinkx = (gameOn == 1 && nextPinkX >= 0 && nextPinkX < 20) ? nextPinkX : pinkx;
        pinky = (gameOn == 1 && nextPinkY >= 0 && nextPinkY < 10) ? nextPinkY : pinky;
        
        btrack = (gameOn == 1 && bx == 19 && bdir == 1 && by == 3) ? 1 : ((gameOn == 1 && bx == 0 && bdir == -1 && by == 6) ? 0 : btrack);
        by = (gameOn == 1 && btrack == 1 && by == 3 && bx == 19) ? 6 : ((gameOn == 1 && btrack == 0 && by == 6 && bx == 0) ? 3 : by);
        bdir = (gameOn == 1 && bx == 19 && bdir == 1) ? -1 : ((gameOn == 1 && bx == 0 && bdir == -1) ? 1 : bdir);
        bx = (gameOn == 1) ? (bx + bdir) : bx;
    }
    
    return 0;
}