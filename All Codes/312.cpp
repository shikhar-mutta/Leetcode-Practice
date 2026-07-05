// Link: https://leetcode.com/problems/burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^3), SC: O(n^2)
    // Approach: Dynamic Programming
    int maxCoins(vector<int> &nums)
    {
        // Pad with 1s; dp[i][j] = max coins bursting everything strictly
        // between i and j. Choose k = LAST balloon burst in (i,j): its
        // neighbors are then exactly i and j, earning a[i]*a[k]*a[j].
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++)
            a[i + 1] = nums[i];
        int m = n + 2;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int gap = 2; gap < m; gap++)
            for (int i = 0; i + gap < m; i++)
            {
                int j = i + gap;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = max(dp[i][j],
                                   dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
            }
        return dp[0][m - 1];
    }
};
