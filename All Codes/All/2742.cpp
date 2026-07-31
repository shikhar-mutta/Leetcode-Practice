// Link: https://leetcode.com/problems/painting-the-walls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the number of walls, SC: O(n) where n is the number of walls
//  Approach: We can use a dynamic programming approach to find the minimum cost to paint all the walls. We will define a dp array where dp[i] represents the minimum cost to paint the first i walls. We will iterate through each wall and for each wall, we will iterate through the dp array in reverse order to update the minimum cost for painting the walls. For each wall, we will calculate the new index nj which represents the number of walls that can be painted after painting the current wall, and update the dp[nj] with the minimum cost. Finally, we will return dp[n] which represents the minimum cost to paint all the walls.
class Solution
{
public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = n; j >= 0; j--)
            {
                if (dp[j] == INT_MAX)
                    continue;
                int nj = min(n, j + 1 + time[i]);
                dp[nj] = min(dp[nj], dp[j] + cost[i]);
            }
        }
        return dp[n];
    }
};
