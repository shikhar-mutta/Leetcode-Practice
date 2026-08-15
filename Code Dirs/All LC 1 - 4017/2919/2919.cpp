// Link: https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++) {
            long long cost = max(0, k - nums[i]);
            long long best = LLONG_MAX;
            for (int d = 1; d <= 3; d++) {
                long long prev = (i - d >= 0) ? dp[i - d] : 0;
                best = min(best, prev);
            }
            dp[i] = cost + best;
        }
        long long ans = LLONG_MAX;
        for (int d = 1; d <= 3; d++) {
            int idx = n - d;
            if (idx >= 0) ans = min(ans, dp[idx]);
        }
        return ans;
    }
};
