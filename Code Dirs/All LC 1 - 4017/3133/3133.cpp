// Link: https://leetcode.com/problems/minimum-array-end/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minEnd(int n, int x) {
        long long result = x;
        long long rem = n - 1;
        long long bit = 1;
        while (rem > 0) {
            if (!(result & bit)) {
                if (rem & 1) result |= bit;
                rem >>= 1;
            }
            bit <<= 1;
        }
        return result;
    }
};
