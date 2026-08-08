// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                int best = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    best = min(best, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = best + (cuts[j] - cuts[i]);
            }
        }
        return dp[0][m-1];
    }
};
