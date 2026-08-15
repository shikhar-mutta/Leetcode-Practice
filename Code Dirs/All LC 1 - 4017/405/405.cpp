// Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  SC: O(1)
// Approach: treat num as unsigned 32-bit, extract 4 bits at a time
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string digits = "0123456789abcdef";
        string res;
        while (n) {
            res += digits[n & 0xF];
            n >>= 4;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
