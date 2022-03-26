#include <iostream>
#include <bitset>

#include "Bitwise.h"

#define ACTIVE 0

int main(int argc, char *argv[])
{
#if ACTIVE

    // Problem 42-P1
    // Count the number of bits that are set to 1 in an integer

    std::cout << "Approach 1.A:\n";
    std::cout << bitwise::countOneBitsAp1(atoll(argv[1])) << "\n";

    std::cout << "Approach 1.B:\n";
    std::cout << bitwise::countOneBitsAp2(atoll(argv[1])) << "\n";

    std::cout << "Approach 2.A:\n";
    std::cout << bitwise::countOneBitsAp3_1(atoll(argv[1])) << "\n";

    std::cout << "Approach 2.B:\n";
    std::cout << bitwise::countOneBitsAp3_2(atoll(argv[1])) << "\n";

    // Problem 43-P-5.1.A
    // Compute the parity of a word
    std::cout << "Approach 1 - O(k) :\n";
    std::cout << bitwise::parity1(atoll(argv[1])) << "\n";
    std::cout << "Approach 2 - O(log n) :\n";
    std::cout << bitwise::parity2(atoll(argv[1])) << "\n";

    // Problem 43-P-5.1.B
    // Compute the parity of a number of 64 bit words
    bitwise::parity3(argc, argv);

    // Problem 51-5.7
    // Compute pow(x,y), where x is a floating point number and y is an integer
    std::cout << bitwise::pow1(2, -3) << "\n";
    std::cout << bitwise::pow2(2, -3) << "\n";
#endif

    return 0;
}