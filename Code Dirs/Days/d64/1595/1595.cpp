// Link: https://leetcode.com/problems/minimum-cost-to-connect-two-groups-of-points/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^m) SC: O(2^m)
// Approach: We can use dynamic programming to solve this problem. We can use a bitmask to represent the state of the second group of points. We can iterate through each point in the first group and for each point, we can iterate through each point in the second group and update the dp array. The dp array will store the minimum cost to connect the first i points in the first group to the second group of points represented by the bitmask. We can also keep track of the minimum cost to connect each point in the second group to any point in the first group. Finally, we can iterate through the dp array and for each state, we can add the minimum cost to connect the remaining points in the second group to any point in the first group. The answer will be the minimum cost to connect all points in the first group to the second group of points.
class Solution
{
private:
    int inf = 1e9;
    vector<int> dp, maxcol;

public:
    int connectTwoGroups(vector<vector<int>> &cost)
    {
        int size1 = cost.size(), size2 = cost[0].size();
        maxcol.assign(size2, inf);
        for (int i = 0; i < size2; i++)
        {
            for (int j = 0; j < size1; j++)
                maxcol[i] = min(maxcol[i], cost[j][i]);
        }
        int total = (1 << size2);
        dp.assign(total, inf);
        dp[0] = 0;
        for (int i = 0; i < size1; i++)
        {
            vector<int> ndp(total, inf);
            for (int mask = 0; mask < total; mask++)
            {
                if (dp[mask] == inf)
                    continue;
                for (int j = 0; j < size2; j++)
                {
                    int idx = mask | (1 << j);
                    ndp[idx] = min(ndp[idx], dp[mask] + cost[i][j]);
                }
            }
            dp = move(ndp);
        }
        int ans = inf;
        for (int mask = 0; mask < total; mask++)
        {
            int extra = 0;
            for (int i = 0; i < size2; i++)
            {
                if ((mask >> i) & 1)
                    continue;
                extra += maxcol[i];
            }
            ans = min(ans, dp[mask] + extra);
        }
        return ans;
    }
};
