// Link: https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        const long long MOD = 1000000007;
        int n = nums.size();
        vector<long long> dp(nums[0] + 1, 1);

        for (int i = 1; i < n; i++) {
            int delta = nums[i] - nums[i-1];
            int shift = max(0, delta);
            vector<long long> prefix(nums[i-1] + 2, 0);
            for (int v = 0; v <= nums[i-1]; v++) prefix[v+1] = (prefix[v] + dp[v]) % MOD;

            vector<long long> ndp(nums[i] + 1, 0);
            for (int v = 0; v <= nums[i]; v++) {
                int bound = v - shift;
                if (bound < 0) continue;
                bound = min(bound, nums[i-1]);
                ndp[v] = prefix[bound + 1];
            }
            dp = move(ndp);
        }

        long long ans = 0;
        for (long long x : dp) ans = (ans + x) % MOD;
        return (int)ans;
    }
};
