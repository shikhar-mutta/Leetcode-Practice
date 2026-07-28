// Link: https://leetcode.com/problems/escape-a-large-maze/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(b^2)  b = blocked.size()  SC: O(b^2)
// Approach: with b blocked cells, the largest area they can fully
// enclose (as a triangle against a grid corner) is b*(b-1)/2. So a
// bounded BFS from source that visits more than that many cells without
// hitting a wall must be "free" (not enclosed) — no need to actually
// search the full 1e6x1e6 grid. Run this capped BFS from source toward
// target, then from target toward source; both must either reach the
// other directly or escape their local trap (visit past the limit) for
// the answer to be true.
class Solution {
    int LIMIT;
    bool bfsEscape(unordered_set<long long>& blockedSet, pair<int,int> start, pair<int,int> end) {
        auto key = [](int x, int y) { return (long long)x * 1000000 + y; };
        unordered_set<long long> visited;
        queue<pair<int,int>> q;
        q.push(start);
        visited.insert(key(start.first, start.second));
        int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == end.first && y == end.second) return true;
            if ((int)visited.size() > LIMIT) return true;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000) continue;
                long long k = key(nx, ny);
                if (visited.count(k) || blockedSet.count(k)) continue;
                visited.insert(k);
                q.push({nx, ny});
            }
        }
        return false;
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int b = blocked.size();
        LIMIT = b * (b - 1) / 2;
        unordered_set<long long> blockedSet;
        for (auto& p : blocked) blockedSet.insert((long long)p[0] * 1000000 + p[1]);

        pair<int,int> s = {source[0], source[1]};
        pair<int,int> t = {target[0], target[1]};

        if (!bfsEscape(blockedSet, s, t)) return false;
        if (!bfsEscape(blockedSet, t, s)) return false;
        return true;
    }
};
