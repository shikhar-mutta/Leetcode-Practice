// Link: https://leetcode.com/problems/rectangle-area-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: coordinate-compress all x-coordinates. For each consecutive
// pair of x-columns, find the total covered y-length by merging the
// y-intervals of all rectangles spanning that x-slice (sort + sweep),
// then add width * coveredYLength to the total area, all mod 1e9+7.
class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const long long MOD = 1e9 + 7;
        vector<int> xs;
        for (auto& r : rectangles) { xs.push_back(r[0]); xs.push_back(r[2]); }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        long long total = 0;
        for (int i = 0; i + 1 < (int)xs.size(); i++) {
            int xl = xs[i], xr = xs[i + 1];
            vector<pair<int,int>> intervals;
            for (auto& r : rectangles) {
                if (r[0] <= xl && r[2] >= xr) intervals.push_back({r[1], r[3]});
            }
            sort(intervals.begin(), intervals.end());
            long long covered = 0;
            int curL = INT_MIN, curR = INT_MIN;
            for (auto& [l, r] : intervals) {
                if (l > curR) {
                    covered += curR - curL > 0 ? curR - curL : 0;
                    curL = l; curR = r;
                } else {
                    curR = max(curR, r);
                }
            }
            covered += curR - curL > 0 ? curR - curL : 0;
            total = (total + (long long)(xr - xl) % MOD * (covered % MOD)) % MOD;
        }
        return (int)total;
    }
};
