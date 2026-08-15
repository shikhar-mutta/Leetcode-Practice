// Link: https://leetcode.com/problems/largest-integer-with-given-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestInteger(int n, int s) {
        if (s > 9 * n) return -1;
        string digits(n, '0');
        for (int i = 0; i < n && s > 0; i++) {
            int d = min(9, s);
            digits[i] = '0' + d;
            s -= d;
        }
        return stoi(digits);
    }
};
