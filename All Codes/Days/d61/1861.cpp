// Link: https://leetcode.com/problems/rotating-the-box/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(m*n)
//  Approach:
//    1. We can create a new grid to store the rotated box.
//    2. We can iterate through each row of the box and count the number of stones ('#') and the position of the obstacles ('*').
//    3. For each obstacle, we can place the stones in the new grid starting from the rightmost position of the current row and moving left until we have placed all the stones or reached the obstacle.
//    4. After processing all obstacles in the row, we can place any remaining stones in the new grid starting from the rightmost position of the current row and moving left until we have placed all the stones.
//    5. Finally, we can return the new grid as the rotated box.
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ret(n, vector<char>(m, '.'));
        for (int r = 0; r < m; ++r)
        {
            int stones = 0;
            for (int c = 0; c < n; ++c)
            {
                char cur = boxGrid[r][c];
                if (cur == '#')
                    stones++;
                else if (cur == '*')
                {
                    ret[c][m - r - 1] = '*';
                    if (stones > 0)
                    {
                        for (int i = c - 1; i >= (c - stones); --i)
                            ret[i][m - r - 1] = '#';
                    }
                    stones = 0;
                }
            }
            if (stones > 0)
            {
                for (int i = n - 1; i >= (n - stones); --i)
                    ret[i][m - r - 1] = '#';
            }
        }
        return ret;
    }
};