// Link: https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int best = 0;
        for (int m = 0; m < k; m++) {
            vector<int> dp(k, 0);
            for (int x : nums) {
                int rx = ((x % k) + k) % k;
                int need = ((m - rx) % k + k) % k;
                int cand = dp[need] + 1;
                dp[rx] = max(dp[rx], cand);
                best = max(best, dp[rx]);
            }
        }
        return best;
    }
};
