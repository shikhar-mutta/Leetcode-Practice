// Link: https://leetcode.com/problems/find-maximum-non-decreasing-array-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

        vector<int> dp(n + 1, 0);
        vector<long long> endSum(n + 1, LLONG_MIN / 2);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (prefix[i] - prefix[j] >= endSum[j]) {
                    int cand = dp[j] + 1;
                    long long candEnd = prefix[i] - prefix[j];
                    if (cand > dp[i] || (cand == dp[i] && candEnd < endSum[i])) {
                        dp[i] = cand;
                        endSum[i] = candEnd;
                    }
                }
            }
        }
        return dp[n];
    }
};
