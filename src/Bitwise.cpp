#include "Bitwise.h"

// Approach 1
// Looping over all the digits of the number to check for the value 1
// Time Complexity - O(n), where n is the count of bits in the number
// Keeping the original number unchanged, and creating a new bitmask for each digit of the number

unsigned short int bitwise::countOneBitsAp1(long long int num)
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

// --------------------------------------------------------------------------------------------------------------------------------------- //

// Approach 2
// Looping over all the digits of the number to check for the value 1
// Time Complexity - O(n), where n is the count of bits in the number
// Modifying the number but keeping the same bitmask
// Feeding the bits of the number to the bitmask

// Advantages -
// [1] Avoids the dependency on the number of bits of the number
// [2] Bitshift left operator is safer than the bitshift right as in the case of signed numbers

unsigned short int bitwise::countOneBitsAp2(long long int num)
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

// Approach 3
// By isolating on the bits which are set to 1 and keeping a count of them.
// We can replace the lowest bit that is 1 with 0 in an integer valued number by using two methods:
//
// x = Input number
// Approach 3.1
// y = x & ~(x-1) isolates the lowest bit that is 1
// x = y ^ x updates x to a new value with the lowest 1 eliminated
// Iterate this process until all the 1 are eliminated from x, keeping a count of 1s
//
// Approach 3.2
// x = x & (x-1) elimates the lowest bit that is 1 from the input
// Iterate this process until all the 1 are eliminated from x, keeping a count of 1s
//
// Advantage
// [1] Time complexity of the operation becomes O(k), k = count of 1s in the bit representation of the number
//
unsigned short int bitwise::countOneBitsAp3_1(long long int num)
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

unsigned short int bitwise::countOneBitsAp3_2(long long int num)
{
    unsigned short count = 0;
    while (num) // If the number is non-zero, it has atleast one bit with 1
    {
        num = num & (num - 1); // Eliminating the lowest bit that is one and keeping the count
        ++count;               // Keeping a count
    }
    return count;
}