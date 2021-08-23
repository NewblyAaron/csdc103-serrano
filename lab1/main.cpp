// Filename     : main.cpp
// Description  : This program tests the implementation of the
//                function to approximate the value of PI.
// Author       : Aaron Serrano
// Honor Code   : I have not asked nor given any aunthorized help
//                in completing this exercise.

#define FIXED_FLOAT(x) std::fixed << std::setprecision(15) << (x)

#include <iostream>
#include <iomanip>
#include "approx.h"

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int i = 1; i <= cases; i++) {
        int input;
        cin >> input;
        
        cout << "CASE " << i << ": " << FIXED_FLOAT(approx_pi(input)) << endl;
    }

    return 0;
}