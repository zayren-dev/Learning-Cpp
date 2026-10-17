#include <iostream>
using namespace std;

int main() {
    long long A, B;
    char choice;
    cout << "Input A : ";
    cin >> A;
    cout << "Input B : ";
    cin >> B;
    cout << "Are these numbers signed or unsigned? Y/N : ";
    cin >> choice;
    bool isSigned = (choice == 'Y' || choice == 'y');

    cout << "... Calculating ..." << endl;

    // ============================================================
    // STEP 1: stretch A and B to 7 bits (room for the overflow bit)
    //   signed   -> copy the sign bit (leftmost of the 6 bits) into bit 6
    //   unsigned -> bit 6 is just 0, so nothing to do
    // ============================================================
    long long a7_bit = A;
    long long b7_bit = B;
    if (isSigned) {
        if ((A / 100000) % 10 == 1) a7_bit = A + 1000000;  // put a 1 at position 6
        if ((B / 100000) % 10 == 1) b7_bit = B + 1000000;
    }

    // ============================================================
    // STEP 2: A + B, A - B, B - A  (one loop, three rounds)
    //   round 1 = A + B, round 2 = A - B, round 3 = B - A
    // ============================================================
    long long sumBits = 0, diff1Bits = 0, diff2Bits = 0;
    bool sumOverflow = false, diff1Overflow = false, diff2Overflow = false;

    for (int round = 1; round <= 3; round++) {
        // decide which number goes first
        long long first = a7_bit, second = b7_bit;
        if (round == 3) { first = b7_bit; second = a7_bit; }

        long long result = 0;
        long long place = 1;      // 1, 10, 100, ... (which digit we are on)
        int carryOrBorrow = 0;    // carry when adding, borrow when subtracting

        // go through the 7 bits from right to left
        for (int i = 0; i < 7; i++) {
            int digit1 = (first / place) % 10;
            int digit2 = (second / place) % 10;
            int bit;

            if (round == 1) {
                // full adder: add the two bits and the carry
                int total = digit1 + digit2 + carryOrBorrow;
                bit = total % 2;             // bit we keep
                carryOrBorrow = total / 2;   // bit we pass to the next column
            } else {
                // subtractor: take away the second bit and the borrow
                int total = digit1 - digit2 - carryOrBorrow;
                if (total < 0) {             // not enough, borrow from the left
                    total = total + 2;
                    carryOrBorrow = 1;
                } else {
                    carryOrBorrow = 0;
                }
                bit = total;
            }
            result = result + bit * place;
            place = place * 10;
        }

        // overflow check using the 7-bit answer
        int bit6 = (result / 1000000) % 10;
        int bit5 = (result / 100000) % 10;
        bool overflow;
        if (isSigned)
            overflow = (bit6 != bit5);   // the two leftmost bits disagree
        else
            overflow = (bit6 == 1);      // went above 63 (add) or below 0 (subtract)

        if (round == 1)      { sumBits = result;   sumOverflow = overflow; }
        else if (round == 2) { diff1Bits = result; diff1Overflow = overflow; }
        else                 { diff2Bits = result; diff2Overflow = overflow; }
    }

    // ============================================================
    // STEP 3: A * B using shift and add, 12 bits
    // ============================================================
    long long shiftedA = A;   // A, which moves left every round
    long long bigB = B;

    // stretch both to 12 bits so signed multiplication works too
    if (isSigned) {
        long long fillPlace = 1000000;   // position 6
        for (int i = 6; i < 12; i++) {
            if ((A / 100000) % 10 == 1) shiftedA = shiftedA + fillPlace;
            if ((B / 100000) % 10 == 1) bigB = bigB + fillPlace;
            fillPlace = fillPlace * 10;
        }
    }

    long long product = 0;
    long long bPlace = 1;
    for (int i = 0; i < 12; i++) {
        // if this bit of B is 1, add the shifted A into the product
        if ((bigB / bPlace) % 10 == 1) {
            long long newProduct = 0;
            long long place = 1;
            int carry = 0;
            for (int j = 0; j < 12; j++) {
                int total = (product / place) % 10 + (shiftedA / place) % 10 + carry;
                newProduct = newProduct + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            product = newProduct;
        }
        // shift A left by one bit (x10) and drop anything past 12 digits
        shiftedA = (shiftedA * 10) % 1000000000000LL;
        bPlace = bPlace * 10;
    }

    // ============================================================
    // STEP 4: A / B and A % B (repeated subtraction on positive values)
    // ============================================================
    long long quotient = 0, remainder = 0;
    bool divideByZero = (B == 0);

    if (!divideByZero) {
        long long absA = A, absB = B;
        bool aNegative = false, bNegative = false;

        // make A positive if it is a negative signed number (flip bits, add 1)
        if (isSigned && (A / 100000) % 10 == 1) {
            aNegative = true;
            long long negated = 0, place = 1;
            int carry = 1;
            for (int i = 0; i < 6; i++) {
                int total = (1 - (A / place) % 10) + carry;
                negated = negated + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            absA = negated;
        }
        // same for B
        if (isSigned && (B / 100000) % 10 == 1) {
            bNegative = true;
            long long negated = 0, place = 1;
            int carry = 1;
            for (int i = 0; i < 6; i++) {
                int total = (1 - (B / place) % 10) + carry;
                negated = negated + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            absB = negated;
        }

        remainder = absA;
        // numbers made of only 0s and 1s compare the same in decimal and in
        // binary, so a normal >= tells us if remainder is still big enough
        while (remainder >= absB) {
            // remainder = remainder - absB (bit by bit, with borrow)
            long long smaller = 0, place = 1;
            int borrow = 0;
            for (int i = 0; i < 6; i++) {
                int total = (remainder / place) % 10 - (absB / place) % 10 - borrow;
                if (total < 0) { total = total + 2; borrow = 1; }
                else           { borrow = 0; }
                smaller = smaller + total * place;
                place = place * 10;
            }
            remainder = smaller;

            // quotient = quotient + 1 (bit by bit)
            long long bigger = 0;
            place = 1;
            int carry = 1;
            for (int i = 0; i < 6; i++) {
                int total = (quotient / place) % 10 + carry;
                bigger = bigger + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            quotient = bigger;
        }

        // quotient is negative when the signs were different
        if (aNegative != bNegative) {
            long long negated = 0, place = 1;
            int carry = 1;
            for (int i = 0; i < 6; i++) {
                int total = (1 - (quotient / place) % 10) + carry;
                negated = negated + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            quotient = negated;
        }
        // remainder takes the sign of the dividend
        if (aNegative) {
            long long negated = 0, place = 1;
            int carry = 1;
            for (int i = 0; i < 6; i++) {
                int total = (1 - (remainder / place) % 10) + carry;
                negated = negated + (total % 2) * place;
                carry = total / 2;
                place = place * 10;
            }
            remainder = negated;
        }
    }

    // ============================================================
    // STEP 5: show everything. One loop goes through the 8 output lines;
    // each line picks its value, converts it to decimal, then prints.
    //   1: A   2: B   3: A+B   4: A-B   5: B-A   6: A*B   7: A/B   8: A%B
    // ============================================================
    for (int line = 1; line <= 8; line++) {
        long long value = 0;
        int bits = 6;                 // how many bits this value has
        bool readSigned = isSigned;   // read the sign bit as negative?

        if (line == 1) value = A;
        else if (line == 2) value = B;
        else if (line == 3) {
            if (sumOverflow) { value = sumBits; bits = 7; }
            else value = sumBits % 1000000;          // keep the lowest 6 digits
        }
        else if (line == 4) {
            // an unsigned subtraction that underflows is negative, so its
            // 7-bit answer is read as signed to show the real value
            if (diff1Overflow) { value = diff1Bits; bits = 7; readSigned = true; }
            else value = diff1Bits % 1000000;
        }
        else if (line == 5) {
            if (diff2Overflow) { value = diff2Bits; bits = 7; readSigned = true; }
            else value = diff2Bits % 1000000;
        }
        else if (line == 6) { value = product; bits = 12; }
        else if (line == 7) value = quotient;
        else value = remainder;

        // ---- turn the 0/1 number into its decimal value ----
        long long place = 1;
        for (int i = 0; i < bits - 1; i++) place = place * 10;   // leftmost digit's place

        int decimalValue = 0;
        int signBit = 0;
        for (int i = 0; i < bits; i++) {
            int digit = (value / place) % 10;
            if (i == 0) signBit = digit;             // remember the leftmost bit
            decimalValue = decimalValue * 2 + digit; // value = value*2 + bit
            place = place / 10;
        }
        // two's complement: if the sign bit is 1, subtract 2^bits
        if (readSigned && signBit == 1) {
            int range = 1;
            for (int i = 0; i < bits; i++) range = range * 2;
            decimalValue = decimalValue - range;
        }

        // ---- print ----
        if (line == 1) {
            cout << "A : " << decimalValue << endl;
        }
        else if (line == 2) {
            cout << "B : " << decimalValue << endl;
        }
        else if (line == 6) {
            // 12 bits, shown in groups of 4 like the sample
            long long group1 = value / 100000000;
            long long group2 = (value / 10000) % 10000;
            long long group3 = value % 10000;

            cout << "A * B = ";
            if (group1 < 1000) cout << "0";
            if (group1 < 100)  cout << "0";
            if (group1 < 10)   cout << "0";
            cout << group1 << " ";
            if (group2 < 1000) cout << "0";
            if (group2 < 100)  cout << "0";
            if (group2 < 10)   cout << "0";
            cout << group2 << " ";
            if (group3 < 1000) cout << "0";
            if (group3 < 100)  cout << "0";
            if (group3 < 10)   cout << "0";
            cout << group3 << " = " << decimalValue << endl;
        }
        else if ((line == 7 || line == 8) && divideByZero) {
            if (line == 7) cout << "A / B = undefined (division by zero)" << endl;
            else           cout << "A % B = undefined (division by zero)" << endl;
        }
        else {
            // lines 3, 4, 5, 7, 8: print the label first
            if (line == 3) cout << "A + B = ";
            else if (line == 4) cout << "A - B = ";
            else if (line == 5) cout << "B - A = ";
            else if (line == 7) cout << "A / B = ";
            else cout << "A % B = ";

            // leading zeros (cout drops them), so we add them by hand
            if (bits == 7 && value < 1000000) cout << "0";
            if (value < 100000) cout << "0";
            if (value < 10000)  cout << "0";
            if (value < 1000)   cout << "0";
            if (value < 100)    cout << "0";
            if (value < 10)     cout << "0";
            cout << value << " = " << decimalValue;

            // messages for + and -
            if (line >= 3 && line <= 5) {
                if (bits == 7) cout << "\toverflow detected, answer given in 7 bits";
                else           cout << "\tno overflow, so 6 bits";
            }
            cout << endl;
        }
    }

    return 0;
}