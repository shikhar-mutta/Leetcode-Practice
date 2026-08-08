// Link: https://leetcode.com/problems/valid-tic-tac-toe-state/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: count X's and O's (X count must be O count or O count+1). Check win conditions for each player; X can only have won if xCount == oCount+1 (X went last); O can only have won if xCount == oCount. Both can't win simultaneously.
class Solution {
    bool wins(vector<string>& b, char c) {
        for (int i = 0; i < 3; i++) {
            if (b[i][0]==c && b[i][1]==c && b[i][2]==c) return true;
            if (b[0][i]==c && b[1][i]==c && b[2][i]==c) return true;
        }
        if (b[0][0]==c && b[1][1]==c && b[2][2]==c) return true;
        if (b[0][2]==c && b[1][1]==c && b[2][0]==c) return true;
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;
        for (auto& row : board) for (char c : row) { if (c=='X') xCount++; else if (c=='O') oCount++; }
        if (oCount != xCount && oCount != xCount-1) return false;
        bool xWin = wins(board, 'X'), oWin = wins(board, 'O');
        if (xWin && oWin) return false;
        if (xWin && xCount != oCount+1) return false;
        if (oWin && xCount != oCount) return false;
        return true;
    }
};
