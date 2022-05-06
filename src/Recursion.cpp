#include <iostream>

#include "Recursion.h"

// --------------------------------------------------------------------------- //

unsigned long long int recursion::factorial_r(unsigned int n)
{
    unsigned long long int result = 1;

    if (n == 0)
        return 1;

    result = n * factorial_r(n - 1);

    return result;
}

unsigned long long int recursion::factorial_i(unsigned int n)
{
    unsigned long long int result = 1;
    while (n)
    {
        result = n * result;
        --n;
    }
    return result;
}

// --------------------------------------------------------------------------- //

bool recursion::isPalindrome_r(const std::string &testString)
{
    if (testString.length() == 1 || testString.length() == 0)
        return true;
    if (testString[0] == testString[testString.length() - 1])
        return recursion::isPalindrome_r(testString.substr(1, testString.length() - 2));
    else
        return false;
}

bool recursion::isPalindrome_i(const std::string &testString)
{
    size_t lengthString = testString.length();

    for (size_t i = 0; i < lengthString / 2; ++i)
    {
        if (testString[i] != testString[lengthString - 1 - i])
            return false;
    }
    return true;
}

// --------------------------------------------------------------------------- //

unsigned int recursion::fibonacciNumber_r(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fibonacciNumber_r(n - 1) + fibonacciNumber_r(n - 2);
}

unsigned int recursion::fibonacciNumber_i(unsigned int n)
{
    const unsigned int ZERO = 0;
    const unsigned int FIRST = 1;
    if (n == 0)
        return ZERO;
    else if (n == 1)
        return FIRST;
    else
    {
        unsigned int numberL = FIRST;
        unsigned int numberLL = ZERO;
        unsigned int number = 0;
        for (int i = 2; i <= n; ++i)
        {
            number = numberL + numberLL;
            numberLL = numberL;
            numberL = number;
        }
        return number;
    }
}

// --------------------------------------------------------------------------- //

double recursion::powerTrivia_r(double n, int p)
{
    if (p < 0)
    {
        n = 1 / n;
        p = -1 * p;
    }

    if (p == 0)
        return 1.0;

    return n * recursion::powerTrivia_r(n, --p);
}

double recursion::powerTrivia_i(double n, int p)
{
    double result = 1.0;

    if (p < 0)
    {
        p = -1 * p;
        n = 1 / n;
    }

    while (p)
    {
        result = result * n;
        --p;
    }

    return result;
}

// --------------------------------------------------------------------------- //

double recursion::powerOptimized_r(double n, int p)
{
    double temp = 1.0;
    if (p < 0)
    {
        p = -1 * p;
        n = 1 / n;
    }
    if (p == 0)
        return 1.0;

    if (p % 2)
    {
        return n * recursion::powerOptimized_r(n, p - 1);
    }
    else
    {
        temp = recursion::powerOptimized_r(n, p / 2);
        return temp * temp;
    }
}

double recursion::powerOptimized_i(double n, int p)
{
    double result = 1.0;
    if (p < 0)
    {
        p = -1 * p;
        n = 1 / n;
    }

    while (p)
    {
        if (p % 2)
        {
            result = n * result;
        }
        n = n * n;
        p = p / 2;
    }

    return result;
}

// --------------------------------------------------------------------------- //

void recursion::printN0N_r(int n)
{
    static unsigned int recursion_count = 2 * n + 1;
    static int increment = -1;

    if (n < 0)
    {
        n = -1 * n;
        increment = -1 * increment;
    }

    std::cout << n << " ";

    --recursion_count;
    if (recursion_count == 0)
    {
        std::cout << "\n";
        return;
    }

    n = n + increment;
    recursion::printN0N_r(n);
}

void recursion::printN0N_i(int n)
{
    unsigned int iterationsCount = 2 * n + 1;
    int increment = -1;

    while (iterationsCount--)
    {
        std::cout << n << " ";
        n = n + increment;

        if (n < 0)
        {
            n = -1 * n;
            increment = -1 * increment;
        }
    }

    std::cout << "\n";
}

// --------------------------------------------------------------------------- //

double recursion::power_r(double n, int p)
{
    if (p == 0)
        return 1;
    if (p < 0)
    {
        p = -1 * p;
        n = 1 / n;
    }

    double temp = 1.0;

    if (p % 2)
    {
        return n * recursion::power_r(n, p - 1);
    }
    else
    {
        temp = recursion::power_r(n, p / 2);
        return temp * temp;
    }
}

double recursion::power_i(double n, int p)
{
    double result = 1.0;
    if (p < 0)
    {
        p = -1 * p;
        n = 1 / n;
    }

    while (p)
    {
        if (p % 2)
        {
            result = n * result;
        }

        n = n * n;
        p = p / 2;
    }
    return result;
}

// --------------------------------------------------------------------------- //
bool recursion::binarySearch_r(const std::vector<int> &vec, int num)
{
    if (!vec.size())
        return false;
    else
    {
        int mid = vec.size() / 2;
        if (num == vec[mid])
            return true;
        if (num < vec[mid])
        {
            std::vector<int> lVec(vec.begin(), vec.begin() + mid);
            return recursion::binarySearch_r(lVec, num);
        }
        else
        {
            std::vector<int> rVec(vec.begin() + mid + 1, vec.end());
            return recursion::binarySearch_r(rVec, num);
        }
    }
}

// --------------------------------------------------------------------------- //
#define MAIN_RECURSION 0
#if MAIN_RECURSION

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

    // Fibonacci
    std::cout << recursion::fibonacciNumber_r(atoi(argv[1])) << "\n";
    std::cout << recursion::fibonacciNumber_i(atoi(argv[1])) << "\n";

    std::cout << recursion::power_i(atof(argv[1]), atoi(argv[2])) << "\n";
    std::cout << recursion::power_r(atof(argv[1]), atoi(argv[2])) << "\n";


    std::vector<int> myVec{-98, -39, -1, 3, 7, 13, 89, 109, 133, 180, 389};

    std::array<int, 11> myArray{-98, -39, -1, 3, 7, 13, 89, 109, 133, 180, 389};

    std::cout << recursion::binarySearch_i<11>(myArray, atoi(argv[1])) << "\n";

    std::cout << recursion::binarySearch_r(myVec, atoi(argv[1])) << "\n";
#endif

    return 0;
}
#endif
