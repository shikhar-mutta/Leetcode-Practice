// Link: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        bool neg = num < 0;
        long long n = abs(num);
        string digits;
        while (n > 0) { digits += ('0' + n % 10); n /= 10; }
        sort(digits.begin(), digits.end());

        if (neg) {
            reverse(digits.begin(), digits.end());
        } else {
            if (digits[0] == '0') {
                int i = 0;
                while (digits[i] == '0') i++;
                swap(digits[0], digits[i]);
            }
        }
        long long result = stoll(digits);
        return neg ? -result : result;
    }
};
