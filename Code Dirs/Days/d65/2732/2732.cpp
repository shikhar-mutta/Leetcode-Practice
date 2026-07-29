// Link: https://leetcode.com/problems/find-a-good-subset-of-the-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rows*cols + unique^2), SC: O(rows*cols)
// Approach: a valid subset of size k needs each column sum <= floor(k/2). It's a known fact that
// if any valid subset exists, one of size 1 (an all-zero row) or size 2 (two rows whose bitmasks
// AND to 0) also exists — so checking those two cases suffices. Dedupe row bitmasks (rows*cols
// bounded by 1e5, so distinct masks stay manageable) and check all pairs for disjointness.
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            bool allZero = true;
            for (int j = 0; j < n; j++) if (grid[i][j]) { allZero = false; break; }
            if (allZero) return {i};
        }

        unordered_map<int,int> maskFirst;
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) if (grid[i][j]) mask |= (1 << j);
            if (!maskFirst.count(mask)) maskFirst[mask] = i;
        }

        vector<pair<int,int>> masks(maskFirst.begin(), maskFirst.end());
        for (size_t a = 0; a < masks.size(); a++) {
            for (size_t b = a+1; b < masks.size(); b++) {
                if ((masks[a].first & masks[b].first) == 0) {
                    int i1 = masks[a].second, i2 = masks[b].second;
                    if (i1 > i2) swap(i1, i2);
                    return {i1, i2};
                }
            }
        }
        return {};
    }
};
