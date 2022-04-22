#include <string>
#include "Recursion.h"

unsigned long long int recursion::factorial(unsigned short int number)
{
    if (number == 0)
        return 1;
    else
        return number * recursion::factorial(number - 1);
}

bool recursion::isPalindrome(const std::string &word)
{
    if (word.length() == 0 || word.length() == 1)
        return true;

    if (word.front() != word.back())
        return false;
    else
        return recursion::isPalindrome(word.substr(1, word.length() - 2));
}

double recursion::power_r1(double n, int pow)
{
    if (pow < 0)
    {
        n = 1 / n;
        pow = -1 * pow;
    }

    if (pow == 0)
        return 1;
    else
        return n * recursion::power_r1(n, --pow);
}

double recursion::power(double n, int pow)
{

    if (pow < 0)
    {
        n = 1 / n;
        pow = -1 * pow;
    }

    double result = 1.0;
    while (pow)
    {
        if (pow % 2)
        {
            result = result * n;
        }
        n *= n;
        pow /= 2;
    }

    return result;
}

double recursion::power_r2(double n, int p)
{
    double temp = 1;
    if (p < 0)
    {
        n = 1 / n;
        p = -1 * p;
    }

    if (p == 0)
        return 1;
    if (p % 2)
        return n * power_r2(n, p - 1);
    else
    {
        temp = power_r2(n, p / 2);
        return temp * temp;
    }
}
