#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    // Board dimensions: Width = 20, Height = 10[cite: 1]
    // Initial random positions[cite: 1]
    srand(time(0));
    int pacX = rand() % 20;
    int pacY = rand() % 10;
    
    // Blinky: starts at height 3 from top (y = 3), moving right[cite: 1]
    int blinkyX = rand() % 20;
    int blinkyY = 3;
    int blinkyDirection = 1; // 1 for right, -1 for left[cite: 1]
    int blinkyState = 0;     // 0 for top track, 1 for bottom track[cite: 1]
    
    int pinkyX = rand() % 20;
    int pinkyY = rand() % 10;
    
    int inkyX = rand() % 20;
    int inkyY = rand() % 10;
    
    int clydeX = rand() % 20;
    int clydeY = rand() % 10;
    
    char playerInput;
    int gameRunning = 1;

    while (gameRunning) {
        // 1. Draw the board using nested loops and ternary operators (no if-else)[cite: 1]
        cout << "\n================ PAC-A-MAN ================\n";
        for (int y = 0; y < 10; ++y) {
            for (int x = 0; x < 20; ++x) {
                char cellChar = (x == pacX && y == pacY) ? '@' :
                                ((x == blinkyX && y == blinkyY) ? 'B' :
                                ((x == pinkyX && y == pinkyY) ? 'P' :
                                ((x == inkyX && y == inkyY) ? 'I' :
                                ((x == clydeX && y == clydeY) ? 'C' : '*'))));
                cout << cellChar;
            }
            cout << "\n";
        }

        // 2. Check win/loss conditions[cite: 1]
        int clydeMet = (pacX == clydeX && pacY == clydeY) ? 1 : 0;
        int blinkyCaught = (pacX == blinkyX && pacY == blinkyY) ? 1 : 0;
        int pinkyCaught = (pacX == pinkyX && pacY == pinkyY) ? 1 : 0;
        int inkyCaught = (pacX == inkyX && pacY == inkyY) ? 1 : 0;

        int isGameOver = clydeMet | blinkyCaught | pinkyCaught | inkyCaught;
        gameRunning = (isGameOver == 1) ? 0 : 1;

        // Display status message using ternary operator
        cout << ((clydeMet == 1) ? "Clyde reached Pac-Man! Ghostbusters called, you win!\n" :
                 ((blinkyCaught == 1 || pinkyCaught == 1 || inkyCaught == 1) ? "A ghost caught Pac-Man! Game Over.\n" : ""));

        // Terminate loop if game ended
        gameRunning = (isGameOver == 1) ? 0 : gameRunning;
        int shouldContinue = (gameRunning == 0) ? 0 : 1;
        
        // Exit loop early if game over
        char continuePromptChar = (shouldContinue == 1) ? 'y' : 'n';
        // (Using standard loop termination via gameRunning variable)
        if (gameRunning == 0) {
            break;
        }

        // 3. Take Pac-Man input (WASD)[cite: 1]
        cout << "Enter move (W/A/S/D or Q to quit): ";
        cin >> playerInput;

        int prevPacX = pacX;
        int prevPacY = pacY;

        // Switch case for Pac-Man movement (no if-else)[cite: 1]
        switch (playerInput) {
            case 'w':
            case 'W':
                pacY = (pacY > 0) ? pacY - 1 : pacY;
                break;
            case 's':
            case 'S':
                pacY = (pacY < 9) ? pacY + 1 : pacY;
                break;
            case 'a':
            case 'A':
                pacX = (pacX > 0) ? pacX - 1 : pacX;
                break;
            case 'd':
            case 'D':
                pacX = (pacX < 19) ? pacX + 1 : pacX;
                break;
            case 'q':
            case 'Q':
                gameRunning = 0;
                break;
            default:
                break;
        }

        // 4. Check each ghost's logic and update movement in order: Clyde, Inky, Pinky, Blinky[cite: 1]

        // --- Clyde Logic ---
        int pacDeltaX = pacX - prevPacX;
        int pacDeltaY = pacY - prevPacY;
        int proposedClydeX = clydeX + pacDeltaX;
        int proposedClydeY = clydeY + pacDeltaY;
        clydeX = (proposedClydeX >= 0 && proposedClydeX < 20) ? proposedClydeX : clydeX;
        clydeY = (proposedClydeY >= 0 && proposedClydeY < 10) ? proposedClydeY : clydeY;

        // --- Inky Logic ---
        double distBlinky = pow(pacX - blinkyX, 2) + pow(pacY - blinkyY, 2);
        double distPinky = pow(pacX - pinkyX, 2) + pow(pacY - pinkyY, 2);
        double distClyde = pow(pacX - clydeX, 2) + pow(pacY - clydeY, 2);
        double distInky = pow(pacX - inkyX, 2) + pow(pacY - inkyY, 2);

        int isInkyClosest = (distInky <= distBlinky && distInky <= distPinky && distInky <= distClyde) ? 1 : 0;
        int inkyTeleportX = pacX;
        int inkyTeleportY = (pacY > 0) ? pacY - 1 : pacY;
        
        inkyX = (isInkyClosest == 1) ? inkyTeleportX : inkyX;
        inkyY = (isInkyClosest == 1) ? inkyTeleportY : inkyY;

        // --- Pinky Logic ---
        int pinkyDeltaX = (pacX > pinkyX) ? 1 : ((pacX < pinkyX) ? -1 : 0);
        int pinkyDeltaY = (pacY > pinkyY) ? 1 : ((pacY < pinkyY) ? -1 : 0);
        
        int proposedPinkyX = pinkyX + pinkyDeltaX;
        int proposedPinkyY = pinkyY + pinkyDeltaY;
        pinkyX = (proposedPinkyX >= 0 && proposedPinkyX < 20) ? proposedPinkyX : pinkyX;
        pinkyY = (proposedPinkyY >= 0 && proposedPinkyY < 10) ? proposedPinkyY : pinkyY;

        // --- Blinky Logic ---
        blinkyState = (blinkyX == 19 && blinkyDirection == 1 && blinkyY == 3) ? 1 : 
                      ((blinkyX == 0 && blinkyDirection == -1 && blinkyY == 6) ? 0 : blinkyState);
                      
        blinkyY = (blinkyState == 1 && blinkyY == 3 && blinkyX == 19) ? 6 :
                  ((blinkyState == 0 && blinkyY == 6 && blinkyX == 0) ? 3 : blinkyY);
                  
        blinkyDirection = (blinkyX == 19 && blinkyDirection == 1) ? -1 :
                          ((blinkyX == 0 && blinkyDirection == -1) ? 1 : blinkyDirection);
                          
        blinkyX = blinkyX + blinkyDirection;
    }

    cout << "\nGame execution finished successfully.\n";
    return 0;
}