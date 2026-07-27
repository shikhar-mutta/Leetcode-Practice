// Link: https://leetcode.com/problems/minimum-sum-after-divisible-sum-deletions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(k)
// Approach: dp[i] = min remaining sum of the first i elements after
// optimal deletions. dp[i] = min(dp[i-1]+nums[i-1] (keep element i-1),
// best dp[j] over all j<i with prefix[i]-prefix[j] divisible by k
// (delete that whole subarray)). Track the min dp[j] seen so far per
// prefix-sum-mod-k bucket for O(1) lookups.
class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1, 0);
        unordered_map<int, long long> best;
        dp[0] = 0;
        best[0] = 0;

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
            int mod = (int)(prefix[i] % k);
            dp[i] = dp[i-1] + nums[i-1];
            auto it = best.find(mod);
            if (it != best.end()) dp[i] = min(dp[i], it->second);
            if (it == best.end() || dp[i] < it->second) best[mod] = dp[i];
        }
        return dp[n];
    }
};
