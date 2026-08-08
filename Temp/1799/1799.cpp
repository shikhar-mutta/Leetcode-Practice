// Link: https://leetcode.com/problems/maximize-score-after-n-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1 << n, 0);
        for (int mask = 1; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            if (cnt % 2 != 0) continue;
            int op = cnt / 2;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                for (int j = i + 1; j < n; j++) {
                    if (!(mask & (1 << j))) continue;
                    int prevMask = mask ^ (1 << i) ^ (1 << j);
                    int score = op * gcd(nums[i], nums[j]);
                    dp[mask] = max(dp[mask], dp[prevMask] + score);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};
