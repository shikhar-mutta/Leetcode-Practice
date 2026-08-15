// Link: https://leetcode.com/problems/maximum-distance-in-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track running min and max from arrays seen so far; for each array compute distance to both running extremes (using elements from a different array), then update running extremes with current array's own min/max.
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int curMin = arrays[0].front(), curMax = arrays[0].back();
        int best = 0;
        for (int i = 1; i < (int)arrays.size(); i++) {
            int lo = arrays[i].front(), hi = arrays[i].back();
            best = max({best, abs(hi - curMin), abs(curMax - lo)});
            curMin = min(curMin, lo);
            curMax = max(curMax, hi);
        }
        return best;
    }
};
