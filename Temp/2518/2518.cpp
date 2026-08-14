// Link: https://leetcode.com/problems/number-of-great-partitions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        if (totalSum < 2LL * k) return 0;

        int n = nums.size();
        vector<long long> dp(k, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int j = k - 1; j >= x; j--) {
                dp[j] = (dp[j] + dp[j - x]) % MOD;
            }
        }

        long long badCount = 0;
        for (int j = 0; j < k; j++) badCount = (badCount + dp[j]) % MOD;

        long long power2n = 1;
        for (int i = 0; i < n; i++) power2n = power2n * 2 % MOD;

        long long ans = (power2n - 2 * badCount % MOD + 2 * MOD) % MOD;
        return (int)ans;
    }
};
