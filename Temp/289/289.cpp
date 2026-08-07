// Link: https://leetcode.com/problems/game-of-life/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(1)
// Approach: encode next state in second bit (cur | next<<1) so neighbor
// counts still read the original state, then shift right at the end
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dirs[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    live += board[ni][nj] & 1;
                }
                int next;
                if (board[i][j] & 1) next = (live == 2 || live == 3) ? 1 : 0;
                else next = (live == 3) ? 1 : 0;
                board[i][j] |= next << 1;
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};
