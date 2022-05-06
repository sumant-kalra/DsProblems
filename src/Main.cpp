#define MAIN 1
#if MAIN

#include <iostream>

void func1(int n);
void func2(int n);

int main(int argc, char *argv[])
{
    func1(3);
    func2(3);
    return 0;
}

void func1(int n)
{
    if (n > 0)
    {
        std::cout << n << "\n";
        func1(n - 1);
    }
}

void func2(int n)
{
    if (n > 0)
    {
        func2(n - 1);
        std::cout << n << "\n";
    }
}
#endif