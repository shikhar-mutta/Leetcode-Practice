// Link: https://leetcode.com/problems/flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: DFS from start, replacing matching-color cells; guard against no-op when new color equals old.
class Solution {
    int m, n;
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int color) {
        if (r<0||r>=m||c<0||c>=n||image[r][c]!=oldColor) return;
        image[r][c] = color;
        dfs(image, r-1, c, oldColor, color);
        dfs(image, r+1, c, oldColor, color);
        dfs(image, r, c-1, oldColor, color);
        dfs(image, r, c+1, oldColor, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size(); n = image[0].size();
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;
        dfs(image, sr, sc, oldColor, color);
        return image;
    }
};
