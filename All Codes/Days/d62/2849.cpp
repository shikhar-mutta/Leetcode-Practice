// Link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach: since diagonal moves cover both an x and y step at once, the
// minimum moves needed is max(|dx|,|dy|) — move diagonally min(|dx|,|dy|)
// times, then straight for the remaining |diff1-mini|+|diff2-mini|. Any t
// >= that minimum works EXCEPT when start==end and t==1 (must move away and
// couldn't return in exactly 1 step, though 0 or >=2 are both fine).
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff1 = abs(sx - fx);
        int diff2 = abs(sy - fy);
        int mini = min(diff1, diff2);
        if (diff1 == 0 && diff2 == 0 && t == 1)
            return false;

        int ans = mini;
        ans += diff1 - mini;
        ans += diff2 - mini;
        return ans <= t;
    }
};
