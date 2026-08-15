// Link: https://leetcode.com/problems/multi-source-flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) SC: O(n*m)
//  Approach: multi-source BFS processed level by level (all cells at the
//  same distance handled together). For an uncolored cell reached by
//  multiple colors in the same step, keep the maximum color seen this
//  round before committing it, matching "simultaneous spread, ties go to
//  the larger color."
using int2 = pair<int, int>; // (color, id)
constexpr int N = 1e5;
int dir[5] = {0, 1, 0, -1, 0};
int2 q[N];
int front = 0, back = 0;
class Solution
{
public:
    static inline int idx(int i, int j, int m) { return i * m + j; }
    static inline bool isOutside(int i, int j, int n, int m)
    {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    static vector<vector<int>> colorGrid(int n, int m,
                                         vector<vector<int>> &sources)
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        front = back = 0;
        for (auto &S : sources)
        {
            const int r = S[0], c = S[1], color = S[2];
            const int id = idx(r, c, m);
            ans[r][c] = color;
            q[back++] = {color, id};
        }
        sort(q, q + back, greater<int2>());
        for (int d = 1; front < back; d++)
        {
            const int qz = back - front;
            for (int k = 0; k < qz; k++)
            {
                auto [color, id] = q[front++];
                const int r = id / m, c = id % m;
                for (int a = 0; a < 4; a++)
                {
                    const int i = r + dir[a], j = c + dir[a + 1];
                    if (isOutside(i, j, n, m) || ans[i][j] > 0)
                        continue;
                    q[back++] = {color, idx(i, j, m)};
                    ans[i][j] = color;
                }
            }
        }
        return ans;
    }
};