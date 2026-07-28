// Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MIN / 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                long long prod = (long long)nums1[i-1] * nums2[j-1];
                long long best = prod;
                best = max(best, prod + max(0LL, dp[i-1][j-1]));
                best = max(best, dp[i-1][j]);
                best = max(best, dp[i][j-1]);
                dp[i][j] = best;
            }
        }
        return (int)dp[n][m];
    }
};
