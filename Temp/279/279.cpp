// Link: https://leetcode.com/problems/perfect-squares/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(n))  SC: O(n)
// Approach: DP, dp[i] = min squares summing to i, trying every square <= i
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};
