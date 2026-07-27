// Link: https://leetcode.com/problems/minimum-array-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * op1 * op2) SC: O(op1 * op2)
// Approach: 0/1-knapsack-style DP over the array with two independent
// budgets (op1 halves-with-ceil, op2 subtracts k when value >= k). Each
// element picks one of: no-op, op1 only, op2 only, or both — for "both"
// try applying whichever valid order (subtract-then-halve or
// halve-then-subtract) gives the smaller result, since op2's precondition
// only needs to hold at the moment it's applied.
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        const int INF = 1e9;
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1, INF));
        dp[0][0] = 0;

        for (int x : nums) {
            vector<vector<int>> nd(op1 + 1, vector<int>(op2 + 1, INF));
            int halfVal = (x + 1) / 2;
            bool canSubHalf = (x >= k);
            bool canHalfSub = (halfVal >= k);
            for (int a = 0; a <= op1; a++) {
                for (int b = 0; b <= op2; b++) {
                    if (dp[a][b] == INF) continue;
                    int base = dp[a][b];
                    // no-op
                    nd[a][b] = min(nd[a][b], base + x);
                    // op1 only
                    if (a + 1 <= op1) nd[a+1][b] = min(nd[a+1][b], base + halfVal);
                    // op2 only
                    if (b + 1 <= op2 && x >= k) nd[a][b+1] = min(nd[a][b+1], base + (x - k));
                    // both
                    if (a + 1 <= op1 && b + 1 <= op2 && (canSubHalf || canHalfSub)) {
                        int best = INT_MAX;
                        if (canSubHalf) best = min(best, (x - k + 1) / 2);
                        if (canHalfSub) best = min(best, halfVal - k);
                        nd[a+1][b+1] = min(nd[a+1][b+1], base + best);
                    }
                }
            }
            dp = move(nd);
        }

        int ans = INF;
        for (auto& row : dp) for (int v : row) ans = min(ans, v);
        return ans;
    }
};
