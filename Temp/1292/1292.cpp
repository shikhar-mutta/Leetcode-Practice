// Link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pre[i+1][j+1] = mat[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j];

        auto sumOk = [&](int side) {
            for (int i = 0; i + side <= m; i++) {
                for (int j = 0; j + side <= n; j++) {
                    int sum = pre[i+side][j+side] - pre[i][j+side] - pre[i+side][j] + pre[i][j];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int best = 0;
        for (int side = 1; side <= min(m, n); side++) {
            if (sumOk(side)) best = side;
            else break;
        }
        return best;
    }
};
