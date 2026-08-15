// Link: https://leetcode.com/problems/strange-printer-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size(), cols = targetGrid[0].size();
        unordered_map<int, array<int,4>> bounds; // minR,maxR,minC,maxC
        unordered_set<int> colors;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int c = targetGrid[i][j];
                colors.insert(c);
                if (!bounds.count(c)) bounds[c] = {i, i, j, j};
                else {
                    bounds[c][0] = min(bounds[c][0], i);
                    bounds[c][1] = max(bounds[c][1], i);
                    bounds[c][2] = min(bounds[c][2], j);
                    bounds[c][3] = max(bounds[c][3], j);
                }
            }
        }

        unordered_set<int> removed;
        int total = colors.size();

        for (int iter = 0; iter < total; iter++) {
            bool foundRemovable = false;
            for (int c : colors) {
                if (removed.count(c)) continue;
                auto& b = bounds[c];
                bool canRemove = true;
                for (int i = b[0]; i <= b[1] && canRemove; i++) {
                    for (int j = b[2]; j <= b[3]; j++) {
                        int val = targetGrid[i][j];
                        if (val != c && !removed.count(val)) { canRemove = false; break; }
                    }
                }
                if (canRemove) {
                    removed.insert(c);
                    foundRemovable = true;
                }
            }
            if (!foundRemovable) break;
        }
        return (int)removed.size() == total;
    }
};
