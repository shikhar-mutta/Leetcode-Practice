// Link: https://leetcode.com/problems/number-of-paths-with-max-score/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: DP from bottom-right to top-left, tracking (bestScore,
// waysToAchieveIt) per cell. A cell's best comes from the best of its
// three reachable neighbors (down, right, diag); if multiple neighbors
// tie for best, sum their way-counts. 'S' and 'E' contribute 0 to the
// sum; 'X' cells are unreachable.
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const long long MOD = 1e9 + 7;
        int n = board.size();
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        vector<vector<long long>> ways(n, vector<long long>(n, 0));

        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n - 1 && j == n - 1) continue;
                if (board[i][j] == 'X') continue;
                long long best = -1, cnt = 0;
                int di[3] = {1, 0, 1}, dj[3] = {0, 1, 1};
                for (int d = 0; d < 3; d++) {
                    int ni = i + di[d], nj = j + dj[d];
                    if (ni >= n || nj >= n || dp[ni][nj] == -1) continue;
                    if (dp[ni][nj] > best) { best = dp[ni][nj]; cnt = ways[ni][nj]; }
                    else if (dp[ni][nj] == best) { cnt = (cnt + ways[ni][nj]) % MOD; }
                }
                if (best == -1) continue;
                dp[i][j] = best + (board[i][j] - '0');
                ways[i][j] = cnt;
            }
        }

        if (dp[0][0] == -1) return {0, 0};
        return {(int)dp[0][0], (int)ways[0][0]};
    }
};
