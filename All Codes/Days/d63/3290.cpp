// Link: https://leetcode.com/problems/maximum-multiplication-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: dp[j] = best score using exactly j of the 4 fixed coefficients
// a[0..3] matched with some increasing subsequence of b's elements so far.
// Scanning b left to right, for each element try extending it as the
// (j+1)-th match (dp[j] + b[i]*a[j]); update j from high to low to avoid
// reusing the same b[i] twice within one iteration.
class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long dp[4];
        for (int i = 0; i < 4; ++i)
            dp[i] = LLONG_MIN / 4;
        for (int i = 0, n = b.size(); i < n; ++i) {
            long long num = b[i];
            for (int j = 3; j > 0; --j) {
                long long val = num * a[j];
                dp[j] = max(dp[j], dp[j - 1] + val);
            }
            dp[0] = max(dp[0], num * a[0]);
        }
        return dp[3];
    }
};
