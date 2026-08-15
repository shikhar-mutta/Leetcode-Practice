// Link: https://leetcode.com/problems/queens-that-can-attack-the-king/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1) as we are only checking a fixed number of directions (8) and a fixed number of squares (up to 7) in each direction, regardless of the input size.
    // SC: O(1) as we are using a fixed size array (8x8) to represent the chessboard, which is independent of the input size.
    //   Approach:
    //   1. We will create a boolean array to represent the chessboard and mark the positions of the queens on the board.
    //   2. We will then iterate through each of the 8 possible directions (up, down, left, right, and the 4 diagonals) from the king's position and check for the first queen encountered in each direction.
    //   3. If a queen is found in a direction, we will add its position to the result vector and stop searching in that direction, as any queens behind it are blocked.
    //   4. Finally, we will return the result vector containing the positions of all queens that can attack the king.
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens,
                                            vector<int> &king)
    {
        bool board[8][8] = {};
        for (auto &q : queens)
            board[q[0]][q[1]] = true;

        vector<vector<int>> res;

        for (int dr = -1; dr <= 1; dr++)
        {
            for (int dc = -1; dc <= 1; dc++)
            {
                if (dr == 0 && dc == 0)
                    continue;

                int r = king[0] + dr, c = king[1] + dc;
                while (r >= 0 && r < 8 && c >= 0 && c < 8)
                {
                    if (board[r][c])
                    {
                        res.push_back({r, c});
                        break; // queens behind are blocked
                    }
                    r += dr;
                    c += dc;
                }
            }
        }
        return res;
    }
};