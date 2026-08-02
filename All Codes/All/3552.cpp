// Link: https://leetcode.com/problems/grid-teleportation-traversal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
//  Approach: 0-1 BFS. Normal moves cost 1 (pushed to the back of a deque),
//  teleporting to every same-letter portal costs 0 (pushed to the front).
//  Each portal letter's position list is cleared after first use so it's
//  never explored again (matching "each letter usable at most once").
class Solution
{
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minMoves(vector<string> &matrix)
    {
        if (matrix.back().back() == '#')
            return -1;
        vector<vector<pair<int, int>>> trans(26);

        int m = matrix.size(), n = matrix[0].size();
        if (m == 1 && n == 1)
            return 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 'A' || matrix[i][j] > 'Z')
                {
                    continue;
                }

                trans[matrix[i][j] - 'A'].push_back({i, j});
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        if (matrix[0][0] >= 'A' && matrix[0][0] <= 'Z')
        {
            for (auto &tran : trans[matrix[0][0] - 'A'])
            {
                if (tran.first == (m - 1) && tran.second == (n - 1))
                    return 0;
                matrix[tran.first][tran.second] = '#';
                q.push({tran.first, tran.second});
            }
        }
        int res = 1;
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                auto cur = q.front();
                q.pop();

                for (auto &d : dirs)
                {
                    int nx = cur.first + d.first, ny = cur.second + d.second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (matrix[nx][ny] == '#')
                        continue;
                    if (nx == (m - 1) && ny == (n - 1))
                        return res;
                    int cur_alp = matrix[nx][ny] - 'A';
                    matrix[nx][ny] = '#';
                    q.push({nx, ny});
                    if (cur_alp < 0 || cur_alp > 26)
                        continue;
                    for (auto &tran : trans[cur_alp])
                    {
                        if (tran.first == (m - 1) && tran.second == (n - 1))
                            return res;
                        matrix[tran.first][tran.second] = '#';
                        q.push({tran.first, tran.second});
                    }
                    trans[cur_alp].resize(0);
                }
            }

            res++;
        }
        return -1;
    }
};