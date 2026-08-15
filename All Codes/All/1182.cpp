// Link: https://leetcode.com/problems/shortest-distance-to-target-color/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < (int)colors.size(); i++) positions[colors[i]].push_back(i);

        vector<int> res;
        for (auto& q : queries) {
            int idx = q[0], color = q[1];
            if (!positions.count(color)) { res.push_back(-1); continue; }
            auto& pos = positions[color];
            auto it = lower_bound(pos.begin(), pos.end(), idx);
            int best = INT_MAX;
            if (it != pos.end()) best = min(best, *it - idx);
            if (it != pos.begin()) best = min(best, idx - *prev(it));
            res.push_back(best);
        }
        return res;
    }
};
