// Link: https://leetcode.com/problems/island-perimeter/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(1)
// Approach: for each land cell add 4, subtract 2 for each land neighbor
// above or to the left (avoids double counting)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1) continue;
                perimeter += 4;
                if (i > 0 && grid[i-1][j] == 1) perimeter -= 2;
                if (j > 0 && grid[i][j-1] == 1) perimeter -= 2;
            }
        }
        return perimeter;
    }
};
