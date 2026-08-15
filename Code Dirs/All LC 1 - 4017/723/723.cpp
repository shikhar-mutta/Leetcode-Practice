// Link: https://leetcode.com/problems/candy-crush/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((m*n)^2) worst case SC: O(1) extra
// Approach: repeatedly scan for 3+ runs horizontally and vertically, marking crushed cells (negate value to preserve identity while marking); if any found, zero them out, then apply gravity (compact each column downward); repeat until no crushes occur.
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        while (true) {
            vector<vector<bool>> toCrush(m, vector<bool>(n, false));
            bool found = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j+2 < n; j++) {
                    int v = abs(board[i][j]);
                    if (v != 0 && abs(board[i][j+1]) == v && abs(board[i][j+2]) == v) {
                        toCrush[i][j] = toCrush[i][j+1] = toCrush[i][j+2] = true;
                        found = true;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                for (int i = 0; i+2 < m; i++) {
                    int v = abs(board[i][j]);
                    if (v != 0 && abs(board[i+1][j]) == v && abs(board[i+2][j]) == v) {
                        toCrush[i][j] = toCrush[i+1][j] = toCrush[i+2][j] = true;
                        found = true;
                    }
                }
            }
            if (!found) break;
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (toCrush[i][j]) board[i][j] = 0;
            for (int j = 0; j < n; j++) {
                int write = m-1;
                for (int i = m-1; i >= 0; i--) {
                    if (board[i][j] != 0) board[write--][j] = board[i][j];
                }
                while (write >= 0) board[write--][j] = 0;
            }
        }
        return board;
    }
};
