// Link: https://leetcode.com/problems/minimum-path-cost-in-a-hidden-grid/description/

#include <bits/stdc++.h>
using namespace std;

class GridMaster {
public:
    virtual bool canMove(char direction) = 0;
    virtual int move(char direction) = 0;
    virtual bool isTarget() = 0;
    virtual ~GridMaster() {}
};

class Solution {
public:
    unordered_map<int, unordered_map<int, bool>> visited;
    unordered_map<long long, int> edgeCost; // key: (r,c,dir) -> cost
    int targetR = INT_MIN, targetC = INT_MIN;
    bool foundTarget = false;

    char dirs[4] = {'U', 'D', 'L', 'R'};
    char opposite(char d) {
        if (d == 'U') return 'D';
        if (d == 'D') return 'U';
        if (d == 'L') return 'R';
        return 'L';
    }
    pair<int,int> delta(char d) {
        if (d == 'U') return {-1, 0};
        if (d == 'D') return {1, 0};
        if (d == 'L') return {0, -1};
        return {0, 1};
    }

    long long key(int r, int c, char d) {
        return ((long long)(r + 1000) * 2000 + (c + 1000)) * 4 + (d == 'U' ? 0 : d == 'D' ? 1 : d == 'L' ? 2 : 3);
    }

    void explore(GridMaster& master, int r, int c) {
        visited[r][c] = true;
        if (master.isTarget()) {
            targetR = r; targetC = c;
            foundTarget = true;
        }
        for (char d : dirs) {
            auto [dr, dc] = delta(d);
            int nr = r + dr, nc = c + dc;
            if (master.canMove(d)) {
                int cost = master.move(d);
                edgeCost[key(r, c, d)] = cost;
                bool alreadyVisited = visited.count(nr) && visited[nr].count(nc);
                if (!alreadyVisited) explore(master, nr, nc);
                master.move(opposite(d));
            }
        }
    }

    int findShortestPath(GridMaster& master) {
        explore(master, 0, 0);
        if (!foundTarget) return -1;

        map<pair<int,int>, long long> dist;
        dist[{0, 0}] = 0;
        priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto [d, r, c] = pq.top(); pq.pop();
            if (dist.count({r, c}) && d > dist[{r, c}]) continue;
            for (char dir : dirs) {
                long long k = key(r, c, dir);
                if (!edgeCost.count(k)) continue;
                auto [dr, dc] = delta(dir);
                int nr = r + dr, nc = c + dc;
                long long nd = d + edgeCost[k];
                if (!dist.count({nr, nc}) || nd < dist[{nr, nc}]) {
                    dist[{nr, nc}] = nd;
                    pq.push({nd, nr, nc});
                }
            }
        }
        if (!dist.count({targetR, targetC})) return -1;
        return (int)dist[{targetR, targetC}];
    }
};
