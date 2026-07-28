// Link: https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(1)
// Approach: Find the bounding box of all 1-cells (min/max row and column
// indices containing a 1); the minimum covering rectangle's area is its
// width times height.
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int left = INT_MAX, right = INT_MIN, top = INT_MAX, bottom = INT_MIN;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
            }
        }
        return (right-left+1) * (bottom-top+1);
    }
};
