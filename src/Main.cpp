#include <iostream>
#include <cstdlib>

#include "Recursion.h"

int main(int argc, char *argv[])
{
#if 0
    // Factorial
    std::cout << recursion::factorial_r(atoll(argv[1])) << "\n";
    std::cout << recursion::factorial_i(atoll(argv[1])) << "\n";

    // Palindrome
    std::cout << recursion::isPalindrome_r(std::string(argv[1])) << "\n";
    std::cout << recursion::isPalindrome_i(std::string(argv[1])) << "\n";

    // Power function
    std::cout << recursion::powerTrivia_r(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << recursion::powerOptimized_r(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << recursion::powerTrivia_i(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << recursion::powerOptimized_i(atof(argv[1]), atoi(argv[2])) << "\n";


    // Print function
    recursion::printN0N_i(atoi(argv[1]));
    recursion::printN0N_r(atoi(argv[1]));

#endif

    std::cout << recursion::fibonacciNumber_r(atoi(argv[1])) << "\n";
    std::cout << recursion::fibonacciNumber_i(atoi(argv[1])) << "\n";

    return 0;
}