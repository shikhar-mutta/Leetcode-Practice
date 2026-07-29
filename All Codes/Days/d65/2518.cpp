// Link: https://leetcode.com/problems/number-of-great-partitions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*K), SC: O(K)
// Approach: total assignments = 2^n. A partition is "bad" if either group's sum < k; these two
// events are disjoint (needs total >= 2k to even coexist as possibilities). Count subsets with
// sum < k via bounded knapsack DP (cap at k-1), badCount = sum of dp[0..k-1]; answer = 2^n - 2*badCount.
class Solution {
public:
    const long long MOD = 1e9+7;

    int countPartitions(vector<int>& nums, int k) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        if (total < 2LL * k) return 0;

        int n = nums.size();
        long long pow2n = 1;
        for (int i = 0; i < n; i++) pow2n = pow2n * 2 % MOD;

        vector<long long> dp(k, 0);
        dp[0] = 1;
        for (int x : nums) {
            if (x >= k) continue;
            for (int s = k-1; s >= x; s--) dp[s] = (dp[s] + dp[s-x]) % MOD;
        }
        long long badCount = 0;
        for (int s = 0; s < k; s++) badCount = (badCount + dp[s]) % MOD;

        long long ans = ((pow2n - 2*badCount) % MOD + MOD) % MOD;
        return (int)ans;
    }
};
