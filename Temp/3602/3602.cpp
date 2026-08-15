// Link: https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // convert v to the given base (<=36) as an uppercase string
    string toBase(long long v, int base) {
        if (v == 0) return "0";
        string r;
        while (v) {
            int d = v % base;
            r += (d < 10) ? char('0' + d) : char('A' + d - 10);
            v /= base;
        }
        reverse(r.begin(), r.end());
        return r;
    }

    string concatHex36(int n) {
        // hex (base 16) of n^2 followed by base-36 of n^3
        long long sq = 1LL * n * n, cube = 1LL * n * n * n;
        return toBase(sq, 16) + toBase(cube, 36);
    }
};
