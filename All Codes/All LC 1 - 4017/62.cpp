// Link: https://leetcode.com/problems/unique-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n). SC: O(n)
// Approach: Dynamic Programming.
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[j] += dp[j - 1];
        return dp[n - 1];
    }
};
