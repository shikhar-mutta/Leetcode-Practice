// Link: https://leetcode.com/problems/construct-2d-grid-matching-graph-layout/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> adjHead; // not used; using vector<vector<int>> instead
    vector<vector<int>> g;

    int neighborExcluding2(int a, int e1, int e2) {
        for (int x : g[a]) if (x != e1 && x != e2) return x;
        return -1;
    }
    int commonNeighborExcluding(int a, int b, int exclude) {
        for (int x : g[a]) {
            if (x == exclude) continue;
            for (int y : g[b]) if (y == x) return x;
        }
        return -1;
    }

    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        g.assign(n, {});
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int maxDeg = 0;
        for (int i = 0; i < n; i++) maxDeg = max(maxDeg, (int)g[i].size());

        if (maxDeg <= 2) {
            // single row (path)
            int start = -1;
            for (int i = 0; i < n; i++) if ((int)g[i].size() <= 1) { start = i; break; }
            if (start == -1) start = 0;
            vector<int> row;
            int prev = -1, cur = start;
            while (true) {
                row.push_back(cur);
                int nxt = -1;
                for (int x : g[cur]) if (x != prev) { nxt = x; break; }
                if (nxt == -1) break;
                prev = cur;
                cur = nxt;
            }
            return {row};
        }

        // find a corner (degree 2)
        int corner = -1;
        for (int i = 0; i < n; i++) if ((int)g[i].size() == 2) { corner = i; break; }

        int nb1 = g[corner][0], nb2 = g[corner][1];

        unordered_map<long long,int> coordToNode;
        vector<pair<int,int>> nodeCoord(n, {-1,-1});
        const long long M = n + 5;
        auto key = [&](int r, int c) { return (long long)r * M + c; };

        auto setCell = [&](int r, int c, int node) {
            coordToNode[key(r,c)] = node;
            nodeCoord[node] = {r, c};
        };

        setCell(0, 0, corner);
        setCell(0, 1, nb1);
        setCell(1, 0, nb2);

        queue<pair<int,int>> q;
        q.push({0, 1});
        q.push({1, 0});

        auto tryInteriorAsUp = [&](int x, int y) {
            // (x,y) is "up" ref for target (x+1,y); "left" ref = (x+1,y-1)
            if (y - 1 < 0) return;
            auto itLeft = coordToNode.find(key(x+1, y-1));
            if (itLeft == coordToNode.end()) return;
            if (coordToNode.count(key(x+1, y))) return;
            int exclude = -1;
            auto itDiag = coordToNode.find(key(x, y-1));
            if (itDiag != coordToNode.end()) exclude = itDiag->second;
            int node = commonNeighborExcluding(coordToNode[key(x,y)], itLeft->second, exclude);
            if (node != -1 && nodeCoord[node].first == -1) {
                setCell(x+1, y, node);
                q.push({x+1, y});
            }
        };
        auto tryInteriorAsLeft = [&](int x, int y) {
            // (x,y) is "left" ref for target (x,y+1); "up" ref = (x-1,y+1)
            if (x - 1 < 0) return;
            auto itUp = coordToNode.find(key(x-1, y+1));
            if (itUp == coordToNode.end()) return;
            if (coordToNode.count(key(x, y+1))) return;
            int exclude = -1;
            auto itDiag = coordToNode.find(key(x-1, y));
            if (itDiag != coordToNode.end()) exclude = itDiag->second;
            int node = commonNeighborExcluding(itUp->second, coordToNode[key(x,y)], exclude);
            if (node != -1 && nodeCoord[node].first == -1) {
                setCell(x, y+1, node);
                q.push({x, y+1});
            }
        };
        auto tryRow0Ext = [&](int y) {
            // (0,y) newly added; try (0,y+1): needs (1,y) present
            auto itDown = coordToNode.find(key(1, y));
            if (itDown == coordToNode.end()) return;
            if (coordToNode.count(key(0, y+1))) return;
            int excludePrev = -1;
            auto itPrev = coordToNode.find(key(0, y-1));
            if (itPrev != coordToNode.end()) excludePrev = itPrev->second;
            int node = neighborExcluding2(coordToNode[key(0,y)], excludePrev, itDown->second);
            if (node != -1 && nodeCoord[node].first == -1) {
                setCell(0, y+1, node);
                q.push({0, y+1});
            }
        };
        auto tryCol0Ext = [&](int x) {
            auto itRight = coordToNode.find(key(x, 1));
            if (itRight == coordToNode.end()) return;
            if (coordToNode.count(key(x+1, 0))) return;
            int excludePrev = -1;
            auto itPrev = coordToNode.find(key(x-1, 0));
            if (itPrev != coordToNode.end()) excludePrev = itPrev->second;
            int node = neighborExcluding2(coordToNode[key(x,0)], excludePrev, itRight->second);
            if (node != -1 && nodeCoord[node].first == -1) {
                setCell(x+1, 0, node);
                q.push({x+1, 0});
            }
        };

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            tryInteriorAsUp(x, y);
            tryInteriorAsLeft(x, y);
            if (x == 0 && y >= 1) tryRow0Ext(y);
            if (y == 0 && x >= 1) tryCol0Ext(x);
        }

        int rows = 0, cols = 0;
        for (int i = 0; i < n; i++) {
            rows = max(rows, nodeCoord[i].first + 1);
            cols = max(cols, nodeCoord[i].second + 1);
        }

        vector<vector<int>> result(rows, vector<int>(cols));
        for (int i = 0; i < n; i++) {
            result[nodeCoord[i].first][nodeCoord[i].second] = i;
        }
        return result;
    }
};
