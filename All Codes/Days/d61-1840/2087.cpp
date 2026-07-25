// Link: https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), where n is the number of rows and m is the number of columns in the grid.
// SC: O(1), as we are using a constant amount of extra space.
//  Approach:
//   1. We first find the minimum and maximum row and column indices between the start and home positions.
//   2. We then iterate through the rows and columns between these indices and accumulate the costs from the rowCosts and colCosts arrays.
//   3. Finally, we subtract the costs of the starting cell from the total cost and return the result.
class Solution
{
public:
    int minCost(vector<int> &startPos, vector<int> &homePos,
                vector<int> &rowCosts, vector<int> &colCosts)
    {
        int cost = 0;
        int r1 = min(startPos[0], homePos[0]),
            r2 = max(startPos[0], homePos[0]);
        int c1 = min(startPos[1], homePos[1]),
            c2 = max(startPos[1], homePos[1]);

        for (int r = r1; r <= r2; ++r)
            cost += rowCosts[r];
        for (int c = c1; c <= c2; ++c)
            cost += colCosts[c];
        cost -= rowCosts[startPos[0]] +
                colCosts[startPos[1]]; // exclude the starting cell
        return cost;
    }
};
