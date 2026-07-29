// Link: https://leetcode.com/problems/grid-teleportation-traversal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<char, vector<pair<int,int>>> letterCells;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (isupper(matrix[i][j])) letterCells[matrix[i][j]].push_back({i, j});

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        deque<pair<int,int>> dq;
        dq.push_back({0, 0});
        set<char> usedLetters;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while (!dq.empty()) {
            auto [r, c] = dq.front(); dq.pop_front();
            int d = dist[r][c];

            if (isupper(matrix[r][c]) && !usedLetters.count(matrix[r][c])) {
                usedLetters.insert(matrix[r][c]);
                for (auto& [nr, nc] : letterCells[matrix[r][c]]) {
                    if (d < dist[nr][nc]) {
                        dist[nr][nc] = d;
                        dq.push_front({nr, nc});
                    }
                }
            }

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (matrix[nr][nc] == '#') continue;
                if (d + 1 < dist[nr][nc]) {
                    dist[nr][nc] = d + 1;
                    dq.push_back({nr, nc});
                }
            }
        }

        return dist[m-1][n-1] == INT_MAX ? -1 : dist[m-1][n-1];
    }
};
