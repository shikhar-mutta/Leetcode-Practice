// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-x-and-y-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (x <= y) return y - x;
        queue<int> q;
        unordered_map<int,int> dist;
        q.push(x);
        dist[x] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == y) return dist[u];
            vector<int> next;
            if (u % 11 == 0) next.push_back(u / 11);
            if (u % 5 == 0) next.push_back(u / 5);
            next.push_back(u - 1);
            next.push_back(u + 1);
            for (int v : next) {
                if (v < 0 || v > 100000) continue;
                if (!dist.count(v)) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return -1;
    }
};
