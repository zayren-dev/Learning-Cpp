#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int choice;
    cout << "Choose a question (1-8), or 0 to exit:" << endl;
    cout << "1. Question 1" << endl;
    cout << "2. Question 2" << endl;
    cout << "3. Question 3" << endl;
    cout << "4. Question 4" << endl;
    cout << "5. Question 5" << endl;
    cout << "6. Question 6" << endl;
    cout << "7. Question 7" << endl;
    cout << "8. Question 8" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            
        break;

     case 2:
            
    double windSpeed, slopeAngle, dryness;
    long long lastfour_digits;
    cout << " Enter the wind speed (U): ";
    cin >> windSpeed;
    cout << " Enter the slope angle in radians (Θ): ";
    cin >> slopeAngle;
    cout << " Enter the dryness (D): ";
    cin >> dryness;
    cout << " Enter the last four digits of your roll no: ";
    cin >> lastfour_digits;

    const double w_knot = 0.8;
    const double beta = 0.12;
    const double u_knot = 15.0;
    const double miu = 3.4;
    const double d_knot = 0.5;
    // finding the delta_velocity using the formula
    double delta_velocity = w_knot * exp(beta * windSpeed) + u_knot * sin(slopeAngle) * sin(slopeAngle)
                    + miu * log((dryness + 1.0) / d_knot)
                    + sqrt(windSpeed) * cos(slopeAngle) + 1.0;

    // extracting the parts
    int v_int = static_cast<int>(delta_velocity);  //truncates the decimal part       
    double fractional = delta_velocity - v_int;             
    int F1 = static_cast<int>(fractional * 100); // it will give 1st two        
    int F2 = static_cast<int>((fractional * 100 - F1) * 100); // it will give last twwo

    // finding R
    int rolloffset_R = static_cast<int>((lastfour_digits % 89) + 10);

    // finding K
    long long telemetryKey_K = (v_int * 1000000LL) + (F1 * 10000LL) + (F2 * 100LL) + rolloffset_R;

    // synthesizing status_tags
    int recoveredR = static_cast<int>(telemetryKey_K % 100);
    char first_tag  = static_cast<char>('A' + (v_int % 26));
    char second_tag = static_cast<char>('Z' - (recoveredR % 26));

    // reconstructing original velocity from parsed components
    float  vFloat  = v_int + F1 / 100.0f + F2 / 10000.0f;
    double vDouble = v_int + F1 / 100.0  + F2 / 10000.0;

    // precision match indicator
    int exactmatch = static_cast<int>(vFloat == vDouble);

    int penalty = 25 * (1 - exactmatch);
    int threat = static_cast<int>(recoveredR + penalty + 1.5 * vDouble);
    // output
    cout << fixed << setprecision(4);
    cout << "ΔV: " << delta_velocity << endl;
    cout << "Telemetry Key K: " << telemetryKey_K << endl;
    cout << "Status Tag: " << first_tag << second_tag << endl;
    cout << "Precision Match Flag: " << exactmatch << endl;
    cout << "Threat Rating: " << threat << endl;

    break;

        case 3:
            
            break;

        case 4:
            
            break;

        case 5:
            
            break;

        case 6:
           
            break;

        case 7:
           
            break;

        case 8:
            
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please select a number from 0 to 8." << endl;
            break;
    }

    return 0;
}
