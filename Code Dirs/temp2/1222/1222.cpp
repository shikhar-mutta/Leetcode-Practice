// Link: https://leetcode.com/problems/queens-that-can-attack-the-king/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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