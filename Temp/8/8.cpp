// Link: https://leetcode.com/problems/string-to-integer-atoi/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: skip leading whitespace, parse optional sign, accumulate digits with clamping to INT range as we go
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        long long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if (sign == 1 && res > INT_MAX) return INT_MAX;
            if (sign == -1 && -res < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(sign * res);
    }
};
