// Link: https://leetcode.com/problems/battleships-in-a-board/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(1)
// Approach: count only the top-left cell of each battleship (cell with no
// 'X' neighbor above or to the left)
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'X') continue;
                if (i > 0 && board[i-1][j] == 'X') continue;
                if (j > 0 && board[i][j-1] == 'X') continue;
                count++;
            }
        }
        return count;
    }
};
