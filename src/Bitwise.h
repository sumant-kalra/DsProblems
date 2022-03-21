#ifndef BITWISE_H
#define BITWISE_H
/**
 * @brief Bitwise Operators
 * DS and Algorithms problems on Bitwise Operators
 * Source - Elements of Programming Interview Chapter 5
 */

namespace bitwise
{
    // Problem 42-P1
    // Count the number of bits that are set to 1 in an integer
    // Approach 1.A
    unsigned short int countOneBitsAp1(long long int number);
    // Approach 1.B
    unsigned short int countOneBitsAp2(long long int number);
    // Approach 2.A
    unsigned short int countOneBitsAp3_1(long long int number);
    // Approach 2.B
    unsigned short int countOneBitsAp3_2(long long int number);
}

#endif