#include <iostream>
using namespace std;

int main() {
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

    // ============================================================
    long long sumBits = 0, diff1Bits = 0, diff2Bits = 0;
    bool sumOverflow = false, diff1Overflow = false, diff2Overflow = false;

    for (int round = 1; round <= 3; round++) {

        // choose which number comes first
        long long first = a7, second = b7;
        if (round == 3) { first = b7; second = a7; }

        long long result = 0;
        long long place = 1;       // 1, 10, 100... = which column we are on
        int carryOrBorrow = 0;     // carry when adding, borrow when subtracting

        // go through the 7 columns, right to left
        for (int column = 0; column < 7; column++) {
            int bit1 = (first / place) % 10;
            int bit2 = (second / place) % 10;
            int answerBit;

            if (round == 1) {
                // adding: two bits + carry
                int total = bit1 + bit2 + carryOrBorrow;
                answerBit = total % 2;           // bit we write
                carryOrBorrow = total / 2;       // carry to next column
            } else {
                // subtracting: first - second - borrow
                int total = bit1 - bit2 - carryOrBorrow;
                if (total < 0) {                 // can't take away, so borrow
                    total = total + 2;
                    carryOrBorrow = 1;
                } else {
                    carryOrBorrow = 0;
                }
                answerBit = total;
            }

            result = result + answerBit * place;
            place = place * 10;
        }

        // overflow check using the two leftmost bits of the 7-bit answer
        int bit6 = (result / 1000000) % 10;
        int bit5 = (result / 100000) % 10;
        bool overflow;
        if (isSigned) overflow = (bit6 != bit5);   // fits in 6 bits only if both are same
        else          overflow = (bit6 == 1);      // unsigned: went above 63 or below 0

        if (round == 1)      { sumBits = result;   sumOverflow = overflow; }
        else if (round == 2) { diff1Bits = result; diff1Overflow = overflow; }
        else                 { diff2Bits = result; diff2Overflow = overflow; }
    }

    // ============================================================
    // STEP 3: A * B  (shift and add, 12 bits)
    // ============================================================
    long long shiftedA = numA;   // A, moves one place left every round
    long long bigB = numB;       // B stretched to 12 bits

    // stretch to 12 bits: negative signed numbers get 1s in positions 6 to 11
    if (isSigned && signA == 1) {
        long long fillPlace = 1000000;
        for (int i = 6; i < 12; i++) { shiftedA = shiftedA + fillPlace; fillPlace = fillPlace * 10; }
    }
    if (isSigned && signB == 1) {
        long long fillPlace = 1000000;
        for (int i = 6; i < 12; i++) { bigB = bigB + fillPlace; fillPlace = fillPlace * 10; }
    }

    long long product = 0;
    long long bPlace = 1;   // which bit of B we are looking at

    for (int round = 0; round < 12; round++) {

        // if this bit of B is 1, add shiftedA into product (12-bit adder)
        if ((bigB / bPlace) % 10 == 1) {
            long long newProduct = 0;
            long long place = 1;
            int carry = 0;
            for (int column = 0; column < 12; column++) {
                int total = (product / place) % 10 + (shiftedA / place) % 10 + carry;
                newProduct = newProduct + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            product = newProduct;
        }

        // shift A one bit left (x10) and cut anything beyond 12 digits
        shiftedA = (shiftedA * 10) % 1000000000000LL;
        bPlace = bPlace * 10;
    }

    // ============================================================
    // STEP 4: A / B and A % B
    // make both positive, subtract again and again, then fix the signs
    // ============================================================
    long long quotient = 0, remainder = 0;
    bool divideByZero = (numB == 0);

    if (!divideByZero) {

        long long absA = numA, absB = numB;
        bool aNegative = false, bNegative = false;

        // 4a: make A (who = 1) and B (who = 2) positive if they are negative
        for (int who = 1; who <= 2; who++) {
            long long original = numA;
            int originalSign = signA;
            if (who == 2) { original = numB; originalSign = signB; }

            if (isSigned && originalSign == 1) {
                // negate = flip every bit, then add 1 (start with carry = 1)
                long long negated = 0, place = 1;
                int carry = 1;
                for (int column = 0; column < 6; column++) {
                    int total = (1 - (original / place) % 10) + carry;
                    negated = negated + (total % 2) * place;
                    carry = total / 2;
                    place = place * 10;
                }
                if (who == 1) { absA = negated; aNegative = true; }
                else          { absB = negated; bNegative = true; }
            }
        }

        // 4b: repeated subtraction. 0/1 numbers compare the same in
        // decimal and binary, so a normal >= works for "is it big enough?"
        remainder = absA;
        while (remainder >= absB) {

            // remainder = remainder - absB (with borrow)
            long long smaller = 0, place = 1;
            int borrow = 0;
            for (int column = 0; column < 6; column++) {
                int total = (remainder / place) % 10 - (absB / place) % 10 - borrow;
                if (total < 0) { total = total + 2; borrow = 1; }
                else           { borrow = 0; }
                smaller = smaller + total * place;
                place = place * 10;
            }
            remainder = smaller;

            // quotient = quotient + 1 (adder with carry starting at 1)
            long long bigger = 0;
            place = 1;
            int carry = 1;
            for (int column = 0; column < 6; column++) {
                int total = (quotient / place) % 10 + carry;
                bigger = bigger + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            quotient = bigger;
        }

        // 4c: put the signs back (who = 1 fixes quotient, who = 2 fixes remainder)
        for (int who = 1; who <= 2; who++) {
            long long toFix = quotient;
            bool needsNegate = (aNegative != bNegative);   // quotient: signs differ
            if (who == 2) {
                toFix = remainder;
                needsNegate = aNegative;                   // remainder: sign of dividend
            }

            if (needsNegate) {
                long long negated = 0, place = 1;
                int carry = 1;
                for (int column = 0; column < 6; column++) {
                    int total = (1 - (toFix / place) % 10) + carry;
                    negated = negated + (total % 2) * place;
                    carry = total / 2;
                    place = place * 10;
                }
                if (who == 1) quotient = negated;
                else          remainder = negated;
            }
        }
    }

    // ============================================================
    // STEP 5: CONVERT EVERYTHING TO DECIMAL (no printing in this loop)
    // item: 1=A  2=B  3=A+B  4=A-B  5=B-A  6=A*B  7=A/B  8=A%B
    // ============================================================
    int decA = 0, decB = 0, decSum = 0, decDiff1 = 0;
    int decDiff2 = 0, decProduct = 0, decQuotient = 0, decRemainder = 0;

    // the 6-bit or 7-bit values we will show for +, - (and whether they are 7 bits)
    long long sumShown = 0, diff1Shown = 0, diff2Shown = 0;
    bool sumSeven = false, diff1Seven = false, diff2Seven = false;

    for (int item = 1; item <= 8; item++) {

        long long value = 0;
        int bits = 6;                 // how many bits this value has
        bool readSigned = isSigned;   // should the leftmost bit count as negative?

        if (item == 1) value = numA;
        else if (item == 2) value = numB;
        else if (item == 3) {
            if (sumOverflow) { value = sumBits; bits = 7; }
            else value = sumBits % 1000000;            // keep lowest 6 digits
        }
        else if (item == 4) {
            // unsigned underflow (like 3 - 5) is negative, so read it as signed
            if (diff1Overflow) { value = diff1Bits; bits = 7; readSigned = true; }
            else value = diff1Bits % 1000000;
        }
        else if (item == 5) {
            if (diff2Overflow) { value = diff2Bits; bits = 7; readSigned = true; }
            else value = diff2Bits % 1000000;
        }
        else if (item == 6) { value = product; bits = 12; }
        else if (item == 7) value = quotient;
        else value = remainder;

        // place of the leftmost bit: 10^(bits-1)
        long long place = 1;
        for (int i = 0; i < bits - 1; i++) place = place * 10;

        // read the bits left to right: decimal = decimal * 2 + bit
        int decimalValue = 0;
        int leftmostBit = 0;
        for (int i = 0; i < bits; i++) {
            int bit = (value / place) % 10;
            if (i == 0) leftmostBit = bit;
            decimalValue = decimalValue * 2 + bit;
            place = place / 10;
        }

        // two's complement: if the sign bit is 1, subtract 2^bits
        if (readSigned && leftmostBit == 1) {
            int range = 1;
            for (int i = 0; i < bits; i++) range = range * 2;
            decimalValue = decimalValue - range;
        }

        // store the answers (still no cout)
        if (item == 1)      decA = decimalValue;
        else if (item == 2) decB = decimalValue;
        else if (item == 3) { decSum = decimalValue;   sumShown = value;   sumSeven = (bits == 7); }
        else if (item == 4) { decDiff1 = decimalValue; diff1Shown = value; diff1Seven = (bits == 7); }
        else if (item == 5) { decDiff2 = decimalValue; diff2Shown = value; diff2Seven = (bits == 7); }
        else if (item == 6) decProduct = decimalValue;
        else if (item == 7) decQuotient = decimalValue;
        else                decRemainder = decimalValue;
    }

    // ============================================================
    // STEP 6: PRINTING. No loops, each line written on its own.
    // cout drops leading zeros, so "if (x < ...) cout << zero;"
    // prints the missing ones before the number.
    // ============================================================
    cout << "A : " << decA << endl;
    cout << "B : " << decB << endl;

    // ---- A + B ----
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

    // ---- A - B ----
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

    // ---- B - A ----
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

    // ---- A * B (12 bits shown in groups of 4, like the sample) ----
    long long group1 = product / 100000000;        // left 4 digits
    long long group2 = (product / 10000) % 10000;  // middle 4 digits
    long long group3 = product % 10000;            // right 4 digits

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

    // ---- A / B and A % B ----
    if (divideByZero) {
        cout << "A / B = undefined (division by zero)" << endl;
        cout << "A % B = undefined (division by zero)" << endl;
    } else {
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
        cout << remainder << " = " << decRemainder << endl;
    }

    return 0;
}