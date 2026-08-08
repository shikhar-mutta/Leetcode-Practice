// Link: https://leetcode.com/problems/maximum-building-height/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<pair<int,int>> r;
        for (auto& x : restrictions) r.push_back({x[0], x[1]});
        r.push_back({1, 0});
        r.push_back({n, n - 1});
        sort(r.begin(), r.end());

        int m = r.size();
        for (int i = 1; i < m; i++) {
            r[i].second = min(r[i].second, r[i-1].second + (r[i].first - r[i-1].first));
        }
        for (int i = m - 2; i >= 0; i--) {
            r[i].second = min(r[i].second, r[i+1].second + (r[i+1].first - r[i].first));
        }

        int best = 0;
        for (int i = 1; i < m; i++) {
            int dist = r[i].first - r[i-1].first;
            int peak = (r[i-1].second + r[i].second + dist) / 2;
            best = max(best, peak);
        }
        return best;
    }
};
