// Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        set<int> nodes;
        for (int i = 0; i < n; i++) nodes.insert(i);
        int pathLen = n - 1;

        vector<int> res;
        res.reserve(queries.size());
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            auto it = nodes.upper_bound(u);
            while (it != nodes.end() && *it < v) {
                it = nodes.erase(it);
                pathLen--;
            }
            res.push_back(pathLen);
        }
        return res;
    }
};
