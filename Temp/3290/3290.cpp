// Link: https://leetcode.com/problems/maximum-multiplication-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        const long long NEG = LLONG_MIN / 2;
        vector<long long> dp(5, NEG);
        dp[0] = 0;
        for (int x : b) {
            for (int k = 4; k >= 1; k--) {
                if (dp[k-1] > NEG / 2) {
                    dp[k] = max(dp[k], dp[k-1] + (long long)a[k-1] * x);
                }
            }
        }
        return dp[4];
    }
};
