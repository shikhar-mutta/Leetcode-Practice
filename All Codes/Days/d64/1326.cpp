// Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: for each position, track the farthest right-reach among
// taps whose watering interval starts at or before that position
// (maxReach[i] = max over taps covering i of their right endpoint).
// Then it's the classic jump-game/interval-covering greedy: repeatedly
// jump to the farthest reachable point using the best tap available in
// the current reachable window, counting jumps, until reaching n.
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> maxReach(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int lo = max(0, i - ranges[i]);
            int hi = min(n, i + ranges[i]);
            maxReach[lo] = max(maxReach[lo], hi);
        }

        int taps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i <= n; i++) {
            if (i > farthest) return -1;
            if (i > curEnd) {
                taps++;
                curEnd = farthest;
            }
            farthest = max(farthest, maxReach[i]);
        }
        return taps;
    }
};
