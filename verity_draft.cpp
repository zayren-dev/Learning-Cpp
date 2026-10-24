#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int radius;
    cout << "\033[96mInitialize Silent Containment Matrix Radius (e.g., 8, 12, 16): \033[0m";
    cin >> radius;
    cout << endl;

    // every measurement grows from the one number the user typed 
    int halfHeight    = radius * 3 / 2;               // rows above and below the middle row
    int reachSideways = 3 * radius;                   // how far the middle line stretches left / right
    int diamondLimit  = 3 * radius + 1;               // |x| + 2|y| must stay inside this to be in the diamond
    int wallPosition  = radius * 7 / 4;               // column of the straight vertical walls
    int wallThickness = radius / 4 - 1;               // width of those walls
    int whiteBand     = 2 * (radius / 8) + 1;         // width of the white slanted border
    int cyanBand      = 2 * ((radius + 4) / 12) + 1;  // width of the cyan strip next to it
    int leftMargin    = 3 * radius;                   // blank space before every row

    if (wallThickness < 1)
        wallThickness = 1;

    int whiteStart = diamondLimit - whiteBand + 1;    // slanted distance where white begins
    int cyanStart  = whiteStart - cyanBand;           // slanted distance where cyan begins

    for (int y = -halfHeight; y <= halfHeight; y++)
    {
        for (int pad = 0; pad < leftMargin; pad++)
            cout << ' ';

        for (int x = -reachSideways; x <= reachSideways; x++)
        {
            int sideDistance = abs(x);
            int rowDistance  = abs(y);
            int slant        = sideDistance + 2 * rowDistance;

            char symbol = ' ';
            int  colour = 0;

            // the hexagon is the diamond with its left and right tips cut off by vertical walls
            bool insideHexagon = (slant <= diamondLimit) && (sideDistance <= wallPosition);
            bool onWhiteSlope  = insideHexagon && (slant >= whiteStart);
            bool onWhiteWall   = insideHexagon && (sideDistance > wallPosition - wallThickness);

            // the cyan rhombus: a strip along the same slanted edges plus the long middle line
            bool onCyanStrip   = (slant >= cyanStart) && (slant <= whiteStart);
            bool onMiddleLine  = (y == 0) && (sideDistance > wallPosition);

            if (onWhiteSlope || onWhiteWall)
            {
                symbol = 'X';
                colour = 97;
            }
            else if (onCyanStrip || onMiddleLine)
            {
                symbol = '+';
                colour = 96;
            }
            else if (insideHexagon)
            {
                if ((x + y) % 2 == 0)
                {
                    symbol = '.';
                    colour = 90;
                }
            }

            cout << "\033[" << colour << "m" << symbol;
        }
        cout << "\033[0m" << endl;
    }

    return 0;
}