// Link: https://leetcode.com/problems/toss-strange-coins/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1, 0.0);
        dp[0] = 1.0;
        for (int i = 0; i < n; i++) {
            for (int j = min(i + 1, target); j >= 0; j--) {
                double withHead = (j > 0) ? dp[j-1] * prob[i] : 0.0;
                double withTail = dp[j] * (1 - prob[i]);
                dp[j] = withHead + withTail;
            }
        }
        return dp[target];
    }
};
