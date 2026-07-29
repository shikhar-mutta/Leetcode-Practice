// Link: https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        vector<long long> bestForRem(k, LLONG_MAX);
        long long prefix = 0;
        bestForRem[0] = dp[0]; // dp[0] = 0, prefix[0] = 0

        for (int i = 1; i <= n; i++) {
            prefix += nums[i-1];
            dp[i] = dp[i-1] + nums[i-1];
            int rem = (int)(prefix % k);
            if (bestForRem[rem] != LLONG_MAX) dp[i] = min(dp[i], bestForRem[rem]);
            bestForRem[rem] = min(bestForRem[rem], dp[i]);
        }

        return dp[n];
    }
};
