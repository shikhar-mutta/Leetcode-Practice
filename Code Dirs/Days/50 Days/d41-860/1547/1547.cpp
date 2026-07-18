// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3), SC: O(n^2)
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the minimum cost to cut the stick between positions i and j. We can iterate through all possible cuts and calculate the minimum cost for each segment by considering all possible first cuts. Finally, we return the minimum cost to cut the entire stick.
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        // Order of cuts is ours to choose => interval DP on cut positions.
        // pos = {0, cuts..., n}; dp[i][j] = min cost to fully cut the
        // segment (pos[i], pos[j]); each first cut k costs the segment length.
        vector<int> pos = cuts;
        pos.push_back(0);
        pos.push_back(n);
        sort(pos.begin(), pos.end());
        int m = pos.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int gap = 2; gap < m; gap++)
            for (int i = 0; i + gap < m; i++)
            {
                int j = i + gap;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                dp[i][j] += pos[j] - pos[i];
            }
        return dp[0][m - 1];
    }
};
