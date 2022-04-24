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