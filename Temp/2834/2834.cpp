// Link: https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        const long long MOD = 1e9 + 7;
        long long m = min((long long)n, (long long)target / 2);
        long long sum1 = m * (m + 1) / 2 % MOD;
        long long rem = n - m;
        long long sum2 = 0;
        if (rem > 0) {
            long long last = target + rem - 1;
            sum2 = (target + last) * rem / 2 % MOD;
        }
        return (int)((sum1 + sum2) % MOD);
    }
};
