#include <cmath>
#include <memory>
#include <iostream>

#include "Bitwise.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Problem 42-P1
// Count the number of bits that are set to 1 in an integer

// Approach 1 - O(n)
// Method A
// Looping over all the digits of the number to check for the value 1
// Time Complexity - O(n), where n is the count of bits in the number
// Keeping the original number unchanged, and creating a new bitmask for each digit of the number

unsigned short int bitwise::countOneBitsAp1(unsigned long long int num)
{
    unsigned short int count = 0;
    const unsigned short int COUNT_BITS = (unsigned short int)sizeof(num) * 8;

    long long int bitmask = 1;

    for (unsigned short int i = 0; i < COUNT_BITS; ++i)
    {
        if (num & bitmask)
            ++count;
        bitmask <<= 1;
    }

    return count;
}
// Method B
// Looping over all the digits of the number to check for the value 1
// Time Complexity - O(n), where n is the count of bits in the number
// Modifying the number but keeping the same bitmask
// Feeding the bits of the number to the bitmask

// Advantages -
// [1] Avoids the dependency on the number of bits of the number
// [2] Bitshift left operator is safer than the bitshift right as in the case of signed numbers

unsigned short int bitwise::countOneBitsAp2(unsigned long long int num)
{
    unsigned short int count = 0;
    while (num)
    {

#if 0
        if (num & 1)
            ++count;
#endif

        // The above condition can be avoided by rewriting it as below:
        count += (num & 1);
        // (num&1) returns either one or zero
        // In our case, we wanted to increase the count by 1 if (num&1) == 1 else keep it as is
        // Since, the expression in the condition also evaluates to 1 or 0, it can be directly used.

        num >>= 1;
    }
    return count;
}

// --------------------------------------------------------------------------------------------------------------------------------------- //

// Approach 2 - O(k), k = count of 1s in the bit representation of the number
// By isolating on the bits which are set to 1 and keeping a count of them.
// We can replace the lowest bit that is 1 with 0 in an integer valued number by using two methods:
//
// x = Input number
// Method A
// y = x & ~(x-1) isolates the lowest bit that is 1
// x = y ^ x updates x to a new value with the lowest 1 eliminated
// Iterate this process until all the 1 are eliminated from x, keeping a count of 1s
//
// Method B
// x = x & (x-1) elimates the lowest bit that is 1 from the input
// Iterate this process until all the 1 are eliminated from x, keeping a count of 1s
//
// Advantage
// [1] Time complexity of the operation becomes O(k), k = count of 1s in the bit representation of the number
//
// Method A
unsigned short int bitwise::countOneBitsAp3_1(unsigned long long int num)
{
    unsigned short count = 0;
    long long int num2 = 0;
    while (num) // If the number is non-zero, it has atleast one bit with 1
    {
        // Isolating and eliminating the lowest bit that is one and keeping the count
        num2 = num & ~(num - 1); // Isolate
        num = num ^ num2;        // Eliminate
        ++count;                 // Keeping a count
    }
    return count;
}
// Method B
unsigned short int bitwise::countOneBitsAp3_2(unsigned long long int num)
{
    unsigned short count = 0;
    while (num) // If the number is non-zero, it has atleast one bit with 1
    {
        num = num & (num - 1); // Eliminating the lowest bit that is one and keeping the count
        ++count;               // Keeping a count
    }
    return count;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Problem 43-P-5.1.A
// Compute the parity of a word
// Approach 1 - O(k), k = number of bits set to 1
// Counting the number of bits that are set to and perform modulo 2 using XOR

unsigned short int bitwise::parity1(unsigned long long int number)
{
    unsigned short int parity = 0;
    while (number)
    {
        number &= (number - 1);
        // Here we are directly checking for parity instead of first counting the total number of 1s,
        // then performing modulo 2. At each intermedite step, we are setting parity = 0 if the count of
        // 1s become odd
        parity = parity ^ 1;
    }
    return parity;
}
// Approach 2 - O(log n), n = number of bits of the word
// By using Divide and Conquer
unsigned short int bitwise::parity2(unsigned long long int number)
{
    number ^= number >> 32; // number = number ^ number >> 32;
    number ^= number >> 16;
    number ^= number >> 8;
    number ^= number >> 4;
    number ^= number >> 2;
    number ^= number >> 1;
    return number & 1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Problem 43-P-5.1.B
// Compute the parity of a very large number of 64-bit words
// In other words, there are a number of 64-bit words for which the parity needs to be tested
void bitwise::parity3(int argc, char *argv[])
{
    int sizeOfCache = (int)std::pow(2.0, 16.0);
    // Caching the parity results of all the 16 bit words
    bool *parity16BitCache = new bool[sizeOfCache];
    for (int i = 0; i < sizeOfCache; i++)
    {
        parity16BitCache[i] = bitwise::parity2(i);
    }
    // Computing the parity of each of the number from the work input by the user
    unsigned long long int number = 0;
    const int kWordSize = 16;
    const int KBitMask = 0xFFFF; // Total - 8 bits
    unsigned short int parityResult = 0;
    for (int i = 1; i < argc; i++) // The first string is the name of the binary
    {
        number = atoll(argv[i]);
        //    G1       G2       G3       G4
        // [[[[]]]] [[[[]]]] [[[[]]]] [[[[]]]]
        parityResult = parity16BitCache[number >> (3 * kWordSize)] ^              // Formulate a number with G1 bits - 16 bit word
                       parity16BitCache[(number >> (2 * kWordSize)) & KBitMask] ^ // Formulate a number with G2 bits - 16 bit word
                       parity16BitCache[(number >> kWordSize) & KBitMask] ^       // Formulate a number with G3 bits - 16 bit word
                       parity16BitCache[number & KBitMask];                       // Formulate a number with G4 bits - 16 bit word
        std::cout << "The parity of the number " << number << " is: " << parityResult << "\n";
    }
    delete[] parity16BitCache;
}