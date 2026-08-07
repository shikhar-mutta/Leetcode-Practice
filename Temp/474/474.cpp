// Link: https://leetcode.com/problems/ones-and-zeroes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(strs.size() * m * n)  SC: O(m*n)
// Approach: 2D 0/1 knapsack, dp[i][j] = max count of strings using at most
// i zeros and j ones
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto& s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) c == '0' ? zeros++ : ones++;
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
