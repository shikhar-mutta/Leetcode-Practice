// Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev = grid[0];
        for (int i = 1; i < n; i++) {
            int min1 = INT_MAX, min1idx = -1, min2 = INT_MAX;
            for (int j = 0; j < n; j++) {
                if (prev[j] < min1) { min2 = min1; min1 = prev[j]; min1idx = j; }
                else if (prev[j] < min2) { min2 = prev[j]; }
            }
            vector<int> cur(n);
            for (int j = 0; j < n; j++) {
                cur[j] = grid[i][j] + (j == min1idx ? min2 : min1);
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
