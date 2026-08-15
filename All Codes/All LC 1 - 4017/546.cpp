// Link: https://leetcode.com/problems/remove-boxes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^4)  SC: O(n^3)
// Approach: dp[l][r][k] = max points removing boxes[l..r] with k extra
// boxes of value boxes[l] attached to the left; either remove boxes[l]
// immediately with its k attached, or merge with a later matching box
class Solution {
    vector<vector<vector<int>>> memo;

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (memo[l][r][k] != -1) return memo[l][r][k];

        int origL = l, origK = k;
        while (l + 1 <= r && boxes[l + 1] == boxes[l]) { l++; k++; }

        int best = (k + 1) * (k + 1) + solve(boxes, l + 1, r, 0);
        for (int m = l + 1; m <= r; m++) {
            if (boxes[m] == boxes[l]) {
                best = max(best, solve(boxes, l + 1, m - 1, 0) + solve(boxes, m, r, k + 1));
            }
        }
        return memo[origL][r][origK] = best;
    }

public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memo.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(boxes, 0, n - 1, 0);
    }
};
