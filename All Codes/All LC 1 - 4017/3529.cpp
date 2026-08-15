// Link: https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
//  Approach: We can use the KMP algorithm to find all occurrences of the pattern in each row and column of the grid. We can keep track of the number of occurrences in each row and column using two 2D arrays, dhor and dver. Finally, we can iterate through the grid and count the number of cells that are part of both a horizontal and vertical occurrence of the pattern. We can do this by checking if the value in dhor and dver for each cell is greater than 0. If both values are greater than 0, we increment the count of overlapping cells. The final count will be the answer.
class Solution
{
public:
    int countCells(vector<vector<char>> &grid, string pattern)
    {
        int m = size(grid), n = size(grid[0]), k = size(pattern);
        vector<int> lps(k + 1);
        lps[0] = -1;
        int pos = 1, cnd = 0;
        while (pos < k)
        {
            if (pattern[pos] == pattern[cnd])
                lps[pos] = lps[cnd];
            else
            {
                lps[pos] = cnd;
                while (cnd != -1 && pattern[pos] != pattern[cnd])
                    cnd = lps[cnd];
            }
            ++pos, ++cnd;
        }
        lps[pos] = cnd;
        int i = 0, j = 0, l = 0;
        vector<vector<int>> dhor(m, vector<int>(n)), dver = dhor;
        while (i != m - 1 || j != n)
        {
            if (j == n)
                j = 0, ++i;
            if (grid[i][j] != pattern[l])
            {
                if (l == k)
                {
                    int z = i * n + j - l, pi = z / n, pj = z % n;
                    ++dhor[pi][pj], --dhor[i][j];
                }
                l = lps[l];
                if (l == -1)
                    ++j, ++l;
            }
            else
                ++j, ++l;
        }
        if (l == k)
        {
            int z = i * n + j - l, pi = z / n, pj = z % n;
            ++dhor[pi][pj];
        }
        i = 0, j = 0, l = 0;
        while (i != m || j != n - 1)
        {
            if (i == m)
                i = 0, ++j;
            if (grid[i][j] != pattern[l])
            {
                if (l == k)
                {
                    int z = j * m + i - l, pi = z % m, pj = z / m;
                    ++dver[pi][pj], --dver[i][j];
                }
                l = lps[l];
                if (l == -1)
                    ++i, ++l;
            }
            else
                ++i, ++l;
        }
        if (l == k)
        {
            int z = j * m + i - l, pi = z % m, pj = z / m;
            ++dver[pi][pj];
        }
        for (int i = 0, sum = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                sum += dhor[i][j], dhor[i][j] = sum;
            }
        }
        int ans = 0;
        for (int j = 0, sum = 0; j < n; ++j)
        {
            for (int i = 0; i < m; ++i)
            {
                sum += dver[i][j];
                if (sum != 0 && dhor[i][j] != 0)
                    ++ans;
            }
        }
        return ans;
    }
};