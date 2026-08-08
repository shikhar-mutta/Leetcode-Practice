// Link: https://leetcode.com/problems/largest-sum-of-averages/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * k) SC: O(n)
// Approach: dp[j][i] = best sum of averages splitting nums[i:] into j groups. Base case dp[1][i] = average of nums[i:]. Transition tries every split point for the first group.
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n+1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
        auto avg = [&](int i, int j) { return (prefix[j] - prefix[i]) / (j - i); };

        vector<double> dp(n);
        for (int i = 0; i < n; i++) dp[i] = avg(i, n);

        for (int groups = 2; groups <= k; groups++) {
            vector<double> ndp(n);
            for (int i = 0; i < n; i++) {
                ndp[i] = dp[i]; // fallback: use fewer groups (last group absorbs rest)
                for (int j = i+1; j < n; j++) {
                    ndp[i] = max(ndp[i], avg(i, j) + dp[j]);
                }
            }
            dp = ndp;
        }
        return dp[0];
    }
};
