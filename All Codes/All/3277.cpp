// Link: https://leetcode.com/problems/maximum-xor-score-subarray-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the nums array
// SC: O(n^2) where n is the length of the nums array
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the maximum xor score of the subarray nums[i...j]. We can fill the dp array by iterating through all possible subarrays and calculating the maximum xor score for each subarray. Finally, we can return the maximum xor score for each query by accessing the dp array.
class Solution
{
public:
    vector<int> maximumSubarrayXor(vector<int> &nums,
                                   vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = n - 1; l >= 0; --l)
        {
            dp[l][l] = nums[l];
            for (int r = l + 1; r < n; ++r)
                dp[l][r] = dp[l][r - 1] ^ dp[l + 1][r];
        }
        for (int l = n - 1; l >= 0; --l)
        {
            for (int r = l + 1; r < n; ++r)
                dp[l][r] = max(dp[l][r], max(dp[l][r - 1], dp[l + 1][r]));
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            ans[i] = dp[queries[i][0]][queries[i][1]];
        }

        return ans;
    }
};