// Link: https://leetcode.com/problems/largest-local-values-in-a-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) SC: O(n)
// Approach:
//  For each cell, check if it is a local maximum by comparing it with its neighbors within the range defined by its value. Use an auxiliary array to store the maximum values of each row to optimize the checking process.
class Solution
{
public:
    int countLocalMaximums(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> maxrow(n, 0);

        int maxv = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                maxrow[i] = max(maxrow[i], mat[i][j]);
            }

            maxv = max(maxv, maxrow[i]);
        }

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            if (maxrow[i] == 0)
                continue;

            for (int j = 0; j < m; j++)
            {
                int v = mat[i][j];
                if (v == 0)
                    continue;
                if (v == maxv)
                {
                    result++;
                    continue;
                }
                bool ok = true;
                int r1 = max(0, i - v);
                int r2 = min(n - 1, i + v);
                for (int r = r1; r <= r2 && ok; r++)
                {
                    if (maxrow[r] <= v)
                        continue;
                    int margin = (r == i - v || r == i + v);

                    int c1 = max(0, j - v + margin);
                    int c2 = min(m - 1, j + v - margin);
                    for (int c = c1; c <= c2; c++)
                    {
                        if (mat[r][c] > v)
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok)
                {
                    result++;
                }
            }
        }
        return result;
    }
};