#ifndef RANDOM_H
#define RANDOM_H

namespace random_space
{
    // Generate a 4 digit PIN using rand() of <cstdlib>
    unsigned short int generatePIN_4_C();

    // C++11
    // distribution(generator)
    // Initialize/Seed the generator with an unsigned value from any clock

    // Generate a 4 digit PIN using <random> library of C++
    unsigned short int generatePIN_4_cpp();

    // Generate a real number randomly in the provided range
    double generateRand_cpp(double min, double max);

    // Generate a real number randomly in the range [0,1)
    double generateRandCanonical();
}

#endif