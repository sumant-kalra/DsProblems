#ifndef RECURSION_H
#define RECURSION_H

#include <string>
#include <vector>
#include <array>

namespace recursion
{
    // Recursive - Find the factorial of a non-negative integer
    // Time - O(n) Space - O(n)
    unsigned long long int factorial_r(unsigned int n);

    // Iterative - Find the factorial of an non-negative integer
    // Time - O(n) Space - O(1)
    unsigned long long int factorial_i(unsigned int n);

    // Recursive - Identify if the given string is a palindrome
    // Time - O(|S|/2) Space - O(|S|/2)
    bool isPalindrome_r(const std::string &testString);

    // Iterative - Identify if the given string is a palindrome
    // Time - O(|S|/2) Space - O(1)
    bool isPalindrome_i(const std::string &testString);

    // Recursive - Fibonacci
    // Time - O(2^n) Exponential Space - O(n) from the depth of recursion of the recursion tree
    unsigned int fibonacciNumber_r(unsigned int n);

    // Iterative - Fibonacci
    // Time - O(n) Space - O(1)
    unsigned int fibonacciNumber_i(unsigned int n);

    // ENTIRE SEQUENCE MAY NOT MATCH, IDENTIFY THE OFFSET
    // Jumping frog -
    // A frog wants to cross a river that is 11 feet across.
    // There are 10 stones in a line leading across the river, separated by 1 foot,
    // and the frog is only ever able to jump one foot forward to the next stone,
    // or two feet forward to the stone after the next.
    // In how many different ways can he jump exactly 11 feet to the
    // other side of the river?
    // Forms a fibonacci sequence ofset by 1 as below
    /*
    0 feet - 0 way
    1 feet - 1 way  - 2nd Term of Fibonacci starting from index 0
    2 feet - 2 ways - 3rd Term of Fibonacci starting from index 0
    3 feet - 3 ways - 4th Term
    4 feet - 5 ways - 5th Term
    5 feet - 8 ways
    .
    .
    11 feet - - 12th Term?
    Solve it for 11 feet that is find the 12th term of the fibonacci sequence
    */

    // Recursive - Power function implementation - Trivial
    // Time - O(n) Space - O(n)
    double powerTrivia_r(double n, int p);

    // Iterative - Power function implementation - Trivial
    // Time - O(n) Space - O(n)
    double powerTrivia_i(double n, int p);

    // Recursive - Power function implementation - Optimized
    // Time - O(log p) Space - O(log p)
    // March towards the Base case by withdrawing 2 from the power at each recursion
    double powerOptimized_r(double n, int p);

    // Iterative - Power function implementation - Optimized
    // Time - O(log p) Space - O(1)
    // Square the number n until you reach p
    double powerOptimized_i(double n, int p);

    // Recursive - Print n - 0 - n; ex - 5 4 3 2 1 0 1 2 3 4 5
    // Not really the kind of problem you would like to solve with recursion
    // This problem is just for practise - No recursive thinking
    // Time - O(2n) Space - O(2n)
    void printN0N_r(int n);

    // Iterative - Print n - 0 - n; ex - 5 4 3 2 1 0 1 2 3 4 5
    // Time - O(2n) Space - O(1)
    void printN0N_i(int n);

    // Just for the practise
    double power_r(double x, int y);
    double power_i(double x, int y);

    // Binary search algorithm using recursion
    bool binarySearch_r(const std::vector<int> &vec, int num);

    // Binary search algorithm using iterative approach
    template <int N>
    int binarySearch_i(const std::array<int, N> &sortedArray, int num)
    {
        int left = 0;
        int right = sortedArray.size() - 1;
        int mid = (left + right) / 2;
        while (left <= right)
        {
            if (sortedArray.at(mid) == num)
                return mid;
            else if (sortedArray.at(mid) < num)
            {
                left = mid + 1;
            }
            else if (sortedArray.at(mid) > num)
            {
                right = mid - 1;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }
}

#endif