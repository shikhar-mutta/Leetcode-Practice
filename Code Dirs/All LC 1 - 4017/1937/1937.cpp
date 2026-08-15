// Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        vector<long long> dp(cols);
        for (int c = 0; c < cols; c++) dp[c] = points[0][c];

        for (int r = 1; r < rows; r++) {
            vector<long long> left(cols), right(cols), ndp(cols);
            left[0] = dp[0];
            for (int c = 1; c < cols; c++) left[c] = max(left[c-1] - 1, dp[c]);
            right[cols-1] = dp[cols-1];
            for (int c = cols - 2; c >= 0; c--) right[c] = max(right[c+1] - 1, dp[c]);
            for (int c = 0; c < cols; c++) {
                ndp[c] = points[r][c] + max(left[c], right[c]);
            }
            dp = ndp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
