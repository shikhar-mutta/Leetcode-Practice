// Link: https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        const int BITS = 128;

        // leftOR[i] = achievable OR values using exactly k elements from nums[0..i-1]
        vector<vector<bool>> leftOR(n + 1, vector<bool>(BITS, false));
        {
            vector<vector<bool>> dp(k + 1, vector<bool>(BITS, false));
            dp[0][0] = true;
            for (int i = 0; i <= n; i++) {
                leftOR[i] = dp[k];
                if (i == n) break;
                for (int c = k; c >= 1; c--) {
                    for (int o = 0; o < BITS; o++) {
                        if (dp[c-1][o]) dp[c][o | nums[i]] = true;
                    }
                }
            }
        }

        // rightOR[i] = achievable OR values using exactly k elements from nums[i..n-1]
        vector<vector<bool>> rightOR(n + 1, vector<bool>(BITS, false));
        {
            vector<vector<bool>> dp(k + 1, vector<bool>(BITS, false));
            dp[0][0] = true;
            for (int i = n; i >= 0; i--) {
                rightOR[i] = dp[k];
                if (i == 0) break;
                int idx = i - 1;
                for (int c = k; c >= 1; c--) {
                    for (int o = 0; o < BITS; o++) {
                        if (dp[c-1][o]) dp[c][o | nums[idx]] = true;
                    }
                }
            }
        }

        int best = 0;
        for (int i = k; i <= n - k; i++) {
            for (int a = 0; a < BITS; a++) {
                if (!leftOR[i][a]) continue;
                for (int b = 0; b < BITS; b++) {
                    if (!rightOR[i][b]) continue;
                    best = max(best, a ^ b);
                }
            }
        }
        return best;
    }
};
