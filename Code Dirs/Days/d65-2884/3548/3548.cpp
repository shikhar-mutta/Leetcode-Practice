// Link: https://leetcode.com/problems/equal-sum-grid-partition-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(r * c) where r is the number of rows and c is the number of columns in the grid.
// SC: O(M) where M is the maximum value in the grid.
// Approach: The solution uses a greedy approach to check for possible partitions of the grid. It calculates the total sum of the grid and iterates through the rows and columns to find potential horizontal and vertical cuts. For each cut, it checks if the sums of the two resulting parts are equal or if the difference between them can be matched by any element in the grid. The use of bitsets allows for efficient tracking of seen values during the iteration.
static const int M = 1e5 + 1;
static bitset<M> tSeen, bSeen, lSeen, rSeen;

class Solution
{
public:
    static bool canPartitionGrid(vector<vector<int>> &grid)
    {
        const int r = grid.size(), c = grid[0].size();
        long long Tsum = 0;

        tSeen.reset();
        bSeen.reset();
        lSeen.reset();
        rSeen.reset();
        int xMax = 0;
        for (auto &row : grid)
        {
            for (int x : row)
            {
                Tsum += x;
                xMax = max(x, xMax);
            }
        }

        // Horizontal Cuts
        long long top = 0;
        // First pass for Top removals
        for (int i = 0; i < r - 1; i++)
        {
            for (int x : grid[i])
            {
                top += x;
                tSeen[x] = 1;
            }
            long long bot = Tsum - top;
            if (top == bot)
                return 1;

            long long d = top - bot;
            if (d > 0 && d <= xMax)
            {
                if (i > 0 && c > 1)
                {
                    if (tSeen[d])
                        return 1;
                }
                else if (grid[0][0] == d || grid[i][c - 1] == d)
                    return 1;
            }
        }

        long long bot = 0;
        // Second pass for Bottom removals
        for (int i = r - 1; i >= 1; i--)
        {
            for (int x : grid[i])
            {
                bot += x;
                bSeen[x] = 1;
            }
            long long topS = Tsum - bot;
            long long d = bot - topS;
            if (d > 0 && d <= xMax)
            {
                if ((r - 1 - i) > 0 && c > 1)
                {
                    if (bSeen[d])
                        return 1;
                }
                else if (grid[i][0] == d || grid[r - 1][c - 1] == d)
                    return 1;
            }
        }

        // Vertical Cuts
        long long left = 0;
        for (int j = 0; j < c - 1; j++)
        {
            for (int i = 0; i < r; i++)
            {
                int x = grid[i][j];
                left += x;
                lSeen[x] = 1;
            }
            long long right = Tsum - left;
            if (left == right)
                return 1;

            long long d = left - right;
            if (d > 0 && d <= xMax)
            {
                if (r > 1 && j > 0)
                {
                    if (lSeen[d])
                        return 1;
                }
                else if (grid[0][0] == d || grid[r - 1][j] == d)
                    return 1;
            }
        }

        long long right = 0;
        for (int j = c - 1; j >= 1; j--)
        {
            for (int i = 0; i < r; i++)
            {
                int x = grid[i][j];
                right += x;
                rSeen[x] = 1;
            }
            long long leftS = Tsum - right;
            long long d = right - leftS;
            if (d > 0 && d <= xMax)
            {
                if (r > 1 && (c - 1 - j) > 0)
                {
                    if (rSeen[d])
                        return 1;
                }
                else if (grid[0][j] == d || grid[r - 1][c - 1] == d)
                    return 1;
            }
        }
        return 0;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
