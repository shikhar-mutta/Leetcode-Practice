// Link: https://leetcode.com/problems/maximum-strength-of-k-disjoint-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 2;
        // dp0[j], dp1[j] for current i
        vector<long long> dp0(k + 1, NEG), dp1(k + 1, NEG);
        dp0[0] = 0;
        for (int i = 1; i <= n; i++) {
            vector<long long> ndp0(k + 1, NEG), ndp1(k + 1, NEG);
            for (int j = 1; j <= k; j++) {
                long long coeff = (long long)(k - j + 1) * ((j % 2 == 1) ? 1 : -1);
                long long val = coeff * nums[i-1];
                long long fromExtend = (dp1[j] > NEG) ? dp1[j] + val : NEG;
                long long fromStart = (dp0[j-1] > NEG) ? dp0[j-1] + val : NEG;
                ndp1[j] = max(fromExtend, fromStart);
            }
            for (int j = 0; j <= k; j++) {
                ndp0[j] = max(dp0[j], ndp1[j]);
            }
            dp0 = ndp0;
            dp1 = ndp1;
        }
        return dp0[k];
    }
};
