// Link: https://leetcode.com/problems/maximum-number-of-moves-to-kill-all-pawns/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(8^n) where n is the number of positions
//SC: O(n^2) where n is the number of positions
//Approach: We can use a depth-first search (DFS) approach to solve this problem. We can start from the knight's position and try to move to all possible positions in the grid. We can keep track of the positions that have been visited and the number of moves taken to reach each position. We can then return the maximum number of moves taken to reach all positions in the grid. We can also use memoization to optimize the DFS approach by storing the results of previously computed states.
const int mv[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
const int N = 50;
int D[16][16]; // Store distances between positions (at most 16 positions)
int sz;
int dp[2][16][(1 << 16)];

using int2 = pair<int, int>;
class Solution
{
public:
    inline bool isInside(int r0, int c0)
    {
        return 0 <= r0 && r0 < N && 0 <= c0 && c0 < N;
    }
    inline int num(int i, int j) { return i * N + j; }
    unordered_map<int, int> SetP;
    inline void build_SetP(vector<vector<int>> &positions)
    {
        int i = 0;
        for (auto &p : positions)
        {
            SetP[num(p[0], p[1])] = i++;
        }
    }
    // Perform BFS from a single starting position to all other positions
    void BFS_minMoves(int idx, vector<vector<int>> &positions)
    {
        int r0 = positions[idx][0], c0 = positions[idx][1];
        int dist[N][N]; // Distance from (r0, c0) to all other positions
        memset(dist, -1, sizeof(dist));
        queue<int> q;
        q.push(num(r0, c0));
        dist[r0][c0] = 0;
        int cnt = 0;
        while (!q.empty() && cnt < sz)
        {
            int x = q.front();
            auto [r, c] = div(x, N);
            q.pop();
            int currentD = dist[r][c];
            if (SetP.count(x))
            {
                D[idx][SetP[x]] = currentD;
                cnt++;
            }
            for (int a = 0; a < 8; a++)
            {
                int nr = r + mv[a][0], nc = c + mv[a][1];
                if (isInside(nr, nc) && dist[nr][nc] == -1)
                {
                    dist[nr][nc] = currentD + 1;
                    q.emplace(num(nr, nc));
                }
            }
        }
    }

    int dfs(bool isBob, int idx, int bMask, vector<vector<int>> &positions)
    {
        if (bMask == (1 << sz) - 1)
            return 0; // All positions visited
        if (dp[isBob][idx][bMask] != -1)
            return dp[isBob][idx][bMask];

        int moves = (isBob) ? INT_MAX : 0;
        for (int i = 0; i < sz; i++)
        {
            if (bMask & (1 << i))
                continue;         // If position i is already visited, skip
            int dist = D[idx][i]; // Distance between positions idx and i
            if (isBob)
                moves =
                    min(moves, dist + dfs(0, i, bMask | (1 << i),
                                          positions)); // Bob minimizes moves
            else
                moves =
                    max(moves, dist + dfs(1, i, bMask | (1 << i),
                                          positions)); // Alice maximizes moves
        }
        return dp[isBob][idx][bMask] = moves;
    }

    int maxMoves(int kx, int ky, vector<vector<int>> &positions)
    {
        positions.push_back({kx, ky}); // add starting to positions
        sz = positions.size();

        build_SetP(positions); // Build SetPfrom positions
        // Compute the shortest distances between all pairs of positions
        for (int i = 0; i < sz; i++)
            BFS_minMoves(i, positions);

        memset(dp, -1, sizeof(dp)); // Initialize memoization array
        return dfs(0, sz - 1, 1 << (sz - 1),
                   positions); // Start DFS from the knight's position
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();