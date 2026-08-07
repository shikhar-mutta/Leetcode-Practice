// Link: https://leetcode.com/problems/counting-bits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: dp[i] = dp[i >> 1] + (i & 1), reusing bit count of half of i
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) dp[i] = dp[i >> 1] + (i & 1);
        return dp;
    }
};
