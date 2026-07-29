// Link: https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toBase(long long x, int base) {
        if (x == 0) return "0";
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string res;
        while (x > 0) {
            res += digits[x % base];
            x /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string concatHex36(int n) {
        long long sq = (long long)n * n;
        long long cu = (long long)n * n * n;
        return toBase(sq, 16) + toBase(cu, 36);
    }
};
