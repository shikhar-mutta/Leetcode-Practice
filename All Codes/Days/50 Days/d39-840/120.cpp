// Link: https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n)
    // Approach: Bottom-up DP
    int minimumTotal(vector<vector<int>> &triangle)
    {
        // bottom-up: dp[j] = min path sum from row i, index j to the bottom
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        return dp[0];
    }
};
