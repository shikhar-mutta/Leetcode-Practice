// Link: https://leetcode.com/problems/grid-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of columns in the grid
// SC: O(1) as we are using constant space
// Approach:
// 1. We will keep track of the remaining points in the top row and the collected points in the bottom row.
// 2. We will iterate through each column and update the remaining points in the top row and the collected points in the bottom row.
// 3. We will calculate the maximum points that the second robot can collect at each column and keep track of the minimum of these maximum points.
// 4. Finally, we will return the minimum of the maximum points that the second robot can collect.
class Solution
{
public:
    long long gridGame(std::vector<std::vector<int>> &grid)
    {
        int n = grid[0].size();
        long long topRemaining = 0;
        for (int c = 0; c < n; ++c)
        {
            topRemaining += grid[0][c];
        }

        long long bottomCollected = 0;
        long long minSecondRobotPoints = LLONG_MAX;

        for (int c = 0; c < n; ++c)
        {
            topRemaining -= grid[0][c];
            long long secondRobotPoints =
                std::max(topRemaining, bottomCollected);
            minSecondRobotPoints =
                std::min(minSecondRobotPoints, secondRobotPoints);
            bottomCollected += grid[1][c];
        }

        return minSecondRobotPoints;
    }
};