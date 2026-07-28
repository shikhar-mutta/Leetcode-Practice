// Link: https://leetcode.com/problems/k-inverse-pairs-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*k)  SC: O(k)
// Approach: dp[i][j] = number of permutations of 1..i with exactly j
// inverse pairs; placing element i can add 0..i-1 inverse pairs, so
// dp[i][j] = sum_{d=0}^{i-1} dp[i-1][j-d]. Maintain a running window
// sum (prefix sums) so each transition is O(1), giving O(n*k) overall.
class Solution {
public:
    int kInversePairs(int n, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            vector<long long> ndp(k + 1, 0);
            long long windowSum = 0;
            for (int j = 0; j <= k; j++) {
                windowSum += dp[j];
                if (j - i >= 0) windowSum -= dp[j - i];
                windowSum = ((windowSum % MOD) + MOD) % MOD;
                ndp[j] = windowSum;
            }
            dp = ndp;
        }
        return (int)dp[k];
    }
};
