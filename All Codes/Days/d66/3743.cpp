// Link: https://leetcode.com/problems/maximize-cyclic-partition-score/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*k)  SC: O(n)
// Approach: partition the cyclic array into at most k contiguous (wrap-
// allowed) subarrays maximizing the sum of (max-min) per subarray. Fix the
// cyclic cut at the index of the global minimum (or right after it) so the
// array can be unrolled linearly, then each subarray's range = max-min
// decomposes into a sum of (peak - valley) moves, which is exactly "Best
// Time to Buy and Sell Stock IV" with at most k transactions on the
// unrolled values; take the better of starting the unroll at the min or
// right after it.
class Solution {
    long long bestKTransactions(vector<int>& nums, int k, int base) {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        long long result = 0;
        for (int i = 0; i < k; i++) {
            long long x = LLONG_MIN, y = LLONG_MIN;
            vector<long long> newDp(n + 1, LLONG_MIN);
            for (int j = i; j < n; j++) {
                long long val = nums[(base + j) % n];
                x = max(x, dp[j] - val);
                y = max(y, dp[j] + val);
                newDp[j+1] = max({newDp[j], x + val, y - val});
            }
            dp = newDp;
            result = max(result, dp[n]);
        }
        return result;
    }
public:
    long long maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int i = min_element(nums.begin(), nums.end()) - nums.begin();
        return max(bestKTransactions(nums, k, i), bestKTransactions(nums, k, (i + 1) % n));
    }
};
