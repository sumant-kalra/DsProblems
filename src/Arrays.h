#ifndef ARRAYS_H
#define ARRAYS_H

namespace arrays
{
    class ArrayInts
    {
    private:
        unsigned int m_size;
        int *m_array;

    public:
        ArrayInts(int argc, char *argv[]);
        ~ArrayInts();
        int getSize();
        void printElements();

        // My approach: Time - O(2n), Space - O(n)
        void reorderEvenOddPrint_1();
        // My approach: Time - O(n), Space - O(n)
        void reorderEvenOddPrint_2();
        // My approach: Time - O(n), Space - O(1)
        void reorderEvenOddPrint_3();
        // Book's approach: Time - O(n), Space - O(1)
        void reorderEvenOddPrint_3_0();
    };

}

namespace utilities
{
    void swap(int &a, int &b);
}
#endif