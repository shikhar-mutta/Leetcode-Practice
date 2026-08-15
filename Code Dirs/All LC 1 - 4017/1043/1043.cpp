// Link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int maxVal = 0;
            for (int len = 1; len <= k && i - len >= 0; len++) {
                maxVal = max(maxVal, arr[i - len]);
                dp[i] = max(dp[i], dp[i - len] + maxVal * len);
            }
        }
        return dp[n];
    }
};
