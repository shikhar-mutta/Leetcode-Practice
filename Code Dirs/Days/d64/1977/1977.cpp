// Link: https://leetcode.com/problems/number-of-ways-to-separate-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: dp[i][len] = ways to partition num[0:i] where the last part is
// num[i-len:i]. Transition sums dp[j][len'] for len'<len (any shorter prior
// part is automatically <= current) plus dp[j][len] itself if the equal-
// length prior part is lexicographically <= current (checked via a
// precomputed LCP table for O(1) comparison). Prefix sums per row make each
// transition O(1) after O(n^2) total states.
class Solution {
public:
    int numberOfCombinations(string num) {
        const long long MOD = 1e9 + 7;
        int n = num.size();
        if (num[0] == '0') return 0;

        vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (num[i] == num[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> prefixSum(n + 1, vector<long long>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int len = 1; len <= i; len++) {
                int startIdx = i - len;
                if (num[startIdx] == '0') { dp[i][len] = 0; continue; }
                if (startIdx == 0) { dp[i][len] = 1; continue; }
                int j = startIdx;
                long long total = prefixSum[j][min(len - 1, j)];
                if (len <= j) {
                    int l1 = j - len, l2 = j;
                    int lcpVal = lcp[l1][l2];
                    bool le = (lcpVal >= len) || (num[l1 + lcpVal] <= num[l2 + lcpVal]);
                    if (le) total += dp[j][len];
                }
                dp[i][len] = total % MOD;
            }
            for (int len = 1; len <= i; len++)
                prefixSum[i][len] = (prefixSum[i][len-1] + dp[i][len]) % MOD;
        }
        return (int)prefixSum[n][n];
    }
};
