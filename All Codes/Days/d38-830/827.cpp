// Link: https://leetcode.com/problems/making-a-large-island/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the size of the grid. We traverse the grid twice, once to label the islands and once to check each zero cell.
// SC: O(n^2) for the size array and the queue used in BFS.
// Approach: We first label each island with a unique id and record its size. Then, for each zero cell, we check its four neighbors and sum the sizes of distinct islands to find the maximum possible island size after flipping that zero to one.
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        // Label each island with an id >= 2 and record its size.
        vector<int> size(2, 0); // ids start at 2
        int id = 2;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 1)
                    continue;
                int cnt = 0;
                // BFS flood fill
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = id;
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    cnt++;
                    for (int d = 0; d < 4; d++)
                    {
                        int nr = r + dr[d], nc = c + dc[d];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                        {
                            grid[nr][nc] = id;
                            q.push({nr, nc});
                        }
                    }
                }
                size.push_back(cnt);
                id++;
            }

        // Best without flipping (all land, no zeros case).
        int best = 0;
        for (int s : size)
            best = max(best, s);

        // Try flipping each 0: sum sizes of distinct neighbor islands + 1.
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != 0)
                    continue;
                set<int> seen;
                int total = 1;
                for (int d = 0; d < 4; d++)
                {
                    int nr = i + dr[d], nc = j + dc[d];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] > 1)
                        if (seen.insert(grid[nr][nc]).second)
                            total += size[grid[nr][nc]];
                }
                best = max(best, total);
            }

        return best;
    }
};
