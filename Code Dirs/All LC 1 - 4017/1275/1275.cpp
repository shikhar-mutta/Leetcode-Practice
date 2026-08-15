// Link: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3, vector<int>(3, 0));
        for (int i = 0; i < (int)moves.size(); i++) {
            int player = (i % 2 == 0) ? 1 : -1;
            grid[moves[i][0]][moves[i][1]] = player;
        }
        for (int i = 0; i < 3; i++) {
            int rowSum = grid[i][0] + grid[i][1] + grid[i][2];
            int colSum = grid[0][i] + grid[1][i] + grid[2][i];
            if (rowSum == 3 || colSum == 3) return "A";
            if (rowSum == -3 || colSum == -3) return "B";
        }
        int diag1 = grid[0][0] + grid[1][1] + grid[2][2];
        int diag2 = grid[0][2] + grid[1][1] + grid[2][0];
        if (diag1 == 3 || diag2 == 3) return "A";
        if (diag1 == -3 || diag2 == -3) return "B";
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};
