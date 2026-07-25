// Link: https://leetcode.com/problems/check-if-move-is-legal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    //  Approach:
    //  1. We can check all 8 directions from the given cell (rMove, cMove) to see if there is a line of opposite color cells that ends with a cell of the same color.
    //  2. We can use two arrays dr and dc to represent the row and column offsets for the 8 directions.
    //  3. For each direction, we can keep moving in that direction until we either go out of bounds, hit an empty cell, or hit a cell of the same color.
    //  4. If we hit a cell of   the same color and we have seen at least one opposite color cell in that direction, then the move is legal and we can return true.
    //  5. If we have checked all 8 directions and none of them are legal, then the move is illegal and we can return false.
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove,
                   char color)
    {
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int d = 0; d < 8; ++d)
        {
            int r = rMove + dr[d], c = cMove + dc[d], len = 0;
            while (r >= 0 && r < 8 && c >= 0 && c < 8 && board[r][c] != '.')
            {
                if (board[r][c] == color)
                {
                    if (len >= 1)
                        return true; // endpoint reached with middle cells
                    break;           // same color immediately: no good line
                }
                ++len; // opposite color cell
                r += dr[d];
                c += dc[d];
            }
        }
        return false;
    }
};