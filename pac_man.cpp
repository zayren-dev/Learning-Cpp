#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(0));
    
    // Simple short variables like a student would write
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
    
    while (gameOn) {
        // Draw grid using simple step-by-step ternary assignments
        cout << "\n----------------------- Board -----------------------\n";
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
        
        // Collision checks
        int touchClyde = (px == clydex && py == clydey) ? 1 : 0;
        int touchBlinky = (px == bx && py == by) ? 1 : 0;
        int touchPinky = (px == pinkx && py == pinky) ? 1 : 0;
        int touchInky = (px == inkyx && py == inkyy) ? 1 : 0;
        
        int anyTouch = touchClyde | touchBlinky | touchPinky | touchInky;
        gameOn = (anyTouch == 1) ? 0 : 1;
        
      // Status print using correct ternary strings (no cout inside ternary)
        cout << ((touchClyde == 1) ? "Clyde reached! You Win!\n" : 
                 ((touchBlinky == 1 || touchPinky == 1 || touchInky == 1) ? "Caught by ghost! Game Over.\n" : ""));
        
        // Take input
        cout << "Enter control (W/A/S/D): ";
        cin >> moveInput;
        
        int oldPx = px;
        int oldPy = py;
        
        // Switch case for movement
        switch (moveInput) {
            case 'w':
            case 'W':
                py = (py > 0) ? py - 1 : py;
                break;
            case 's':
            case 'S':
                py = (py < 9) ? py + 1 : py;
                break;
            case 'a':
            case 'A':
                px = (px > 0) ? px - 1 : px;
                break;
            case 'd':
            case 'D':
                px = (px < 19) ? px + 1 : px;
                break;
            case 'q':
            case 'Q':
                gameOn = 0;
                break;
            default:
                break;
        }
        
        // Clyde Movement
        int moveX = px - oldPx;
        int moveY = py - oldPy;
        int tempClydeX = clydex + moveX;
        int tempClydeY = clydey + moveY;
        clydex = (tempClydeX >= 0 && tempClydeX < 20) ? tempClydeX : clydex;
        clydey = (tempClydeY >= 0 && tempClydeY < 10) ? tempClydeY : clydey;
        
        // Inky Movement
        double distB = pow(px - bx, 2) + pow(py - by, 2);
        double distP = pow(px - pinkx, 2) + pow(py - pinky, 2);
        double distC = pow(px - clydex, 2) + pow(py - clydey, 2);
        double distI = pow(px - inkyx, 2) + pow(py - inkyy, 2);
        
        int inkyClosest = (distI <= distB && distI <= distP && distI <= distC) ? 1 : 0;
        inkyps: 
        inkyx = (inkyClosest == 1) ? px : inkyx;
        inkyy = (inkyClosest == 1 && py > 0) ? py - 1 : inkyy;
        
        // Pinky Movement
        int stepX = (px > pinkx) ? 1 : ((px < pinkx) ? -1 : 0);
        int stepY = (py > pinky) ? 1 : ((py < pinky) ? -1 : 0);
        int nextPinkX = pinkx + stepX;
        int nextPinkY = pinky + stepY;
        pinkx = (nextPinkX >= 0 && nextPinkX < 20) ? nextPinkX : pinkx;
        pinky = (nextPinkY >= 0 && nextPinkY < 10) ? nextPinkY : pinky;
        
        // Blinky Movement
        btrack = (bx == 19 && bdir == 1 && by == 3) ? 1 : ((bx == 0 && bdir == -1 && by == 6) ? 0 : btrack);
        by = (btrack == 1 && by == 3 && bx == 19) ? 6 : ((btrack == 0 && by == 6 && bx == 0) ? 3 : by);
        bdir = (bx == 19 && bdir == 1) ? -1 : ((bx == 0 && bdir == -1) ? 1 : bdir);
        bx = bx + bdir;
    }
    
    return 0;
}