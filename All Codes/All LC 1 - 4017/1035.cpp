// Link: https://leetcode.com/problems/uncrossed-lines/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) where n is the size of nums1 and m is the size of nums2
// SC: O(n*m) where n is the size of nums1 and m is the size of nums2
//  Approach:
//  1. We can use dynamic programming to solve this problem.
//  2. We can create a 2D array dp of size (n+1) x (m+1) where dp[i][j] represents the maximum number of uncrossed lines that can be drawn between the first i elements of nums1 and the first j elements of nums2.
//  3. We can initialize the first row and first column of dp to 0
//  4. We can iterate through the elements of nums1 and nums2 and fill the dp array using the following recurrence relation:
//     - If nums1[i-1] == nums2[j-1], then dp[i][j] = 1 + dp[i-1][j-1]
//     - Else, dp[i][j] = max(dp[i-1][j], dp[i][j-1])
//  5. Finally, we can return dp[n][m] which represents the maximum number of uncrossed lines that can be drawn between nums1 and nums2.
class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};