// Link: https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(cols * 10^2), SC: O(cols * 10)
// Approach: Column-wise DP over digit values 0-9. For each column, changing
// it entirely to value j costs (rows - count of j in that column) plus the
// best cost from the previous column using any value != j (tracked via
// running min/second-min cost across all 10 values, so each column is O(10)
// instead of O(10^2)).
class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int colCount[1000][10] = {};
        int cols = grid[0].size();
        int rows = grid.size();
        for (int i = 0; i < rows; i++)
        {
            const vector<int>& row = grid[i];
            for (int j = 0; j < cols; j++)
                colCount[j][row[j]] ++;
        }

        int minCostTotal = 0;
        int secondMinCostTotal = 0;
        int minVal = 10;

        for (int i = 0; i < cols; i++)
        {
            int newMinCost = 0x7fffffff;
            int newSecondCost = 0x7fffffff;
            int newMinVal = 10;

            for (int j = 0; j < 10; j++)
            {
                int cost = rows - colCount[i][j];
                cost += (j == minVal) ? secondMinCostTotal : minCostTotal;
                if (cost < newSecondCost)
                {
                    if (cost < newMinCost)
                    {
                        newSecondCost = newMinCost;
                        newMinCost = cost;
                        newMinVal = j;
                    }
                    else
                        newSecondCost = cost;
                }
            }

            minCostTotal = newMinCost;
            secondMinCostTotal = newSecondCost;
            minVal = newMinVal;
        }

        return minCostTotal;
    }
};
