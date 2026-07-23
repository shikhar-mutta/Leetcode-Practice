// Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^3) where n is the number of vertices in the polygon
    // SC: O(n^2) for the dp array
    //  Approach:
    //  1. We can use dynamic programming to solve this problem.
    //  2. We can create a 2D dp array of size n x n
    //  3. We can iterate through the lengths of the sub-polygons from 3 to n.
    //  4. For each sub-polygon, we can iterate through the possible vertices to form a triangle and calculate the score of that triangle.
    //  5. We can then update the dp array with the minimum score for that sub-polygon.
    //  6. Finally, we can return the value in dp[0][n-1] which will give us the minimum score triangulation of the entire polygon.
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j],
                                   dp[i][k] +
                                       dp[k][j] +
                                       values[i] * values[k] * values[j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};