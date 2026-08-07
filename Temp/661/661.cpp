// Link: https://leetcode.com/problems/image-smoother/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: for each cell, average all valid 3x3 neighbors (rounded down).
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i+di, nj = j+dj;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            count++;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return res;
    }
};
