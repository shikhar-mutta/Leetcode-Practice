// Link: https://leetcode.com/problems/available-captures-for-rook/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int rr = -1, rc = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == 'R') { rr = i; rc = j; }

        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        int captures = 0;
        for (int d = 0; d < 4; d++) {
            int r = rr, c = rc;
            while (true) {
                r += dr[d]; c += dc[d];
                if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] == 'B') break;
                if (board[r][c] == 'p') { captures++; break; }
            }
        }
        return captures;
    }
};
