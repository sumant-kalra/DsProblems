#ifndef BITWISE_H
#define BITWISE_H
/**
 * @brief Bitwise Operators
 * DS and Algorithms problems on Bitwise Operators
 * Source - Elements of Programming Interview Chapter 5
 */

namespace bitwise
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Problem 42-P1
    // Count the number of bits that are set to 1 in an integer
    // Approach 1.A
    unsigned short int countOneBitsAp1(unsigned long long int number);
    // Approach 1.B
    unsigned short int countOneBitsAp2(unsigned long long int number);
    // Approach 2.A
    unsigned short int countOneBitsAp3_1(unsigned long long int number);
    // Approach 2.B
    unsigned short int countOneBitsAp3_2(unsigned long long int number);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Problem 43-P-5.1.A
    // Compute the parity of a word
    // Approach 1 - O(k), k = number of bits of the word set to 1
    unsigned short int parity1(unsigned long long int number);
    //                         Note here, I am taking 'unsigned' 'long long int' as input type, no matter what integer type user will input,
    //                         - I will store it in the largest possible int : long long int (8 bytes)
    //                         - If I use signed integer, then, the user can input value that is out of range,
    //                              the resulting count of 1 will be less than the actual count because of the loop over
    //                              but if I use 'unsigned' then the chances of user providing out of range values are less
    //                              and if user inputs negative number then the count of 1s will remain same as the original one
    //                              when typecasted to unsigned, even after the loopover
    // Approach 2 - O(logn), n = number of bits of the word
    unsigned short int parity2(unsigned long long int number);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Problem 43-P-5.1.B
    // Compute the parity of a very large number of 64-bit words
    // In other words, there are a number of 64-bit words for which the parity needs to be tested

}

#endif