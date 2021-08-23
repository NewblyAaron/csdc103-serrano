// Filename     : approx.cpp
// Description  : This source file contains the implementation of the
//                function to approximate the value of PI.
// Author       : Aaron Serrano
// Honor Code   : I have not asked nor given any aunthorized help
//                in completing this exercise.

// Formula      : 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)

#include "approx.h"

long double approx_pi(int n) {
    long double summation = 0;

    for (int i = 0; i < n; i++) {
        int denominator = 1 + (i * 2);
        
        if (i % 2 == 0) {
            summation += 1.0 / (long double) denominator;
        }
        else {
            summation -= 1.0 / (long double) denominator;
        }
    }

    return 4.0 * summation;
}