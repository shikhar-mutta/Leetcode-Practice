// Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(1)
// Approach:
//   1. We define a TRANS array that represents the valid transitions between different types of streets based on the direction of entry.
//   2. We also define a DIRS array that represents the four possible directions of movement (up, right, down, left).
//   3. The START array indicates the possible starting directions for each type of street in the grid.
//   4. We implement a check function that takes a direction as input and simulates the movement through the grid based on the current direction and the type of street at each cell. If we reach the bottom-right corner of the grid, we return true; otherwise, we return false if we encounter an invalid transition or go out of bounds.
//   5. In the hasValidPath function, we retrieve the possible starting directions for the street at the top-left corner of the grid and call the check function for each starting direction. If either call returns true, we return true; otherwise, we return false.
class Solution
{
    static constexpr int TRANS[6][4] = {{-1, 1, -1, 3}, {0, -1, 2, -1}, {3, 2, -1, -1}, {1, -1, -1, 2}, {-1, 0, 3, -1}, {-1, -1, 1, 0}};
    static constexpr int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static constexpr int START[6][2] = {{1, 3}, {0, 2}, {2, 3}, {1, 2}, {0, 3}, {0, 1}};

public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1)
            return true;
        auto check = [&](int di) -> bool
        {
            if (di == -1)
                return false;
            int r = DIRS[di][0], c = DIRS[di][1];
            while (r >= 0 && r < m && c >= 0 && c < n)
            {
                di = TRANS[grid[r][c] - 1][di];
                if (di == -1 || (r == 0 && c == 0))
                    return false;
                if (r == m - 1 && c == n - 1)
                    return true;
                r += DIRS[di][0];
                c += DIRS[di][1];
            }
            return false;
        };
        const int *s = START[grid[0][0] - 1];
        return check(s[0]) || check(s[1]);
    }
};