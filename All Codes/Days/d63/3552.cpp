// Link: https://leetcode.com/problems/grid-teleportation-traversal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(m*n)
// Approach: 0-1 BFS. Normal moves cost 1 (pushed to the back of a deque),
// teleporting to every same-letter portal costs 0 (pushed to the front).
// Each portal letter's position list is cleared after first use so it's
// never explored again (matching "each letter usable at most once").
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        unordered_map<char, vector<pair<int,int>>> portals;
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (isupper(matrix[r][c])) portals[matrix[r][c]].push_back({r, c});

        deque<pair<int,int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});
        int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};

        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            char ch = matrix[r][c];

            if (isupper(ch) && portals.count(ch)) {
                for (auto& [pr, pc] : portals[ch]) {
                    if (dist[pr][pc] == -1 || dist[pr][pc] > dist[r][c]) {
                        dist[pr][pc] = dist[r][c];
                        dq.push_front({pr, pc});
                    }
                }
                portals.erase(ch);
            }

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (matrix[nr][nc] == '#') continue;
                int nd = dist[r][c] + 1;
                if (dist[nr][nc] == -1 || nd < dist[nr][nc]) {
                    dist[nr][nc] = nd;
                    dq.push_back({nr, nc});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
