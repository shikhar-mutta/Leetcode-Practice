// Link: https://leetcode.com/problems/shortest-path-to-get-all-keys/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*2^k)  SC: O(m*n*2^k)
//  Approach: BFS over states (row, col, keyMask), starting from '@'.
//  Walls block movement; locks require the matching key bit already in
//  the mask; stepping on a key OR's its bit into the mask. The first
//  time the mask has all key bits set gives the shortest path.
class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int startX = -1, startY = -1;
        int totalKeys = 0;

        // Find starting position and total number of keys
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                {
                    startX = i;
                    startY = j;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                {
                    totalKeys++;
                }
            }
        }

        // Target bitmask when all keys are collected (e.g., if totalKeys = 3,
        // target is 111 in binary = 7)
        int targetMask = (1 << totalKeys) - 1;

        // Queue stores: {x, y, key_mask}
        queue<tuple<int, int, int>> q;

        // Visited array: vis[x][y][mask]
        // Max keys is usually 6, so max mask is 2^6 = 64
        bool vis[30][30][64] = {false};

        q.push({startX, startY, 0});
        vis[startX][startY][0] = true;

        int moves = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                auto [x, y, mask] = q.front();
                q.pop();

                // If we collected all keys, return the current step count
                if (mask == targetMask)
                    return moves;

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int nMask = mask;

                    // Check boundaries and walls
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
                        grid[nx][ny] == '#')
                        continue;

                    char cell = grid[nx][ny];

                    // If it's a lock ('A'-'F'), check if we have the
                    // corresponding key
                    if (cell >= 'A' && cell <= 'Z')
                    {
                        int keyIndex = cell - 'A';
                        if (!(nMask & (1 << keyIndex)))
                        {
                            continue; // Don't have the key, can't pass
                        }
                    }

                    // If it's a key ('a'-'f'), update the mask
                    if (cell >= 'a' && cell <= 'z')
                    {
                        int keyIndex = cell - 'a';
                        nMask |= (1 << keyIndex);
                    }

                    // If we haven't visited this cell with this specific key
                    // configuration, push to queue
                    if (!vis[nx][ny][nMask])
                    {
                        vis[nx][ny][nMask] = true;
                        q.push({nx, ny, nMask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};