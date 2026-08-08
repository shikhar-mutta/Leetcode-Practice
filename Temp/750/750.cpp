// Link: https://leetcode.com/problems/number-of-corner-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rows * cols^2) SC: O(cols^2)
// Approach: for each row, examine all pairs of columns with a 1; increment a count map for that column pair. Each time a pair has already been seen k times, it forms k new rectangles with the current row, so add k to the answer before incrementing.
class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        map<pair<int,int>, int> pairCount;
        int total = 0;
        for (int r = 0; r < m; r++) {
            vector<int> cols;
            for (int c = 0; c < n; c++) if (grid[r][c] == 1) cols.push_back(c);
            for (int i = 0; i < (int)cols.size(); i++) {
                for (int j = i+1; j < (int)cols.size(); j++) {
                    auto key = make_pair(cols[i], cols[j]);
                    total += pairCount[key];
                    pairCount[key]++;
                }
            }
        }
        return total;
    }
};
