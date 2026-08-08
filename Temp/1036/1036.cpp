// Link: https://leetcode.com/problems/escape-a-large-maze/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        set<pair<int,int>> blockedSet;
        for (auto& b : blocked) blockedSet.insert({b[0], b[1]});
        int limit = blocked.size();
        long long maxArea = (long long)limit * (limit - 1) / 2;

        auto bfs = [&](vector<int>& start, vector<int>& end) {
            set<pair<int,int>> visited;
            queue<pair<int,int>> q;
            q.push({start[0], start[1]});
            visited.insert({start[0], start[1]});
            int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                if (r == end[0] && c == end[1]) return true;
                if ((long long)visited.size() > maxArea) return true;
                for (int d = 0; d < 4; d++) {
                    long long nr = (long long)r + dr[d], nc = (long long)c + dc[d];
                    if (nr < 0 || nr >= 1000000 || nc < 0 || nc >= 1000000) continue;
                    pair<int,int> p = {(int)nr, (int)nc};
                    if (visited.count(p) || blockedSet.count(p)) continue;
                    visited.insert(p);
                    q.push(p);
                }
            }
            return false;
        };

        return bfs(source, target) && bfs(target, source);
    }
};
