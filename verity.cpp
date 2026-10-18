#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int radius;
    cout << "Initialize Silent Containment Matrix Radius (e.g., 8, 12, 16): ";
    cin >> radius;
    cout << endl;

    // ---------- every measurement grows from the one number the user typed ----------
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

    // face measurements (in "real" units, one unit = 2 columns or 1 row)
    double ringRadius   = radius / 2.0;
    double strokeHalf   = 0.25 + radius / 24.0;       // half of the stroke thickness
    double eyeOffset    = radius * 5 / 24.0;          // how far each eye sits from the centre line
    int    eyeHeight    = radius / 4;                 // how many rows each eye climbs above the middle
    double mouthCentreY = radius / 3.0;
    double mouthRadius  = radius * 3 / 16.0;
    double smileRadius  = ringRadius + 2.5;

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
                double u = x / 2.0;                                   // columns are half as wide as rows are tall
                double distFromCentre = sqrt(u * u + (double)y * y);
                double distFromMouth  = sqrt(u * u + (y - mouthCentreY) * (y - mouthCentreY));

                bool onFaceRing = fabs(distFromCentre - ringRadius) <= strokeHalf;
                bool onEye      = (fabs(fabs(u) - eyeOffset) <= strokeHalf) && (y >= -eyeHeight) && (y <= 0);
                bool onMouth    = fabs(distFromMouth - mouthRadius) <= strokeHalf;
                bool onSmile    = (y >= 1) && (y <= smileRadius - 1)
                                  && (fabs(distFromCentre - smileRadius) <= 0.5)
                                  && ((x + y) % 2 == 0);

                if (onFaceRing || onEye || onMouth || onSmile)
                {
                    symbol = '#';
                    colour = 91;
                }
                else if ((x + y) % 2 == 0)
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