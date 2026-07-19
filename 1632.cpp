// Link: https://leetcode.com/problems/rank-transform-of-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*log(m*n)) where m is the number of rows and n is the number of columns in the matrix
// SC: O(m*n) where m is the number of rows and n is the number of columns in the matrix
// Approach:
//  1. Create a map to group the cells of the matrix based on their values.
//  2. For each group of cells with the same value, use a union-find data structure to connect the cells in the same row and column.
//  3. For each group of cells, find the maximum rank of the connected components and assign the rank to the cells in the group.
//  4. Return the transformed matrix with the assigned ranks.
class Solution
{
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> groups;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                groups[matrix[i][j]].push_back({i, j});

        vector<int> rowMax(m, 0), colMax(n, 0), parent(m + n);
        auto find = [&](int x)
        {
            while (parent[x] != x)
                x = parent[x] = parent[parent[x]];
            return x;
        };

        vector<vector<int>> res(m, vector<int>(n));
        for (auto &[val, cells] : groups)
        {
            for (auto &[i, j] : cells)
            {
                parent[i] = i;
                parent[m + j] = m + j;
            }
            for (auto &[i, j] : cells)
                parent[find(i)] = find(m + j);

            unordered_map<int, int> best;
            for (auto &[i, j] : cells)
            {
                int r = find(i);
                best[r] = max({best[r], rowMax[i], colMax[j]});
            }
            for (auto &[i, j] : cells)
            {
                int r = best[find(i)] + 1;
                res[i][j] = r;
                rowMax[i] = colMax[j] = r;
            }
        }
        return res;
    }
};
