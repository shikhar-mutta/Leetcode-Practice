// Link: https://leetcode.com/problems/convert-to-base-2/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string res;
        long long x = n;
        while (x != 0) {
            int rem = (int)(x % -2);
            x /= -2;
            if (rem < 0) { rem += 2; x += 1; }
            res += ('0' + rem);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
