// Link: https://leetcode.com/problems/minimum-moves-to-spread-stones-over-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int,int>> src, dst;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] > 1) for (int c = 0; c < grid[i][j] - 1; c++) src.push_back({i, j});
                if (grid[i][j] == 0) dst.push_back({i, j});
            }
        int n = src.size();
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0);
        int best = INT_MAX;
        do {
            int cost = 0;
            for (int i = 0; i < n; i++)
                cost += abs(src[i].first - dst[perm[i]].first) + abs(src[i].second - dst[perm[i]].second);
            best = min(best, cost);
        } while (next_permutation(perm.begin(), perm.end()));
        return n == 0 ? 0 : best;
    }
};
