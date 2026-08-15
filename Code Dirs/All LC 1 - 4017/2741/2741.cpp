// Link: https://leetcode.com/problems/special-permutations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<vector<long long>> dp(1 << n, vector<long long>(n, -1));

        function<long long(int,int)> solve = [&](int mask, int last) -> long long {
            if (mask == (1 << n) - 1) return 1;
            if (dp[mask][last] != -1) return dp[mask][last];

            long long total = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) continue;
                if (nums[last] % nums[i] == 0 || nums[i] % nums[last] == 0) {
                    total = (total + solve(mask | (1 << i), i)) % MOD;
                }
            }
            return dp[mask][last] = total;
        };

        long long ans = 0;
        for (int i = 0; i < n; i++) ans = (ans + solve(1 << i, i)) % MOD;
        return (int)ans;
    }
};
