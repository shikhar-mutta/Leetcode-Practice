// Link: https://leetcode.com/problems/number-of-paths-with-max-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const long long MOD = 1e9 + 7;
        int n = board.size();
        vector<vector<long long>> sum(n, vector<long long>(n, -1));
        vector<vector<long long>> ways(n, vector<long long>(n, 0));

        sum[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == n - 1 && j == n - 1) continue; // S already set
                if (board[i][j] == 'X') continue;

                long long best = -1, cnt = 0;
                // candidate from below (up move): (i+1, j)
                if (i + 1 < n && sum[i+1][j] != -1) {
                    if (sum[i+1][j] > best) { best = sum[i+1][j]; cnt = ways[i+1][j]; }
                    else if (sum[i+1][j] == best) { cnt = (cnt + ways[i+1][j]) % MOD; }
                }
                // candidate from right (left move): (i, j+1)
                if (j + 1 < n && sum[i][j+1] != -1) {
                    if (sum[i][j+1] > best) { best = sum[i][j+1]; cnt = ways[i][j+1]; }
                    else if (sum[i][j+1] == best) { cnt = (cnt + ways[i][j+1]) % MOD; }
                }
                // candidate from below-right (up-left move): (i+1, j+1)
                if (i + 1 < n && j + 1 < n && sum[i+1][j+1] != -1) {
                    if (sum[i+1][j+1] > best) { best = sum[i+1][j+1]; cnt = ways[i+1][j+1]; }
                    else if (sum[i+1][j+1] == best) { cnt = (cnt + ways[i+1][j+1]) % MOD; }
                }

                if (best == -1) continue;
                int val = (board[i][j] == 'E') ? 0 : (board[i][j] - '0');
                sum[i][j] = best + val;
                ways[i][j] = cnt;
            }
        }

        if (sum[0][0] == -1) return {0, 0};
        return {(int)sum[0][0], (int)ways[0][0]};
    }
};
