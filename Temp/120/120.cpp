// Link: https://leetcode.com/problems/triangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: bottom-up DP over a single row, dp[j] = triangle[i][j] + min(dp[j], dp[j+1]) from the row below
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};
