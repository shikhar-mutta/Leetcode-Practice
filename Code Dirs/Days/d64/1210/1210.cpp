// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: BFS over states (r, c, orientation) where (r,c) is the
// snake's head cell and orientation is horizontal or vertical. From
// each state, try sliding right, sliding down, and rotating (clockwise
// from horizontal, counterclockwise from vertical), each requiring the
// relevant clearance cells to be empty. Goal: horizontal at the bottom
// right two cells.
class Solution
{
public:
    typedef tuple<int, int, int, int> tpl;

    int minimumMoves(vector<vector<int>> &v)
    {

        int n = v.size();

        queue<tpl> q;
        q.push({0, 1, 0, 0});

        vector<vector<pair<int, int>>> vis(n, vector<pair<int, int>>(n));
        vis[0][0] = {1, 1};
        vis[0][1] = {1, 1};

        while (!q.empty())
        {
            auto [i, j, vrti, c] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1 && !vrti)
                return c;

            // right
            if (j + 1 < n)
            {
                if (!vrti && !v[i][j + 1] && !vis[i][j + 1].first)
                {
                    q.push({i, j + 1, vrti, c + 1});
                    vis[i][j + 1].first = 1;
                }
                else if (vrti && i - 1 >= 0 && !v[i - 1][j + 1] &&
                         !v[i][j + 1] && !vis[i][j + 1].second)
                {
                    q.push({i, j + 1, vrti, c + 1});
                    vis[i][j + 1].second = 1;
                }
            }

            // down,
            if (i + 1 < n)
            {
                if (vrti && !v[i + 1][j] && !vis[i + 1][j].second)
                {
                    q.push({i + 1, j, vrti, c + 1});
                    vis[i + 1][j].second = 1;
                }
                else if (!vrti && i + 1 < n && !v[i + 1][j] &&
                         !v[i + 1][j - 1] && !vis[i + 1][j].first)
                {
                    vis[i + 1][j].first = 1;
                    q.push({i + 1, j, vrti, c + 1});
                }
            }

            // rotate v to h
            if (i - 1 >= 0 && j + 1 < n && vrti && !v[i - 1][j + 1] &&
                !v[i][j + 1] && !vis[i - 1][j + 1].first)
            {
                vis[i - 1][j + 1].first = 1;
                q.push({i - 1, j + 1, !vrti, c + 1});
            }

            // rotate h to v
            if (i + 1 < n && j - 1 >= 0 && !vrti && !v[i + 1][j - 1] &&
                !v[i + 1][j] && !vis[i + 1][j - 1].second)
            {
                vis[i + 1][j - 1].second = 1;
                q.push({i + 1, j - 1, !vrti, c + 1});
            }
        }

        return -1;
    }
};