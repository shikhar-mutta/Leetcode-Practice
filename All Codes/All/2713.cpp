// Link: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n log(m * n)), SC: O(m + n) where m is the number of rows and n is the number of columns in the matrix
//  Approach: We can use a greedy approach to find the maximum number of strictly increasing cells in the matrix. We will first sort the cells of the matrix based on their values. Then, we will iterate through the sorted cells and keep track of the maximum number of strictly increasing cells that can be reached from each row and column. We will use two arrays to store the maximum number of strictly increasing cells that can be reached from each row and column. For each cell, we will check if the value of the cell is greater than the previous value in the same row or column. If it is, we will update the maximum number of strictly increasing cells that can be reached from that row or column. Finally, we will return the maximum number of strictly increasing cells that can be reached from any row or column. The key insight is that we can use the sorted order of the cells to ensure that we are always considering the maximum number of strictly increasing cells that can be reached from each row and column.
class Solution
{
public:
    int maxIncreasingCells(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<tuple<int, int, int>> vmat(m * n);
        int idx{0};
        for (int i{0}; i < m; ++i)
        {
            for (int j{0}; j < n; ++j)
            {
                vmat[idx++] = {mat[i][j], i, j};
            }
        }

        sort(vmat.begin(), vmat.end());

        vector<pair<int, int>> nvis_row(m, {0, 0}), nvis_col(n, {0, 0});
        vector<int> prev_row(m, INT_MIN), prev_col(n, INT_MIN);

        for (auto [v, i, j] : vmat)
        {
            int vis_row = prev_row[i] != v ? nvis_row[i].first + 1
                                           : nvis_row[i].second + 1;
            int vis_col = prev_col[j] != v ? nvis_col[j].first + 1
                                           : nvis_col[j].second + 1;
            int vis = max(vis_row, vis_col);

            if (prev_row[i] != v)
            {
                nvis_row[i].second = nvis_row[i].first;
                prev_row[i] = v;
            }

            if (prev_col[j] != v)
            {
                nvis_col[j].second = nvis_col[j].first;
                prev_col[j] = v;
            }

            nvis_row[i].first = max(nvis_row[i].first, vis);
            nvis_col[j].first = max(nvis_col[j].first, vis);
        }

        return max((*max_element(nvis_row.begin(), nvis_row.end())).first,
                   (*max_element(nvis_col.begin(), nvis_col.end())).first);
    }
};
