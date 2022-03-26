#ifndef BITWISE_H
#define BITWISE_H
/**
 * @brief Bitwise Operators
 * DS and Algorithms problems on Bitwise Operators
 * Source - Elements of Programming Interview Chapter 5
 *
 * Three Problems:                                                      : n = word size, k = number of ones, L = length of bits cached
 * 1. Count the number of 1s in the binary representation of a number   : Best Solution O(k)
 * 2. Find the parity of a word                                         : Best Solution O(log n)
 * 3. Find the parity of a number of 64-bit words                       : Best Solution O(log n) + O(n/L)
 * 4. Compute pow(x,y), where x is a floating point number and y is an integer : Best Solution O(log y)
 *
 * Solution:
 * 1. Solved by 2 approaches: O(n) and O(k); n = word size, k = number of 1s.
 * 2. Solved by 2 approaches:
 *    I.  Counting the number of 1s (Problem 1) and obtaining modulo 2.
 *    II. O(log n); n = word size; Using Commutative Property of parity computation.
 * 3. Solved by caching the parity results of all the 16-bit words and using Associativity Property of parity computation
 *      to obtain the parity of the 64-bit word by splitting it into 4 groups of 16-bit words.
 * 4. Solved by 2 approaches
 *    I.  Brute force approach - Multiply x with itself for y number of times, O(y)
 *    II. Refined-Brute force - Keep on extracting 2 from power y and squaring the number inside (x) until y = 1, O(log y)
 *
 * Important learnings: x and y be the words
 * 1. y = x & ~(x-1)    : Isolates the lowest bit that is 1
 * 2. x = x ^ y         : Eliminates the lowest bit which is set to 1, where y = x & ~(x-1)
 * 3. x = x & (x-1)     : Eliminates the lowest bit which is set to 1
 * 4. a^b               : Parity check for the corresponding bits
 */

namespace bitwise
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Problem 42-P1
    // Count the number of bits that are set to 1 in an integer
    // Approach 1.A --> My way
    unsigned short int countOneBitsAp1(unsigned long long int number);
    // Approach 1.B --> The better way
    unsigned short int countOneBitsAp2(unsigned long long int number);
    // Approach 2.A --> Refined approach 1, another way
    unsigned short int countOneBitsAp3_1(unsigned long long int number);
    // Approach 2.B --> Refined approach 1, the best way
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
    // Cache the parity results in an array and then access the results with O(1) complexity from the array

    // O(n/L) : n = word size, L = width of the words for which the results are cached

    // If we cache all the parity results of all the possible numbers that can be formed by using 64 bit word in an array
    // then the size of the array required will be 2^64 elements with size of element as 2 bytes (short int), which is not practical.
    // However, we can cache the parity results of all the numbers possible with 16 bits in an array. The size of array required
    // will be 2^16 elements = 65536 with size of each element as 2 bytes (short int), which is reasonable.
    // Since the parity calculation is associative, we can split the original 64 bits into 4 group of 16 bits and find the parity results
    // of each group from the cache and then find the final parity result from the 4 groups.

    // Note that the cache will not be very useful unless we are running the application in loop to find the parity
    // of a large number of 64 bit words. If we wanted to find parity of a single word then, the direct computation would have been better.
    void parity3(int argc, char *argv[]); // User inputs all the words for parity calculations as arguments while executing the application

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Problem 51-5.7
    // Compute pow(x,y), where x is a floating point number and y is an integer : Best Solution O(log y)
    // I.  Brute force approach - Multiply x with itself for y number of times, O(y)
    double pow1(double x, long long int y);
    // II. Refined-Brute force approach - Keep on extracting 2 from power y and squaring the number inside (x) until y = 1, O(log y)
    //     At any step in the iteration, if y is odd then, (x^2)^(y/2).(x);
    //                                   if y is even then, (x^2)^(y/2); ^ represents power
    double pow2(double x, long long int y);
}

#endif