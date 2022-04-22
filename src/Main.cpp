#include <iostream>
#include <cstdlib>

#include "Recursion.h"

int main(int argc, char *argv[])
{
#if 0
    int num = atoi(argv[1]);
    std::cout << recursion::factorial((unsigned short int)(num)) << "\n";

    std::cout << recursion::isPalindrome(argv[1]) << "\n";


    std::cout << recursion::power_r1(strtod(argv[1], NULL), atoi(argv[2])) << "\n";
#endif
    std::cout << recursion::power_r2(strtod(argv[1], NULL), atoi(argv[2])) << "\n";
    return 0;
}