#include <iostream>
#include <string>

using namespace std;

bool contains_digit(int n, int d) {
    // declare variables
    string strNum = to_string(n);
    string strDigit = to_string(d);

    size_t found = strNum.find(strDigit); // find digit in number string
    if (found != string::npos) return true; // if digit is found, return true

    return false; // otherwise, return false
}

int main() {
    int cases;
    cin >> cases; // get the input for number of cases

    for (int i = 1; i <= cases; i++) {
        int n, d;
        cin >> n >> d; // get the input for the number and digit to find
    
        if (n < 0 || d < 0) { // check if number is negative
            cout << "CASE " << i << ": NOT FOUND" << endl;
            continue; // go to the next iteration
        }

        if (contains_digit(n, d)) { // check if digit is found
            cout << "CASE " << i << ": FOUND" << endl;
        }
        else {
            cout << "CASE " << i << ": NOT FOUND" << endl;
        }
    }
    
    return 0;
}