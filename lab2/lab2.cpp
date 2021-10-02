// Filename : lab2.cpp
//
// Author : Aaron M. Serrano
//          aaserrano@gbox.adnu.edu.ph
//
// Sanity : Gone
//
// Honor Code : I have not received nor given any unauthorized help
//              in completing this exercise.

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    c = char(tolower(c));
    
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    else {
        return false;
    }
}

/*
    count_vowels(s, n)
        = 1                         if n == 0 and s[n] is a vowel
        = 0                         if n == 0 and s[n] is not a vowel
        = count_vowels(s, n) + 1    if n > 0 and s[n] is a vowel
        = count_vowels(s, n)        if n > 0 and s[n] is not a vowel

    Base case is when 's' is empty (which n = 0). Since C++ forwards
    the input as whitespace, it will check if s[n] is a vowel, which
    a whitespace is not a vowel.

    Do note that s[] starts at 0, not 1. Thus, if a word has 5 letters,
    n should be 4. Arrays start at index 0.

    Decomposition Appoach:
    Break the array in two, where the first is a subarray containing
    the first n-1 elements and the last is a single value which is
    the last element on the array.

    Recursive Case:
    For any array 's' containing n > 0 elements,
        if the last element s[n-1] is a vowel,
            check if there are still elements in 's',
                if there are, increment count_vowels(s, n) by 1.
                else if there are no more, return 1.
        else if the last element s[n-1] is not a vowel,
            check if there are still elements in 's',
                if there are, run count_vowels(s, n) again.
                else if there are no more, return 0.
*/
int count_vowels(string s, int n) {
    if (isVowel(s[n])) {
        if (n == 0) return 1;
        return count_vowels(s, n - 1) + 1;
    }
    else {
        if (n == 0) return 0;
        return count_vowels(s, n - 1);
    }
}

/*
    binary_to_decimal(b, n)
    [n will always start at 0]
        = 0                                 if b == 0
        = b * 2^n                           if b == 1
        = binary_to_decimal(b / 10, n + 1)  if b > 1
            + ((b mod 10) * 2^n)
    
    Base cases are when 'b' only has one digit: 0 or 1.
    When it is 0, it returns 0. When it is 1, it returns the product
    of b * 2^n.

    Decomposition Approach:
    Separate the last digit of integer 'b', which would make the size
    smaller. 'n' increments by 1 every repetition.

    Recursive Case:
    For any integer 'b' that isn't a single digit (b == 0 or 1)
        add binary_to_decimal(b / 10, n + 1) with (b mod 10) * 2^n.
*/
int binary_to_decimal(int b, int n=0) {
    if (b == 0)
        return 0;
    else if (b == 1)
        return b * pow(2, n);
    
    return binary_to_decimal(b / 10, n + 1) + ((b % 10) * pow(2, n));
}

// This is just the same as in the sample code, but I added 'i' to
// count up...
int search(int A[], int n, int x, int i=0) {
    if (n == 0) {
        return -1; 
    }
    
    if (A[n - 1] == x) {
        return i;
    }
    
    return search(A, n - 1, x, i + 1);
}

// My head hurts too much to do search_sorted() atm.

int main() {
    cout << count_vowels("Apple", 4) << endl;
    cout << count_vowels("BAnaNa", 5) << endl;

    cout << binary_to_decimal(10110) << endl;

    int A[] = {90, 100, 1001, 87, 90};
    cout << search(A, 5, 90) << endl;
    cout << search(A, 5, 777) << endl;
}