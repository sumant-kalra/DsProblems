#include <iostream>

#include "Bitwise.h"

int main(int argc, char *argv[])
{
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

    return 0;
}