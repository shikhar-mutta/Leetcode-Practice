// Link: https://leetcode.com/problems/lonely-pixel-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m+n)
// Approach: count black pixels per row and column, a pixel is lonely if
// its row and column each have exactly 1 black pixel
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> rowCount(m, 0), colCount(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (picture[i][j] == 'B') { rowCount[i]++; colCount[j]++; }

        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (picture[i][j] == 'B' && rowCount[i] == 1 && colCount[j] == 1) count++;
        return count;
    }
};
