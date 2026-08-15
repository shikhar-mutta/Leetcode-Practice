// Link: https://leetcode.com/problems/sum-of-special-evenly-spaced-elements-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        int B = (int)sqrt((double)n) + 1;

        vector<vector<long long>> dp(B + 1, vector<long long>(n, 0));
        for (int y = 1; y <= B; y++) {
            for (int x = n - 1; x >= 0; x--) {
                dp[y][x] = nums[x];
                if (x + y < n) dp[y][x] = (dp[y][x] + dp[y][x+y]) % MOD;
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            if (y <= B) {
                ans.push_back((int)dp[y][x]);
            } else {
                long long sum = 0;
                for (int i = x; i < n; i += y) sum = (sum + nums[i]) % MOD;
                ans.push_back((int)sum);
            }
        }
        return ans;
    }
};
