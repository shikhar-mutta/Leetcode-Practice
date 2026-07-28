// Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(R*C*(R+C))  SC: O(R*C)
// Approach: dp[i][j] = set of achievable balances (open-close count) at
// cell (i,j) via any right/down path, represented as a bitset/boolean
// array (balance capped by R+C). Transition from up/left neighbors,
// adjusting by +1 for '(' or -1 for ')' (discard negative balances).
// Answer: is balance 0 reachable at bottom-right.
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int R = grid.size(), C = grid[0].size();
        if ((R + C - 1) % 2 != 0) return false;
        int maxBal = R + C;
        vector<vector<vector<bool>>> dp(R, vector<vector<bool>>(C, vector<bool>(maxBal + 1, false)));
        auto delta = [&](int i, int j) { return grid[i][j] == '(' ? 1 : -1; };
        if (grid[0][0] == '(') dp[0][0][1] = true;
        else return false; // first char must be '(' for any valid path
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) continue;
                int d = delta(i, j);
                for (int b = 0; b <= maxBal; b++) {
                    bool from = false;
                    if (i > 0 && b - d >= 0 && b - d <= maxBal) from = from || dp[i-1][j][b-d];
                    if (j > 0 && b - d >= 0 && b - d <= maxBal) from = from || dp[i][j-1][b-d];
                    if (from) dp[i][j][b] = true;
                }
            }
        }
        return dp[R-1][C-1][0];
    }
};
