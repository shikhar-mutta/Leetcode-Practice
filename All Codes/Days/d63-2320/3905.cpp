// Link: https://leetcode.com/problems/multi-source-flood-fill/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) SC: O(n*m)
// Approach: multi-source BFS processed level by level (all cells at the
// same distance handled together). For an uncolored cell reached by
// multiple colors in the same step, keep the maximum color seen this
// round before committing it, matching "simultaneous spread, ties go to
// the larger color."
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for (auto& s : sources) {
            grid[s[0]][s[1]] = s[2];
            q.push({s[0], s[1]});
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int sz = q.size();
            unordered_map<long long, int> incoming; // cell -> best color this round
            for (int t = 0; t < sz; t++) {
                auto [r, c] = q.front(); q.pop();
                int color = grid[r][c];
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
                    if (grid[nr][nc] != 0) continue;
                    long long key = (long long)nr * m + nc;
                    auto it = incoming.find(key);
                    if (it == incoming.end() || color > it->second) incoming[key] = color;
                }
            }
            for (auto& [key, color] : incoming) {
                int r = key / m, c = key % m;
                grid[r][c] = color;
                q.push({r, c});
            }
        }
        return grid;
    }
};
