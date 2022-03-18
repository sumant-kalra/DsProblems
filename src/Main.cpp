#include <iostream>

#include "Bitwise.h"

int main(int argc, char *argv[])
{
    std::cout << "Approach 1:\n";
    std::cout << bitwise::countOneBitsAp1(atoll(argv[1])) << "\n";

    std::cout << "Approach 2:\n";
    std::cout << bitwise::countOneBitsAp2(atoll(argv[1])) << "\n";

    std::cout << "Approach 3.1:\n";
    std::cout << bitwise::countOneBitsAp3_1(atoll(argv[1])) << "\n";

    std::cout << "Approach 3.2:\n";
    std::cout << bitwise::countOneBitsAp3_2(atoll(argv[1])) << "\n";

    return 0;
}