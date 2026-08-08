// Link: https://leetcode.com/problems/palindrome-removal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i + 1 < n; i++) dp[i][i+1] = (arr[i] == arr[i+1]) ? 1 : 2;

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i+1][j] + 1;
                for (int k = i + 1; k <= j; k++) {
                    if (arr[k] == arr[i]) {
                        int left = (k == i + 1) ? 0 : dp[i+1][k-1];
                        int right = (k == j) ? 0 : dp[k+1][j];
                        dp[i][j] = min(dp[i][j], left + right);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
