#include <iostream>

#include "Arrays.h"

//------------------------------------------------------------------------//

arrays::ArrayInts::ArrayInts(int argc, char *argv[]) : m_size(argc - 1)
{
    m_array = new int[m_size];
    for (int i = 0; i < m_size; ++i)
    {
        m_array[i] = std::stoi(argv[i + 1]);
    }
}
//------------------------------------------------------------------------//

arrays::ArrayInts::~ArrayInts()
{
    delete[] m_array;
}
//------------------------------------------------------------------------//

int arrays::ArrayInts::getSize()
{
    return m_size;
}
//------------------------------------------------------------------------//

void arrays::ArrayInts::printElements()
{
    std::cout << "Array: ";
    for (int i = 0; i < m_size; ++i)
    {
        std::cout << m_array[i] << " ";
    }
    std::cout << "\n";
}
//------------------------------------------------------------------------//
// My approach: Time - O(2n), Space - O(n)
void arrays::ArrayInts::reorderEvenOddPrint_1()
{
    int *arrayIntermediate = new int[m_size];

    int j = 0;
    for (int i = 0; i < m_size; ++i)
    {
        if (!(m_array[i] & 1))
        {
            arrayIntermediate[j] = m_array[i];
            ++j;
        }
    }
    for (int i = 0; i < m_size; ++i)
    {
        if (m_array[i] & 1)
        {
            arrayIntermediate[j] = m_array[i];
            ++j;
        }
    }

    for (int i = 0; i < m_size; ++i)
    {
        m_array[i] = arrayIntermediate[i];
    }

    printElements();

    delete[] arrayIntermediate;
}
//------------------------------------------------------------------------//
// My approach: Time - O(n), Space - O(n)
void arrays::ArrayInts::reorderEvenOddPrint_2()
{
    int *arrayIntermediate = new int[m_size];

    int m = 0;
    int n = m_size - 1;
    for (int i = 0; i < m_size; ++i)
    {
        if (m_array[i] & 1)
        {
            arrayIntermediate[n] = m_array[i];
            --n;
        }
        else
        {
            arrayIntermediate[m] = m_array[i];
            ++m;
        }
    }

    for (int i = 0; i < m_size; ++i)
    {
        m_array[i] = arrayIntermediate[i];
    }

    printElements();

    delete[] arrayIntermediate;
}
//------------------------------------------------------------------------//
// My approach: Time - O(n), Space - O(1)
void arrays::ArrayInts::reorderEvenOddPrint_3()
{
    // Dividing the whole array into 3 parts
    // 1. Ordered array - Left
    // 2. Unordered array - Middle
    // 3. Ordered array - Right
    // The unordered array diminishes in size by moving the elements to the ordered part
    // Initially, the array contains only the unordered part
    // Finally, the array contains only the ordered part

    int m = 0;          // Pointing to the first element of the unordered array
    int n = m_size - 1; // Pointing to the last element of the unordered array

// The condition to iterate through each element only once is wrong
// The current location must be tested until the number at the location is the correct number
#if 0
    for (int i = 0; i < m_size; ++i)
#endif
    while (m < n)
    {
        if (m_array[m] & 1) // Test if the first element of the unordered part is odd
        {                   // If yes, then swap it with the last element of the unordered part
            utilities::swap(m_array[n], m_array[m]);
            // Since, the last element of the unordered part contains an odd number for sure,
            --n;
            // But we do not know what has arrived at the first position of the unordered part
            // So, we can't ++m. The mth postion must be rechecked until it has an even number
        }
        else // If the first element of the unordered part is an even number, it means it is already a part of the ordered array,
             // so, shifting m to the next element
            ++m;
    }
    printElements();
}
// Note that the algorithm is O(n) in time though we might be checking elements at a position more than once
// because with repititive check for a position, we are elimination a check at the last position in the unordered part
//------------------------------------------------------------------------//
// Book's approach: Time - O(n), Space - O(1)
void arrays::ArrayInts::reorderEvenOddPrint_3_0()
{
    int m = 0;
    int n = m_size - 1;
    while (m < n)
    {
        if (m_array[m] & 1)
        {
            utilities::swap(m_array[m], m_array[n]);
            --n;
        }
        else
            ++m;
    }
    printElements();
}
//------------------------------------------------------------------------//

void utilities::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}