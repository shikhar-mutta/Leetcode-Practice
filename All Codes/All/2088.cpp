// Link: https://leetcode.com/problems/count-fertile-pyramids-in-a-land/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(n)
//   Approach: For each row, maintain the height of the pyramid that can be formed at each column. Use dynamic programming to update the height based on the previous row's heights and the current row's values. Count the number of pyramids by summing the heights of the pyramids at each column, subtracting 1 to exclude the apex of the pyramid. Repeat the process for the inverted grid to count the inverted pyramids and return the total count.
int widthFor(int h)
{
    // 1 1
    // 2 3
    // 3 5
    // 4 7
    return h * 2 - 1;
}
int heightFor(int w)
{
    return (w + 1) / 2;
}
int doCount(span<const vector<int>> grid)
{
    const int m = grid.size(), n = grid[0].size();
    vector<int> pH(n), nH(n);
    for (int j = 0; j < n; ++j)
        nH[j] = grid[0][j];
    int total = 0;
    for (int i = 1; i < m; ++i)
    {
        swap(pH, nH);
        for (int j = 0, len = 0; j < n; ++j)
        {
            if (!grid[i][j])
            {
                nH[j] = 0;
                len = 0;
                continue;
            }
            nH[j] = 1;
            ++len;
            if (j == 0)
                continue;
            if (len >= widthFor(pH[j - 1] + 1))
            {
                nH[j] = pH[j - 1] + 1;
            }
            else
            {
                nH[j] = heightFor(len);
            }
            // println("h[{}][{}]={}", i, j, nH[j]);
            total += (nH[j] - 1);
        }
    }
    return total;
}

class Solution
{
public:
    int countPyramids(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        if (m < 2)
            return 0;
        // 2: 1
        // 3: 3+1
        // 4: 5+3+1
        // 3*1 + 2*3 + 1*5
        int total = doCount(grid);
        // println("{} ================================================================================", total);
        std::ranges::reverse(grid);
        total += doCount(grid);
        return total;
    }
};