// Link: https://leetcode.com/problems/snakes-and-ladders/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getCell = [&](int label) {
            int row = (label - 1) / n;
            int col = (label - 1) % n;
            if (row % 2 == 1) col = n - 1 - col;
            row = n - 1 - row;
            return make_pair(row, col);
        };

        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == n * n) return dist[cur];
            for (int next = cur + 1; next <= min(cur + 6, n * n); next++) {
                auto [r, c] = getCell(next);
                int dest = board[r][c] == -1 ? next : board[r][c];
                if (dist[dest] == -1) {
                    dist[dest] = dist[cur] + 1;
                    q.push(dest);
                }
            }
        }
        return -1;
    }
};
