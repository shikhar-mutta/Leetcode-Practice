// Link: https://leetcode.com/problems/swim-in-rising-water/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) where n is the size of the grid. We use a priority queue to process each cell, and each cell is processed at most once.
// SC: O(n^2) for the best array and the priority queue.
// Approach: We use Dijkstra's algorithm to find the minimum time required to reach the bottom-right cell from the top-left cell. The time taken to enter a cell is determined by the maximum elevation encountered along the path. We maintain a priority queue to explore cells in order of their elevation, ensuring that we always process the cell with the lowest elevation next.
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        // Dijkstra: minimize the maximum elevation encountered on the path.
        vector<vector<int>> best(n, vector<int>(n, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq; // {time, r, c}
        best[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            auto [t, r, c] = pq.top();
            pq.pop();
            if (r == n - 1 && c == n - 1)
                return t;
            if (t > best[r][c])
                continue;
            for (int d = 0; d < 4; d++)
            {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;
                int nt = max(t, grid[nr][nc]);
                if (nt < best[nr][nc])
                {
                    best[nr][nc] = nt;
                    pq.push({nt, nr, nc});
                }
            }
        }
        return best[n - 1][n - 1];
    }
};
