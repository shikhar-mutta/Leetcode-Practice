// Link: https://leetcode.com/problems/stone-game-v/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i+1] = pre[i] + stoneValue[i];
        auto sum = [&](int l, int r) { return pre[r+1] - pre[l]; };
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(int,int)> solve = [&](int l, int r) -> int {
            if (l == r) return 0;
            if (dp[l][r] != -1) return dp[l][r];
            int best = 0;
            for (int m = l; m < r; m++) {
                int leftSum = sum(l, m), rightSum = sum(m+1, r);
                if (leftSum <= rightSum) best = max(best, leftSum + solve(l, m));
                if (rightSum <= leftSum) best = max(best, rightSum + solve(m+1, r));
            }
            return dp[l][r] = best;
        };
        return solve(0, n - 1);
    }
};
