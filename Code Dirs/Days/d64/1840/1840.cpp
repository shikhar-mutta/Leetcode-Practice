// Link: https://leetcode.com/problems/maximum-building-height/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m log m)  SC: O(m)
// Approach: add (1,0) and (n,inf) as boundary restrictions, sort by id, then
// tighten each restriction's max height using its left neighbor (forward pass)
// and right neighbor (backward pass) via |dx| distance. Answer is the max
// achievable height at the midpoint between each consecutive pair.
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>> r = restrictions;
        r.push_back({1, 0});
        r.push_back({n, n - 1});
        sort(r.begin(), r.end());
        int m = r.size();
        for (int i = 1; i < m; i++)
            r[i][1] = min(r[i][1], r[i-1][1] + (r[i][0] - r[i-1][0]));
        for (int i = m - 2; i >= 0; i--)
            r[i][1] = min(r[i][1], r[i+1][1] + (r[i+1][0] - r[i][0]));
        int ans = 0;
        for (int i = 1; i < m; i++) {
            int dist = r[i][0] - r[i-1][0];
            int peak = (r[i-1][1] + r[i][1] + dist) / 2;
            ans = max(ans, peak);
        }
        return ans;
    }
};
