// Link: https://leetcode.com/problems/minimum-knight-moves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        unordered_map<long long,int> dist;
        auto key = [](int x, int y) { return (long long)(x + 400) * 1000 + (y + 400); };
        queue<pair<int,int>> q;
        q.push({0, 0});
        dist[key(0,0)] = 0;
        int dx[] = {1,1,-1,-1,2,2,-2,-2};
        int dy[] = {2,-2,2,-2,1,-1,1,-1};
        while (!q.empty()) {
            auto [cx, cy] = q.front(); q.pop();
            if (cx == x && cy == y) return dist[key(cx,cy)];
            for (int d = 0; d < 8; d++) {
                int nx = cx + dx[d], ny = cy + dy[d];
                if (nx < -2 || ny < -2) continue;
                long long k = key(nx, ny);
                if (dist.count(k)) continue;
                dist[k] = dist[key(cx,cy)] + 1;
                q.push({nx, ny});
            }
        }
        return -1;
    }
};
