// Link: https://leetcode.com/problems/smallest-greater-multiple-made-of-two-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validDigits(long long n, int d1, int d2) {
        while (n > 0) {
            int d = n % 10;
            if (d != d1 && d != d2) return false;
            n /= 10;
        }
        return true;
    }

    int findInteger(int k, int digit1, int digit2) {
        for (long long n = k; n <= 100000000LL; n += k) {
            if (validDigits(n, digit1, digit2)) return (int)n;
        }
        return -1;
    }
};
