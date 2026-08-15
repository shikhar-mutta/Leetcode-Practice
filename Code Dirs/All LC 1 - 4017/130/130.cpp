// Link: https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: mark all 'O's connected to the border (unflippable) via DFS/flood-fill, then flip every
// remaining unmarked 'O' to 'X' and restore the marked ones back to 'O'
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
            board[r][c] = '#';
            dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1);
        };
        for (int r = 0; r < m; r++) { dfs(r, 0); dfs(r, n-1); }
        for (int c = 0; c < n; c++) { dfs(0, c); dfs(m-1, c); }
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
};
