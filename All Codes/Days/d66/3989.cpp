// Link: https://leetcode.com/problems/maximum-consistent-columns-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * m)  SC: O(n)
// Approach: We can use dynamic programming to solve this problem. We can use a dp array to store the maximum length of consistent columns ending at each column. We can iterate through each column and for each column, we can check all previous columns to see if they can be extended to the current column. If they can be extended, we update the dp array accordingly. Finally, we return the maximum value in the dp array as the answer.
class Solution
{
public:
    int maxConsistentColumns(vector<vector<int>> &grid, int limit)
    {
        int n = grid[0].size(); 
        vector<int> dp(n, 1);   

        for (int c = 0; c < n; c++)
        {
            for (int i = c - 1; i >= 0; i--)
            {
                if (dp[i] + 1 > dp[c])
                {
                    bool good = true;

                    for (const auto &r : grid)
                    {
                        if (abs(r[c] - r[i]) > limit)
                        {
                            good = false;
                            break;
                        }
                    }

                    if (good)
                    {
                        dp[c] = dp[i] + 1;
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
