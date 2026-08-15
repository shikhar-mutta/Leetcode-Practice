// Link: https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*log(n*m)), SC: O(n*m) — Dijkstra's algorithm on a grid
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> relaxed(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            q;
        q.push({0, n - 1, m - 1});

        relaxed[n - 1][m - 1] = 0;
        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!q.empty())
        {
            while (relaxed[get<1>(q.top())][get<2>(q.top())] > get<0>(q.top()))
                q.pop();
            auto [eff, r, c] = q.top();
            if (r == 0 && c == 0)
                return eff;
            q.pop();
            for (auto &[i, j] : dir)
            {
                int dr = i + r, dc = j + c;
                if (dr >= 0 && dr < n && dc >= 0 && dc < m)
                {
                    int neweff = max(eff, abs(heights[r][c] - heights[dr][dc]));
                    if (neweff < relaxed[dr][dc])
                    {
                        relaxed[dr][dc] = neweff;
                        q.push({neweff, dr, dc});
                    }
                }
            }
        }
        return 0;
    }
};
