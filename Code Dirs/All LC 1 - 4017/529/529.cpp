// Link: https://leetcode.com/problems/minesweeper/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: if clicking a mine, reveal it and stop; otherwise DFS flood-fill
// revealing empty cells, stopping expansion at any cell with adjacent mines
class Solution {
    int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    void reveal(vector<vector<char>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        if (board[r][c] != 'E') return;

        int mineCount = 0;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (board[nr][nc] == 'M') mineCount++;
        }

        if (mineCount > 0) {
            board[r][c] = '0' + mineCount;
            return;
        }

        board[r][c] = 'B';
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            reveal(board, nr, nc);
        }
    }

public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        reveal(board, r, c);
        return board;
    }
};
