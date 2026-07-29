// Link: https://leetcode.com/problems/minimum-operations-to-equalize-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s, int k) {
        long long n = s.size();
        long long z = 0;
        for (char c : s) if (c == '0') z++;
        if (z == 0) return 0;

        long long limit = 2 * n + 4;
        for (long long t = 1; t <= limit; t++) {
            long long total = (long long)k * t;
            if ((total % 2) != (z % 2)) continue;
            if (total < z) continue;
            long long maxZeroPerPos = (t % 2 == 1) ? t : t - 1;
            long long maxOnePerPos = (t % 2 == 0) ? t : t - 1;
            long long maxSum = z * maxZeroPerPos + (n - z) * maxOnePerPos;
            if (total <= maxSum) return (int)t;
        }
        return -1;
    }
};
