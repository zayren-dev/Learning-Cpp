#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
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

    switch (choice) {
    case 1:
    {
    
    char type;
    int game, time_left, guard_alert, injuries;
    int lights_on, cameras;
    int take_needles, needles;
    int take_bandages, bandages;
    int take_marbles, marbles;
    int take_rope, ropeM;
    int pack_kg, stamina, players_left;
    int bet, stake, favor;
    int cash, debt, card, ally;

    cout << "Enter type (A/T/G): ";
    cin >> type; 
    cout << "Enter game (1-5): ";
    cin >> game;
    cout << "Enter timeLeft (0-120): ";
    cin >> time_left;
    cout << "Enter guardAlert (0-100): ";
    cin >> guard_alert;
    cout << "Enter injuries (0-3): ";
    cin >> injuries;
    cout << "Enter lightsOn (0/1): ";
    cin >> lights_on;
    cout << "Enter cameras (0/1): ";
    cin  >> cameras;
    cout << "Enter takeNeedles (0/1): ";
    cin >> take_needles ;
    cout << "Enter needles (0-40): ";
    cin  >> needles;
    cout << "Enter takeBandages (0/1): ";
    cin >> take_bandages;
    cout << "Enter bandages (0-30): ";
    cin >> bandages;
    cout << "Enter takeMarbles (0/1): ";
    cin >> take_marbles;
    cout << "Enter marbles (0-100): ";
    cin  >> marbles;
    cout << "Enter takeRope (0/1): ";
    cin >> take_rope;
    cout << "Enter ropeM (0-60): ";
    cin >> ropeM;
    cout << "Enter packKg (0-150): ";
    cin >> pack_kg;
    cout << "Enter stamina (0-100): ";
    cin  >> stamina;
    cout << "Enter playersLeft (2-456): ";
    cin  >> players_left;
    cout << "Enter bet (0/1/2): ";
    cin >> bet;
    cout << "Enter stake (0-2000): ";
    cin >> stake ;
    cout << "Enter favor (0-3): ";
    cin  >> favor;
    cout << "Enter cash (0-6000): ";
    cin >> cash;
    cout << "Enter debt (0-3000): ";
    cin >> debt;
    cout << "Enter card (0/1): ";
    cin >> card;
    cout << "Enter ally (0/1): ";
    cin  >> ally;

    int pass = 1;
    pass = (type == 'A' || type == 'T' || type == 'G') ? pass : 0;
    pass = (game >= 1 && game <= 5) ? pass : 0;
    pass = (time_left >= 0 && time_left <= 120) ? pass : 0;
    pass = (guard_alert >= 0 && guard_alert <= 100) ? pass : 0;
    pass = (injuries >= 0 && injuries <= 3) ? pass : 0;
    pass = (lights_on == 0 || lights_on == 1) ? pass : 0;
    pass = (cameras == 0 || cameras == 1) ? pass : 0;
    pass = (take_needles == 0 || take_needles == 1) ? pass : 0;
    pass = (needles >= 0 && needles <= 40) ? pass : 0;
    pass = (take_bandages == 0 || take_bandages == 1) ? pass : 0;
    pass = (bandages >= 0 && bandages <= 30) ? pass : 0;
    pass = (take_marbles == 0 || take_marbles == 1) ? pass : 0;
    pass = (marbles >= 0 && marbles <= 100) ? pass : 0;
    pass = (take_rope == 0 || take_rope == 1) ? pass : 0;
    pass = (ropeM >= 0 && ropeM <= 60) ? pass : 0;
    pass = (pack_kg >= 0 && pack_kg <= 150) ? pass : 0;
    pass = (stamina >= 0 && stamina <= 100) ? pass : 0;
    pass = (players_left >= 2 && players_left <= 456) ? pass : 0;
    pass = (bet >= 0 && bet <= 2) ? pass : 0;
    pass = (bet == 0 || (stake >= 0 && stake <= 2000)) ? pass : 0;
    pass = (favor >= 0 && favor <= 3) ? pass : 0;
    pass = (cash >= 0 && cash <= 6000) ? pass : 0;
    pass = (debt >= 0 && debt <= 3000) ? pass : 0;
    pass = (card == 0 || card == 1) ? pass : 0;
    pass = (ally == 0 || ally == 1) ? pass : 0;
    pass ? 0 : (cout << "Invalid input" << endl, exit(0), 0);

    int Baseprice_needle = 150;
    Baseprice_needle = (type == 'T') ? 120 : Baseprice_needle;
    
    int Baseprice_bandage = 350;

    int Baseprice_marble = 60;
    Baseprice_marble = (type == 'G') ? 45 : Baseprice_marble;

    int Baseprice_rope = 120;
    Baseprice_rope = (type == 'A') ? 100 : Baseprice_rope;

   int NeedleCost = 0;
   NeedleCost = (take_needles == 0) ? 0 : (needles <= 10) ? needles * Baseprice_needle : (10 * Baseprice_needle) + (needles - 10) * ((Baseprice_needle * 75) / 100);

   int MarbleCost = 0;
   MarbleCost = (take_marbles == 0) ? 0 : ((marbles <= 50) ? marbles * Baseprice_marble : (50 * Baseprice_marble) + (marbles - 50) * ((Baseprice_marble * 50) / 100));

   int BandageCost = 0;
   BandageCost = (take_bandages == 0) ? 0 :  (bandages - bandages / 3) * Baseprice_bandage;

   int RopeCost = 0;
   RopeCost = (take_rope ==0 ) ? 0: ropeM * Baseprice_rope;

   int alertAdj = guard_alert;
   alertAdj = alertAdj + (take_marbles ? marbles / 5 : 0);
   alertAdj = alertAdj + (take_rope ? ropeM / 3 : 0);
   alertAdj = alertAdj + (lights_on ? 10 : 0);
   alertAdj = alertAdj + (cameras ? 5 : 0);
   alertAdj = (alertAdj > 100) ? 100 : alertAdj; 

   int crowdPts = (players_left > 300) ? 3 : (players_left > 150) ? 2 : (players_left > 50) ? 1 : 0;
   int alertPts = (alertAdj >= 70) ? 2 : (alertAdj >= 40) ? 1 : 0;
   int gamePts = (game >= 4) ? 2 : (game >= 2) ? 1 : 0;
   int camerasPts = cameras ? 1 : 0;
   int darknessPts = lights_on ? 0 : -1;
   int DangerPoints = crowdPts + alertPts + gamePts + camerasPts + darknessPts;
   DangerPoints = (DangerPoints < 0) ? 0 : DangerPoints;

   int surchargePct = (DangerPoints >= 7) ? 50 : (DangerPoints >= 5) ? 25 : (DangerPoints >= 3) ? 10 : 0;
   // gonna declare new same name variables because we need original ones as output so we can't change 
   int NeedleS = (NeedleCost * (100 + surchargePct)) / 100;
   int BandageS = (BandageCost * (100 + surchargePct)) / 100;
   int MarbleS = (MarbleCost * (100 + surchargePct)) / 100;
   int RopeS = (RopeCost * (100 + surchargePct)) / 100;
   int itemsAfterSurcharge = NeedleS + BandageS + MarbleS + RopeS;
   int lateFee = (time_left < 15) ? 250 : (time_left < 45) ? 100 : 0;
   int guardToll = 50 + (alertAdj / 10) * 5;
   guardToll = (card == 1 && cameras == 0) ? 0 : guardToll;

   int carryBase = (type == 'A') ? 40 : (type == 'T') ? 30 : 35;
   int carryCap = carryBase + (ally ? 10 : 0);

   int overweight = (pack_kg > carryCap) ? pack_kg - carryCap : 0; // calculates the over weight for the weight penalty
   int weightPenalty = (25 * overweight > 500) ? 500 : 25 * overweight; // calculating the weight penlaty using the above over weight
   int wager = (bet != 0) ? stake : 0; 
   int allyRebate = ally ? 60 : 0;
   int calmRebate = (injuries == 0 && stamina >= 70) ? 40 : 0;
   int injuryTax = (injuries == 0) ? 0 : (injuries == 1) ? 30 : (injuries == 2) ? 90 : 200;
   
   int favorDiscount = 0;
   int insider = ((NeedleS + MarbleS) * 15 / 100> 500) ? 500 : (NeedleS + MarbleS) * 15 / 100;
   favorDiscount = (favor == 1 && (game == 2 || game == 4)) ? insider : favorDiscount;
   int hush = (lateFee + guardToll) * 50 / 100;
   hush = (hush > 250) ? 250 : hush;
   favorDiscount = (favor == 2 && alertAdj >= 60) ? hush : favorDiscount;
   int medpass = BandageS * 35 / 100;
   medpass = (medpass > 900) ? 900 : medpass;
   favorDiscount = (favor == 3 && injuries >= 1) ? medpass : favorDiscount;

   int gross = itemsAfterSurcharge + lateFee + guardToll + weightPenalty + wager;
   int net = gross + injuryTax - allyRebate - calmRebate - favorDiscount;
   net = (net < 0) ? 0 : net;
   int debtFee = (net > cash) ? (80 + debt / 20) : 0;
   int total = net + debtFee; total = (total < 200) ? 200 : total;
   int fees = lateFee + guardToll + weightPenalty + injuryTax + debtFee;
   int cashUsed = (cash < total) ? cash : total;
   int payable = total - cashUsed;

   int survival_Chance = 40;
   survival_Chance += (take_rope == 1) ? ((ropeM / 2 > 15) ? 15 : ropeM / 2) : 0;
   survival_Chance += (take_bandages == 1) ? ((2 * bandages > 12) ? 12 : 2 * bandages) : 0;
   survival_Chance += stamina / 4;
   survival_Chance += (card == 1) ? 8 : -25;
   survival_Chance += (ally == 1) ? 5 : 0;
   survival_Chance -= overweight / 2;
   survival_Chance -= 5 * (surchargePct / 10);
   survival_Chance -= 8 * injuries;
   survival_Chance -= 4 * (game - 1);
   survival_Chance -= (debtFee > 0) ? 12 : 0;

   int itemBonus = (game == 2 && take_needles == 1 && needles >= 5) ? 10 : (game == 4 && take_marbles == 1 && marbles >= 20) ? 10 : (game == 5 && take_rope == 1 && ropeM >= 10) ? 10 : 0;
   survival_Chance += itemBonus;
   survival_Chance = (survival_Chance < 0) ? 0 : (survival_Chance > 100) ? 100 : survival_Chance;
   int survived = (survival_Chance >= 55) ? 1 : 0;
  
   int prizePool = (456 - players_left) * 100;
   int PrizeShare = survived ? (prizePool / players_left) : 0;

   int BetPayout = 0;
   BetPayout = (survived && bet == 1) ? (stake * 3) / 2 : BetPayout;
   BetPayout = (survived && bet == 2) ? ((survival_Chance >= 75) ? stake * 4 : 0) : BetPayout;

   int FinalBalance = cash - total + PrizeShare + BetPayout;
    cout << "NeedleCost=" << NeedleCost << endl;
    cout << "BandageCost=" << BandageCost << endl;
    cout << "MarbleCost=" << MarbleCost << endl;
    cout << "RopeCost=" << RopeCost << endl;
    cout << "DangerPoints=" << DangerPoints << endl;
    cout << "SurchargePct=" << surchargePct << "%" << endl;
    cout << "LateFee=" << lateFee << endl;
    cout << "GuardToll=" << guardToll << endl;
    cout << "WeightPenalty=" << weightPenalty << endl;
    cout << "Wager=" << wager << endl;
    cout << "FavorDiscount=" << favorDiscount << endl;
    cout << "Fees=" << fees << endl;
    cout << "Total=" << total << endl;
    cout << "CashUsed=" << cashUsed << endl;
    cout << "Payable=" << payable << endl;
    cout << "SurvivalChance=" << survival_Chance << endl;
    cout << "Outcome=" << (survived ? "Survived" : "Eliminated") << endl;
    cout << "PrizeShare=" << PrizeShare << endl;
    cout << "BetPayout=" << BetPayout << endl;
    cout << "FinalBalance=" << FinalBalance << endl;
    }
    break;

    case 2:
    {
            
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

    double w_knot = 0.8;
    double beta = 0.12;
    double u_knot = 15.0;
    double miu = 3.4;
    double d_knot = 0.5;
    // finding the delta_velocity using the given formula
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
    cout << "Threat Rating: " << threat << endl; }

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
