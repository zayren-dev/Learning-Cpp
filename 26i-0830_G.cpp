#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
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
    
        char type = 'A';
    int game = 1, time_left = 0, guard_alert = 0, injuries = 0;
    int lights_on = 0, cameras = 0;
    int take_needles = 0, needles = 0;
    int take_bandages = 0, bandages = 0;
    int take_marbles = 0, marbles = 0;
    int take_rope = 0, ropeM = 0;
    int pack_kg = 0, stamina = 0, players_left = 2;
    int bet = 0, stake = 0, favor = 0;
    int cash = 0, debt = 0, card = 0, ally = 0;
    int pass = 1;

    pass && (cout << "Enter type (A/T/G): ") && (cin >> type);
    pass = (pass && (type == 'A' || type == 'T' || type == 'G')) ? 1 : 0;
    pass && (cout << "Enter game (1-5): ") && (cin >> game);
    pass = (pass && game >= 1 && game <= 5) ? 1 : 0;
    pass && (cout << "Enter timeLeft (0-120): ") && (cin >> time_left);
    pass = (pass && time_left >= 0 && time_left <= 120) ? 1 : 0;
    pass && (cout << "Enter guardAlert (0-100): ") && (cin >> guard_alert);
    pass = (pass && guard_alert >= 0 && guard_alert <= 100) ? 1 : 0;
    pass && (cout << "Enter injuries (0-3): ") && (cin >> injuries);
    pass = (pass && injuries >= 0 && injuries <= 3) ? 1 : 0;
    pass && (cout << "Enter lightsOn (0/1): ") && (cin >> lights_on);
    pass = (pass && (lights_on == 0 || lights_on == 1)) ? 1 : 0;
    pass && (cout << "Enter cameras (0/1): ") && (cin >> cameras);
    pass = (pass && (cameras == 0 || cameras == 1)) ? 1 : 0;
    pass && (cout << "Enter takeNeedles (0/1): ") && (cin >> take_needles);
    pass = (pass && (take_needles == 0 || take_needles == 1)) ? 1 : 0;
    pass && (cout << "Enter needles (0-40): ") && (cin >> needles);
    pass = (pass && needles >= 0 && needles <= 40) ? 1 : 0;
    pass && (cout << "Enter takeBandages (0/1): ") && (cin >> take_bandages);
    pass = (pass && (take_bandages == 0 || take_bandages == 1)) ? 1 : 0;
    pass && (cout << "Enter bandages (0-30): ") && (cin >> bandages);
    pass = (pass && bandages >= 0 && bandages <= 30) ? 1 : 0;
    pass && (cout << "Enter takeMarbles (0/1): ") && (cin >> take_marbles);
    pass = (pass && (take_marbles == 0 || take_marbles == 1)) ? 1 : 0;
    pass && (cout << "Enter marbles (0-100): ") && (cin >> marbles);
    pass = (pass && marbles >= 0 && marbles <= 100) ? 1 : 0;
    pass && (cout << "Enter takeRope (0/1): ") && (cin >> take_rope);
    pass = (pass && (take_rope == 0 || take_rope == 1)) ? 1 : 0;
    pass && (cout << "Enter ropeM (0-60): ") && (cin >> ropeM);
    pass = (pass && ropeM >= 0 && ropeM <= 60) ? 1 : 0;
    pass && (cout << "Enter packKg (0-150): ") && (cin >> pack_kg);
    pass = (pass && pack_kg >= 0 && pack_kg <= 150) ? 1 : 0;
    pass && (cout << "Enter stamina (0-100): ") && (cin >> stamina);
    pass = (pass && stamina >= 0 && stamina <= 100) ? 1 : 0;
    pass && (cout << "Enter playersLeft (2-456): ") && (cin >> players_left);
    pass = (pass && players_left >= 2 && players_left <= 456) ? 1 : 0;
    pass && (cout << "Enter bet (0/1/2): ") && (cin >> bet);
    pass = (pass && bet >= 0 && bet <= 2) ? 1 : 0;
    pass && (cout << "Enter stake (0-2000): ") && (cin >> stake);
    pass = (pass && (bet == 0 || (stake >= 0 && stake <= 2000))) ? 1 : 0;
    pass && (cout << "Enter favor (0-3): ") && (cin >> favor);
    pass = (pass && favor >= 0 && favor <= 3) ? 1 : 0;
    pass && (cout << "Enter cash (0-6000): ") && (cin >> cash);
    pass = (pass && cash >= 0 && cash <= 6000) ? 1 : 0;
    pass && (cout << "Enter debt (0-3000): ") && (cin >> debt);
    pass = (pass && debt >= 0 && debt <= 3000) ? 1 : 0;
    pass && (cout << "Enter card (0/1): ") && (cin >> card);
    pass = (pass && (card == 0 || card == 1)) ? 1 : 0;
    pass && (cout << "Enter ally (0/1): ") && (cin >> ally);
    pass = (pass && (ally == 0 || ally == 1)) ? 1 : 0;

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
   int PrizeShare = survived ? (prizePool / (players_left < 2 ? 2 : players_left)) : 0;

   int BetPayout = 0;
   BetPayout = (survived && bet == 1) ? (stake * 3) / 2 : BetPayout;
   BetPayout = (survived && bet == 2) ? ((survival_Chance >= 75) ? stake * 4 : 0) : BetPayout;

   int FinalBalance = cash - total + PrizeShare + BetPayout;
    NeedleCost      *= pass;
    BandageCost     *= pass;
    MarbleCost      *= pass;
    RopeCost        *= pass;
    DangerPoints    *= pass;
    surchargePct    *= pass;
    lateFee         *= pass;
    guardToll       *= pass;
    weightPenalty   *= pass;
    wager           *= pass;
    favorDiscount   *= pass;
    fees            *= pass;
    total           *= pass;
    cashUsed        *= pass;
    payable         *= pass;
    survival_Chance *= pass;
    PrizeShare      *= pass;
    BetPayout       *= pass;
    FinalBalance    *= pass;
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
    cout << "Outcome=" << (pass ? (survived ? "Survived" : "Eliminated") : "Invalid") << endl;
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
                    + miu * log((dryness + 1.0) / d_knot) + sqrt(windSpeed * cos(slopeAngle) + 1.0);;

    // extracting the parts
    delta_velocity = round(delta_velocity * 10000.0) / 10000.0;
    int v_int = static_cast<int>(delta_velocity);
    int F1 = static_cast<int>(round(delta_velocity * 10000)) / 100 % 100;
    int F2 = static_cast<int>(round(delta_velocity * 10000)) % 100;

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

    case 4: {
    int size;
    cout << "Enter size: ";
    cin >> size;
    for (int row = 0; row < size; row++)
    {
      for (int column = 0; column < size; column++)
        {
         if (row <= size / 2 && column <= size / 2)
            { if (row == 0 || column == 0)
                  cout << "* ";
              else if (row % 2 == 0 && column <= row)
                  cout << "* ";
              else if (column % 2 == 0 && row <= column)
                  cout << "* ";
              else
                  cout << "  ";
            }
            
        else if (row <= size / 2 && column > size / 2)
            {
              if (row == 0 || column == size - 1)
                  cout << "* ";
              else if (row % 2 == 0 && size - 1 - column <= row)
                  cout << "* ";
              else if ((size - 1 - column) % 2 == 0 && row <= size - 1 - column)
                  cout << "* ";
              else
                  cout << "  ";
            }
        else if (row > size / 2 && column <= size / 2)
            {
              if (row == size - 1 || column == 0)
                  cout << "* ";
              else if ((size - 1 - row) % 2 == 0 && column <= size - 1 - row)
                  cout << "* ";
              else if (column % 2 == 0 && size - 1 - row <= column)
                  cout << "* ";
              else
                  cout << "  ";
            }
        else
            {
              if (row == size - 1 || column == size - 1)
                    cout << "* ";
              else if ((size - 1 - row) % 2 == 0 && size - 1 - column <= size - 1 - row)
                    cout << "* ";
              else if ((size - 1 - column) % 2 == 0 && size - 1 - row <= size - 1 - column)
                    cout << "* ";
              else
                    cout << "  ";
            }
        }
        cout << endl;}}
    break;

    case 5:{
    int choice5;
    cout << " Choose which part you want 1 for A or 2 for B ";
    cin >> choice5;
    switch (choice5) {
    case 1: {
        cout << " -----PART A----- ";
        // part A ki jagah idhr h
        break;
    }
    case 2: {
        // part B idher (thomas and the tank)
        cout << " -----PART B-----" << endl;
        int trainCode;
        cout << "Enter a 4-digit number:  ";
        cin >> trainCode;

    
        if (trainCode < 1000 || trainCode > 9999) {
            cout << "Invalid input! Please enter a 4-digit integer." << endl;
            return 0;
        }

        int c1 = trainCode / 1000;         
        int c2 = (trainCode / 100) % 10;   
        int c3 = (trainCode / 10) % 10;    
        int c4 = trainCode % 10;           

        // Har digit 1 se 4 ke beech hona chahiye
        if ((c1 < 1 || c1 > 4) || (c2 < 1 || c2 > 4) ||
            (c3 < 1 || c3 > 4) || (c4 < 1 || c4 > 4)) {
            cout << "Invalid compartment ID! Digits must only be 1, 2, 3, or 4." << endl;
            return 0;
        }

        
        for (int line = 1; line <= 6; line++) {

            for (int pos = 1; pos <= 4; pos++) {

                int car = 0;
                if (pos == 1)      car = c1;
                else if (pos == 2) car = c2;
                else if (pos == 3) car = c3;
                else if (pos == 4) car = c4;

                if (line == 1) {
                    if (car == 1)      cout << "  o O           ";  
                    else               cout << "              ";   
                }
               
                else if (line == 2) {
                    if (car == 1)      cout << "  _[]_  ________";   
                    else if (car == 2) cout << " ____________ ";     
                    else if (car == 3) cout << "|============|";     
                    else if (car == 4) cout << "    _[__]_    ";     
                }
                
                else if (line == 3) {
                    if (car == 1)      cout << " |____|_|[]  []|";   
                    else if (car == 2) cout << "|[] [] [] [] |";     
                    else if (car == 3) cout << "|  |  []  |  |"; 
                    else if (car == 4) cout << " .-========-. ";    
                }
                
                else if (line == 4) {
                    if (car == 1)      cout << " |_()_|_|______|";  
                    else if (car == 2) cout << "|[] [] [] [] |";    
                    else if (car == 3) cout << "|  |  ||  |  |";    
                    else if (car == 4) cout << "(  ~~~~~~~~  )";  
                }
                
                else if (line == 5) {
                    if (car == 1)      cout << "<==============]";  
                    else if (car == 2) cout << "|____________|";     
                    else if (car == 3) cout << "|__|__||__|__|";    
                    else if (car == 4) cout << " '-========-' ";     
                }
                
                else if (line == 6) {
                    if (car == 1)      cout << " (O)(O) (O)(O)  ";   
                    else if (car == 2) cout << " (O)      (O) ";     
                    else if (car == 3) cout << "  (O)    (O)  ";
                    else if (car == 4) cout << "  (O)    (O)  ";      
                }

                if (pos < 4) {
                    if (line == 5) {
                        if (car == 2) cout << "-";
                        else          cout << "--";
                    } else {
                        if (car == 2) cout << " ";
                        else          cout << "  ";}}}
        cout << "\n";}
        break;}}}
 case 6:
break;

        case 7:
           {
    long long numA, numB;
    char choice;

    cout << "Input A : ";
    cin >> numA;
    cout << "Input B : ";
    cin >> numB;
    cout << "Are these numbers signed or unsigned? Y/N : ";
    cin >> choice;
    bool isSigned = (choice == 'Y' || choice == 'y');

    cout << "... Calculating ..." << endl;

    int zero = 0; 
    int signA = (numA / 100000) % 10;
    int signB = (numB / 100000) % 10;

    long long a7 = numA;
    long long b7 = numB;
    if (isSigned && signA == 1) a7 = numA + 1000000;
    if (isSigned && signB == 1) b7 = numB + 1000000;

    long long sumBits = 0, diff1Bits = 0, diff2Bits = 0;
    bool sumOverflow = false, diff1Overflow = false, diff2Overflow = false;

    for (int round = 1; round <= 3; round++) {

        long long first = a7, second = b7;
        if (round == 3) { first = b7; second = a7; }

        long long result = 0;
        long long place = 1;   
        int carryOrBorrow = 0;    

        for (int column = 0; column < 7; column++) {
            int bit1 = (first / place) % 10;
            int bit2 = (second / place) % 10;
            int answerBit;

            if (round == 1) {
                int total = bit1 + bit2 + carryOrBorrow;
                answerBit = total % 2;         
                carryOrBorrow = total / 2;} 
                else {
                int total = bit1 - bit2 - carryOrBorrow;
                if (total < 0) {                
                    total = total + 2;
                    carryOrBorrow = 1;
                } else {
                    carryOrBorrow = 0;
                }
                answerBit = total;}
            result = result + answerBit * place;
            place = place * 10; }

        int bit6 = (result / 1000000) % 10;
        int bit5 = (result / 100000) % 10;
        bool overflow;
        if (isSigned) overflow = (bit6 != bit5);  
        else          overflow = (bit6 == 1);   

        if (round == 1)      { sumBits = result;   sumOverflow = overflow; }
        else if (round == 2) { diff1Bits = result; diff1Overflow = overflow; }
        else                 { diff2Bits = result; diff2Overflow = overflow; }}

    long long shiftedA = numA;   
    long long bigB = numB;     
    if (isSigned && signA == 1) {
        long long fillPlace = 1000000;
        for (int i = 6; i < 12; i++) { shiftedA = shiftedA + fillPlace; fillPlace = fillPlace * 10; }}
    if (isSigned && signB == 1) {
        long long fillPlace = 1000000;
        for (int i = 6; i < 12; i++) { bigB = bigB + fillPlace; fillPlace = fillPlace * 10; }}

    long long product = 0;
    long long bPlace = 1;  

    for (int round = 0; round < 12; round++) {

        if ((bigB / bPlace) % 10 == 1) {
            long long newProduct = 0;
            long long place = 1;
            int carry = 0;
            for (int column = 0; column < 12; column++) {
                int total = (product / place) % 10 + (shiftedA / place) % 10 + carry;
                newProduct = newProduct + (total % 2) * place;
                carry = total / 2;
                place = place * 10;}
            product = newProduct;}
        shiftedA = (shiftedA * 10) % 1000000000000LL;
        bPlace = bPlace * 10;}
    long long quotient = 0, remainder = 0;
    bool divideByZero = (numB == 0);

    if (!divideByZero) {

        long long absA = numA, absB = numB;
        bool aNegative = false, bNegative = false;
        for (int who = 1; who <= 2; who++) {
            long long original = numA;
            int originalSign = signA;
            if (who == 2) { original = numB; originalSign = signB; }

            if (isSigned && originalSign == 1) {
                long long negated = 0, place = 1;
                int carry = 1;
                for (int column = 0; column < 6; column++) {
                    int total = (1 - (original / place) % 10) + carry;
                    negated = negated + (total % 2) * place;
                    carry = total / 2;
                    place = place * 10;}
                if (who == 1) { absA = negated; aNegative = true; }
                else          { absB = negated; bNegative = true; }}}
        remainder = absA;
        while (remainder >= absB) {
            long long smaller = 0, place = 1;
            int borrow = 0;
            for (int column = 0; column < 6; column++) {
                int total = (remainder / place) % 10 - (absB / place) % 10 - borrow;
                if (total < 0) { total = total + 2; borrow = 1; }
                else           { borrow = 0; }
                smaller = smaller + total * place;
                place = place * 10;}
            remainder = smaller;
            long long bigger = 0;
            place = 1;
            int carry = 1;
            for (int column = 0; column < 6; column++) {
                int total = (quotient / place) % 10 + carry;
                bigger = bigger + (total % 2) * place;
                carry = total / 2;
                place = place * 10;}
            quotient = bigger;}
        for (int who = 1; who <= 2; who++) {
            long long toFix = quotient;
            bool needsNegate = (aNegative != bNegative);
            if (who == 2) {
                toFix = remainder;
                needsNegate = aNegative;}
            if (needsNegate) {
                long long negated = 0, place = 1;
                int carry = 1;
                for (int column = 0; column < 6; column++) {
                    int total = (1 - (toFix / place) % 10) + carry;
                    negated = negated + (total % 2) * place;
                    carry = total / 2;
                    place = place * 10;}
                if (who == 1) quotient = negated;
                else          remainder = negated;}}}
    int decA = 0, decB = 0, decSum = 0, decDiff1 = 0;
    int decDiff2 = 0, decProduct = 0, decQuotient = 0, decRemainder = 0;
    long long sumShown = 0, diff1Shown = 0, diff2Shown = 0;
    bool sumSeven = false, diff1Seven = false, diff2Seven = false;

    for (int item = 1; item <= 8; item++) {
        long long value = 0;
        int bits = 6;
        bool readSigned = isSigned; 

        if (item == 1) value = numA;
        else if (item == 2) value = numB;
        else if (item == 3) {
            if (sumOverflow) { value = sumBits; bits = 7; }
            else value = sumBits % 1000000;}
        else if (item == 4) {
            if (diff1Overflow) { value = diff1Bits; bits = 7; readSigned = true; }
            else value = diff1Bits % 1000000;}
        else if (item == 5) {
            if (diff2Overflow) { value = diff2Bits; bits = 7; readSigned = true; }
            else value = diff2Bits % 1000000;}
        else if (item == 6) { value = product; bits = 12; }
        else if (item == 7) value = quotient;
        else value = remainder;
        long long place = 1;
        for (int i = 0; i < bits - 1; i++) place = place * 10;
        int decimalValue = 0;
        int leftmostBit = 0;
        for (int i = 0; i < bits; i++) {
            int bit = (value / place) % 10;
            if (i == 0) leftmostBit = bit;
            decimalValue = decimalValue * 2 + bit;
            place = place / 10;}
        if (readSigned && leftmostBit == 1) {
            int range = 1;
            for (int i = 0; i < bits; i++) range = range * 2;
            decimalValue = decimalValue - range;}
        if (item == 1)      decA = decimalValue;
        else if (item == 2) decB = decimalValue;
        else if (item == 3) { decSum = decimalValue;   sumShown = value;   sumSeven = (bits == 7); }
        else if (item == 4) { decDiff1 = decimalValue; diff1Shown = value; diff1Seven = (bits == 7); }
        else if (item == 5) { decDiff2 = decimalValue; diff2Shown = value; diff2Seven = (bits == 7); }
        else if (item == 6) decProduct = decimalValue;
        else if (item == 7) decQuotient = decimalValue;
        else decRemainder = decimalValue;}
    cout << "A : " << decA << endl;
    cout << "B : " << decB << endl;
    cout << "A + B = ";
    if (sumSeven && sumShown < 1000000) cout << zero;
    if (sumShown < 100000) cout << zero;
    if (sumShown < 10000)  cout << zero;
    if (sumShown < 1000)   cout << zero;
    if (sumShown < 100)    cout << zero;
    if (sumShown < 10)     cout << zero;
    cout << sumShown << " = " << decSum;
    if (sumSeven) cout << "\toverflow detected, answer given in 7 bits" << endl;
    else          cout << "\tno overflow, so 6 bits" << endl;
    cout << "A - B = ";
    if (diff1Seven && diff1Shown < 1000000) cout << zero;
    if (diff1Shown < 100000) cout << zero;
    if (diff1Shown < 10000)  cout << zero;
    if (diff1Shown < 1000)   cout << zero;
    if (diff1Shown < 100)    cout << zero;
    if (diff1Shown < 10)     cout << zero;
    cout << diff1Shown << " = " << decDiff1;
    if (diff1Seven) cout << "\toverflow detected, answer given in 7 bits" << endl;
    else            cout << "\tno overflow, so 6 bits" << endl;
    cout << "B - A = ";
    if (diff2Seven && diff2Shown < 1000000) cout << zero;
    if (diff2Shown < 100000) cout << zero;
    if (diff2Shown < 10000)  cout << zero;
    if (diff2Shown < 1000)   cout << zero;
    if (diff2Shown < 100)    cout << zero;
    if (diff2Shown < 10)     cout << zero;
    cout << diff2Shown << " = " << decDiff2;
    if (diff2Seven) cout << "\toverflow detected, answer given in 7 bits" << endl;
    else            cout << "\tno overflow, so 6 bits" << endl;
    
    long long group1 = product / 100000000;       
    long long group2 = (product / 10000) % 10000; 
    long long group3 = product % 10000;          
    cout << "A * B = ";
    if (group1 < 1000) cout << zero;
    if (group1 < 100)  cout << zero;
    if (group1 < 10)   cout << zero;
    cout << group1 << " ";
    if (group2 < 1000) cout << zero;
    if (group2 < 100)  cout << zero;
    if (group2 < 10)   cout << zero;
    cout << group2 << " ";
    if (group3 < 1000) cout << zero;
    if (group3 < 100)  cout << zero;
    if (group3 < 10)   cout << zero;
    cout << group3 << " = " << decProduct << endl;

    if (divideByZero) {
        cout << "A / B = undefined (division by zero)" << endl;
        cout << "A % B = undefined (division by zero)" << endl;} 
        else {
        cout << "A / B = ";
        if (quotient < 100000) cout << zero;
        if (quotient < 10000)  cout << zero;
        if (quotient < 1000)   cout << zero;
        if (quotient < 100)    cout << zero;
        if (quotient < 10)     cout << zero;
        cout << quotient << " = " << decQuotient << endl;
        cout << "A % B = ";
        if (remainder < 100000) cout << zero;
        if (remainder < 10000)  cout << zero;
        if (remainder < 1000)   cout << zero;
        if (remainder < 100)    cout << zero;
        if (remainder < 10)     cout << zero;
        cout << remainder << " = " << decRemainder << endl;}}
            break;

        case 8: {}
            
        break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please select a number from 0 to 8." << endl;
            break;
    }

    return 0; }
