// Link: https://leetcode.com/problems/integer-break/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: dp[i] = max product from splitting i into >=2 parts, trying
// every first split point j and either keeping i-j whole or using dp[i-j]
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }
        return dp[n];
    }
};
