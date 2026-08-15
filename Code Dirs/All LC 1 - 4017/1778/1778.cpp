// Link: https://leetcode.com/problems/shortest-path-in-a-hidden-grid/description/

#include <bits/stdc++.h>
using namespace std;

class GridMaster {
public:
    virtual bool canMove(char direction) = 0;
    virtual bool move(char direction) = 0;
    virtual bool isTarget() = 0;
    virtual ~GridMaster() {}
};

class Solution {
public:
    unordered_map<int, unordered_map<int, int>> grid; // grid[r][c] = 0 unknown,1 open,2 blocked
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

    void explore(GridMaster& master, int r, int c) {
        grid[r][c] = 1;
        if (master.isTarget()) {
            targetR = r; targetC = c;
            foundTarget = true;
        }
        for (char d : dirs) {
            auto [dr, dc] = delta(d);
            int nr = r + dr, nc = c + dc;
            if (grid.count(nr) && grid[nr].count(nc)) continue;
            if (master.canMove(d)) {
                master.move(d);
                explore(master, nr, nc);
                master.move(opposite(d));
            } else {
                grid[nr][nc] = 2;
            }
        }
    }

    string findShortestPath(GridMaster& master) {
        explore(master, 0, 0);
        if (!foundTarget) return "";

        queue<tuple<int,int,string>> q;
        q.push({0, 0, ""});
        unordered_set<long long> visited;
        visited.insert(0);
        while (!q.empty()) {
            auto [r, c, path] = q.front(); q.pop();
            if (r == targetR && c == targetC) return path;
            for (char d : dirs) {
                auto [dr, dc] = delta(d);
                int nr = r + dr, nc = c + dc;
                if (grid.count(nr) && grid[nr].count(nc) && grid[nr][nc] == 1) {
                    long long key = ((long long)(nr + 1000) << 20) | (nc + 1000);
                    if (visited.count(key)) continue;
                    visited.insert(key);
                    q.push({nr, nc, path + d});
                }
            }
        }
        return "";
    }
};
