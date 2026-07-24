// Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
//  Approach:
//  1. We will use union find to keep track of the connected components in the grid.
//  2. We will iterate through the grid and for each cell, we will check if it is connected to its top and left neighbors. If it is, we will unite them.
//  3. If the two cells are already connected, we have found a cycle and we will return true.
//  4. If we finish iterating through the grid and do not find a cycle, we will return false.
class UnionFind
{
public:
    vector<int> parent;
    UnionFind(int n)
    {
        parent.resize(n);
        iota(begin(parent), end(parent), 0);
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

    void unite(int x, int y) { parent[y] = x; }

    bool findAndUnite(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX != parentY)
        {
            unite(parentX, parentY);
            return true;
        }

        return false;
    }
};

class Solution
{
public:
    bool containsCycle(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        UnionFind uf(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0 && grid[i][j] == grid[i - 1][j])
                {
                    if (!uf.findAndUnite(i * n + j, (i - 1) * n + j))
                        return true;
                }

                if (j > 0 && grid[i][j] == grid[i][j - 1])
                {
                    if (!uf.findAndUnite(i * n + j, i * n + j - 1))
                        return true;
                }
            }
        }

        return false;
    }
};
