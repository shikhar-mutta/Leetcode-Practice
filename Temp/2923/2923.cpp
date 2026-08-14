// Link: https://leetcode.com/problems/find-champion-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            bool win = true;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] == 0) { win = false; break; }
            }
            if (win) return i;
        }
        return -1;
    }
};
