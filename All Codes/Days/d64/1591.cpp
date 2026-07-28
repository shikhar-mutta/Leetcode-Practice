// Link: https://leetcode.com/problems/strange-printer-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size(), cols = targetGrid[0].size();
        unordered_map<int, array<int,4>> bound; // color -> minR,maxR,minC,maxC
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int c = targetGrid[i][j];
                if (!bound.count(c)) bound[c] = {i, i, j, j};
                else {
                    bound[c][0] = min(bound[c][0], i);
                    bound[c][1] = max(bound[c][1], i);
                    bound[c][2] = min(bound[c][2], j);
                    bound[c][3] = max(bound[c][3], j);
                }
            }
        }
        vector<int> colors;
        for (auto& [c, b] : bound) colors.push_back(c);
        vector<bool> removed(colors.size(), false);
        unordered_map<int,int> colorIdx;
        for (int i = 0; i < (int)colors.size(); i++) colorIdx[colors[i]] = i;

        int remaining = colors.size();
        while (remaining > 0) {
            bool progress = false;
            for (int ci = 0; ci < (int)colors.size(); ci++) {
                if (removed[ci]) continue;
                int c = colors[ci];
                auto& b = bound[c];
                bool ok = true;
                for (int i = b[0]; i <= b[1] && ok; i++) {
                    for (int j = b[2]; j <= b[3] && ok; j++) {
                        int cell = targetGrid[i][j];
                        if (cell == c) continue;
                        if (removed[colorIdx[cell]]) continue;
                        ok = false;
                    }
                }
                if (ok) { removed[ci] = true; remaining--; progress = true; }
            }
            if (!progress) return false;
        }
        return true;
    }
};
