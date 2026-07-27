// Link: https://leetcode.com/problems/find-maximum-area-of-a-triangle/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: return twice the max area, so area*2 = base*height. For a
// triangle with a vertical side (parallel to y-axis), group points by x:
// the base is (maxY-minY) at some x, and the height is the max
// horizontal distance from that x to any other point's x (global min or
// max x). Compute this for vertical sides, then swap x/y and repeat for
// horizontal sides; take the overall best.
class Solution {
    long long calc(vector<vector<int>>& coords) {
        int mn = INT_MAX, mx = 0;
        unordered_map<int,int> lo, hi;
        for (auto& p : coords) {
            int x = p[0], y = p[1];
            mn = min(mn, x);
            mx = max(mx, x);
            if (lo.count(x)) { lo[x] = min(lo[x], y); hi[x] = max(hi[x], y); }
            else { lo[x] = hi[x] = y; }
        }
        long long ans = 0;
        for (auto& [x, y] : lo) {
            long long base = hi[x] - y;
            long long height = max(mx - x, x - mn);
            ans = max(ans, base * height);
        }
        return ans;
    }
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long ans = calc(coords);
        for (auto& c : coords) swap(c[0], c[1]);
        ans = max(ans, calc(coords));
        return ans > 0 ? ans : -1;
    }
};
