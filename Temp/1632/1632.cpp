// Link: https://leetcode.com/problems/rank-transform-of-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent_, rnk_;
    int find(int x) {
        while (parent_[x] != x) { parent_[x] = parent_[parent_[x]]; x = parent_[x]; }
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (rnk_[ra] < rnk_[rb]) swap(ra, rb);
        parent_[rb] = ra;
        if (rnk_[ra] == rnk_[rb]) rnk_[ra]++;
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        map<int, vector<pair<int,int>>> byVal;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                byVal[matrix[i][j]].push_back({i, j});

        vector<int> rowMax(rows, 0), colMax(cols, 0);
        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        for (auto& [val, cells] : byVal) {
            int n = rows + cols;
            parent_.assign(n, 0);
            rnk_.assign(n, 0);
            iota(parent_.begin(), parent_.end(), 0);
            for (auto& [r, c] : cells) unite(r, rows + c);

            unordered_map<int, int> compBest;
            for (auto& [r, c] : cells) {
                int root = find(r);
                int best = max(rowMax[r], colMax[c]);
                compBest[root] = max(compBest[root], best);
            }
            for (auto& [r, c] : cells) {
                int root = find(r);
                int rank = compBest[root] + 1;
                ans[r][c] = rank;
                rowMax[r] = max(rowMax[r], rank);
                colMax[c] = max(colMax[c], rank);
            }
        }
        return ans;
    }
};
