// Link: https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: mark positions already illuminated by existing bulbs using
// a difference array. Then greedily scan left to right: at the first
// uncovered position, place a new radius-1 bulb as far right as
// possible (at i+1, covering i..i+2) and jump past its coverage.
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int v = lights[i];
            if (v == 0) continue;
            int lo = max(0, i - v), hi = min(n - 1, i + v);
            diff[lo]++;
            diff[hi + 1]--;
        }
        vector<bool> covered(n);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += diff[i];
            covered[i] = cur > 0;
        }

        int count = 0, i = 0;
        while (i < n) {
            if (covered[i]) { i++; continue; }
            count++;
            int j = min(n - 1, i + 1);
            i = j + 2;
        }
        return count;
    }
};
