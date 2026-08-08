// Link: https://leetcode.com/problems/check-if-move-is-legal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        int dirs[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        char opp = (color == 'W') ? 'B' : 'W';
        for (auto& d : dirs) {
            int r = rMove + d[0], c = cMove + d[1];
            int count = 0;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == opp) {
                r += d[0]; c += d[1];
                count++;
            }
            if (count > 0 && r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] == color) return true;
        }
        return false;
    }
};
