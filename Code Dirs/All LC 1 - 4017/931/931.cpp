// Link: https://leetcode.com/problems/minimum-falling-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for (int i = 1; i < n; i++) {
            vector<int> next(n);
            for (int j = 0; j < n; j++) {
                int best = dp[j];
                if (j > 0) best = min(best, dp[j-1]);
                if (j < n - 1) best = min(best, dp[j+1]);
                next[j] = matrix[i][j] + best;
            }
            dp = next;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
