// Link: https://leetcode.com/problems/number-of-valid-move-combinations-on-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(8^n)  SC: O(n)
//   Approach: Use DFS to explore all possible move combinations for the given pieces on the chessboard. For each piece, generate all valid moves based on its type (rook, bishop, queen) and the current state of the board. Keep track of the occupied squares to avoid collisions and ensure that no two pieces occupy the same square. Count all valid combinations of moves for all pieces.
class Solution
{
public:
    int countCombinations(vector<string> &pieces, vector<vector<int>> &positions)
    {
        const int n{static_cast<int>(pieces.size())};
        static int lkp[8][8]{};
        memset(lkp, 0, sizeof(lkp));
        auto dfs{[&](this auto &&dfs, int idx) -> int
                 {
                     if (idx >= n)
                         return 1;
                     static const pair<int, int> dir[8]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
                     const string &p{pieces[idx]};
                     int i{positions[idx][0] - 1}, j{positions[idx][1] - 1};
                     int ret{0};
                     if (!lkp[i][j])
                     {
                         lkp[i][j] = -1;
                         ret += dfs(idx + 1);
                         lkp[i][j] = 0;
                     }
                     for (const auto [di, dj] : p.front() == 'r' ? span<const pair<int, int>>{dir, dir + 4} : (p.front() == 'b' ? span<const pair<int, int>>{dir + 4, dir + 8} : span<const pair<int, int>>{dir, dir + 8}))
                     {
                         int ni{i + di}, nj{j + dj};
                         int t{1};
                         for (; ni >= 0 && nj >= 0 && ni < 8 && nj < 8; ni += di, nj += dj, t <<= 1)
                         {
                             if (lkp[ni][nj] & t)
                                 break;
                             int inv{t - 1};
                             if ((lkp[ni][nj] & ~inv) == 0)
                             {
                                 lkp[ni][nj] |= ~inv;
                                 ret += dfs(idx + 1);
                                 lkp[ni][nj] &= inv;
                             }
                             lkp[ni][nj] |= t;
                         }
                         for (ni -= di, nj -= dj, t >>= 1; ni != i || nj != j; ni -= di, nj -= dj, t >>= 1)
                             lkp[ni][nj] ^= t;
                     }
                     return ret;
                 }};
        return dfs(0);
    }
};