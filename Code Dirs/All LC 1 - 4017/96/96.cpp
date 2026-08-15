// Link: https://leetcode.com/problems/unique-binary-search-trees/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: Catalan number DP — dp[i] = sum over roots j of dp[j-1] * dp[i-j]
class Solution {
public:
    int numTrees(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return (int)dp[n];
    }
};
